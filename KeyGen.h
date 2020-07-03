#ifndef KEYGEN_H_INCLUDED
#define KEYGEN_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

void FindBitsInKey (string KeyC, int Key[64]) {
    // Iterate on KeyC
    int j = 0;
    for (int i = 0; i < 8; i++) {
        char ch = KeyC[i];
        int n = int (ch);

        int B[8] = {0};
        int k = 0;
        while (n > 0) {
            B[k] = n % 2;
            k++;
            n = n / 2;
        }
        for (int m = 7; m > -1; m--, j++) {
            Key[j] = B[m];
        }
    }
}

void PermChoice1 (int k[64], int kp1[56]) {
    int j = 0;
    for (int i = 56; i >= 0; i = i - 8) kp1[j++] = k[i];
    for (int i = 57; i >= 0; i = i - 8) kp1[j++] = k[i];
    for (int i = 58; i >= 0; i = i - 8) kp1[j++] = k[i];
    for (int i = 59; i >= 35; i = i - 8) kp1[j++] = k[i];

    for (int i = 62; i >= 0; i = i - 8) kp1[j++] = k[i];
    for (int i = 61; i >= 0; i = i - 8) kp1[j++] = k[i];
    for (int i = 60; i >= 0; i = i - 8) kp1[j++] = k[i];
    for (int i = 27; i >= 0; i = i - 8) kp1[j++] = k[i];
}

void PrintKey (int *k, int size_) {
    for (int i = 0; i < size_; i++) {
        cout << k[i];
    }
    cout << endl;
}

void FindCandD (int k[56], int c[28], int d[28]) {
    int i = 0;
    for (int j = 0; j < 28; j++) c[j] = k[i++];
    for (int j = 0; j < 28; j++) d[j] = k[i++];
}

void ShiftOperation (int s[28], int nos) {
    int i = 0;
    while (i < nos) {
        int t = s[0];
        for (int j = 0; j < 27; j++) s[j] = s[j+1];
        s[27] = t;
        i++;
    }
}

void MergerCandD (int KAS[56], int C[28], int D[28]) {
    int i = 0;
    for (int j = 0; j < 28; j++) KAS[i++] = C[j];
    for (int j = 0; j < 28; j++) KAS[i++] = D[j];
}

void PermChoice2 (int rKey[48], int KAS[56]) {
    rKey[0] = KAS[13];
    rKey[1] = KAS[16];
    rKey[2] = KAS[10];
    rKey[3] = KAS[23];
    rKey[4] = KAS[0];
    rKey[5] = KAS[4];
    rKey[6] = KAS[2];
    rKey[7] = KAS[27];

    rKey[8] = KAS[14];
    rKey[9] = KAS[5];
    rKey[10] = KAS[20];
    rKey[11] = KAS[9];
    rKey[12] = KAS[22];
    rKey[13] = KAS[18];
    rKey[14] = KAS[11];
    rKey[15] = KAS[3];

    rKey[16] = KAS[25];
    rKey[17] = KAS[7];
    rKey[18] = KAS[15];
    rKey[19] = KAS[6];
    rKey[20] = KAS[26];
    rKey[21] = KAS[19];
    rKey[22] = KAS[12];
    rKey[23] = KAS[1];

    rKey[24] = KAS[40];
    rKey[25] = KAS[51];
    rKey[26] = KAS[30];
    rKey[27] = KAS[36];
    rKey[28] = KAS[46];
    rKey[29] = KAS[54];
    rKey[30] = KAS[29];
    rKey[31] = KAS[39];

    rKey[32] = KAS[50];
    rKey[33] = KAS[44];
    rKey[34] = KAS[32];
    rKey[35] = KAS[47];
    rKey[36] = KAS[43];
    rKey[37] = KAS[48];
    rKey[38] = KAS[38];
    rKey[39] = KAS[55];

    rKey[40] = KAS[33];
    rKey[41] = KAS[52];
    rKey[42] = KAS[45];
    rKey[43] = KAS[41];
    rKey[44] = KAS[49];
    rKey[45] = KAS[35];
    rKey[46] = KAS[28];
    rKey[47] = KAS[31];

}

void PrintAllSubKeys (int rks[16][48]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 48; j++) {
            cout << rks[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void KeyGen (int rKeys[16][48]) {
    int roundNo = 16;

    string Key = "abcdefgh";
    int KeyBits [64] = {0};
    FindBitsInKey(Key, KeyBits);
    cout << "64-bit Key: ";
    PrintKey(KeyBits, 64);
    int KeyAPC1 [56] = {0};
    PermChoice1(KeyBits, KeyAPC1);
    cout << "56-bit Key: ";
    PrintKey(KeyAPC1, 56);

    int C[28] = {0};
    int D[28] = {0};
    FindCandD(KeyAPC1, C, D);
    cout << "C: ";
    PrintKey(C, 28);
    cout << "D: ";
    PrintKey(D, 28);

    for (int round = 0; round < 16; round++) {
        int nos;
        if (round == 1 || round == 2 || round == 9 || round == 16) nos = 1;
        else nos = 2;

        ShiftOperation(C, nos);
        ShiftOperation(D, nos);

        int KAS [56] = {0};
        MergerCandD(KAS, C, D);

        int rKey[48] = {0};
        PermChoice2(rKey, KAS);

        for (int j = 0; j < 48; j++) {
            rKeys[round][j] = rKey[j];
        }
    }
}

int main()
{
    int rKeys [16][48];
    KeyGen(rKeys);
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);
    return 0;
}

#endif // KEYGEN_H_INCLUDED
