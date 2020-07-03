#include <iostream>
#include <cmath>
#include "KeyGenLectureExample.h"

using namespace std;

int block[64], IP[64], leftB[32], rightB[32], expansion[48], xor1[48],rKeys[16][48];

void XOR1_Expansion_Function(int round){
    for(int i=0; i<48; i++){
        xor1[i] = expansion[i]^rKeys[round-1][i];

    }
}

void Expansion_Function(){
    int k=0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 4; j ++){
            expansion [i * 6 + j + 1] = rightB[k++];
        }
    }
    expansion[0] = rightB[47];
    expansion[47] = rightB[0];

    for (int i = 6,j = 3; i < 43; i = i + 6, j = j + 4){
        expansion[i] = rightB[j];
    }

    for (int i = 5,j = 4; i < 42; i = i + 6, j = j + 4){
        expansion[i] = rightB[j];
    }
}

void IP_Function(){
    int counter=0;
    for (int i = 57; i < 64; i = i+2){
        for (int k = i; k> 0; k -= 8){
            IP[counter++] = block[k];
        }
    }

    for (int i = 56; i < 63; i = i+2){
        for (int k = i; k>= 0; k -= 8){
            IP[counter++] = block[k];
        }
    }
}

int main()
{
    string Key = "abcdefg";
    KeyGen(rKeys,Key);
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    string str;
    cin >> str;

    int size_ = ceil(str.length() / 8.0) * 8 * 8;
    int AllBits [size_];
    for (int i = 0; i<size_; i++){
        AllBits[i]=0;
    }

    int k = 0;
    for (int i = 0; i < str.length(); i++) {
        int n = str[i];
        for(int j = 0 ; j < 8; j++) {
            AllBits[k++] = n % 2;
            n = n / 2;
        }
    }

    for (int i = size_ - 1; i >= 0; i--){
        cout << AllBits[i];
    }

    int AllEncryptedBits[size_];
    for (int i = 0 ; i <size_/64;i++){
        for (int j = 0; j < 64; j++){
            block[j] = AllBits[i * 64 + j];
        }
    }

    IP_Function();
    cout << endl;
    for (int m = 0; m<32; m++){
        leftB[m] = IP[m];
    }

    for (int m = 0; m<32; m++){
        rightB[m] = IP[m + 32];
    }
    cout << "Left: ";
    for (int m = 0; m<32; m++){
        cout << leftB[m];
    }
    cout << endl;
    cout << "Right: ";
    for (int m = 0; m<32; m++){
        cout << rightB[m];
    }
    cout << endl;

    Expansion_Function();

    cout << "Expanded: ";
    for (int m = 0; m<48; m++){
        cout << expansion[m];
    }
    cout << endl;

    cout << "XORed: ";
    XOR1_Expansion_Function(1);
    for (int m = 0; m<48; m++){
        cout << xor1[m];
    }
    cout << endl;

    /*
    for (int i =0; i <size_; i++){
        cout << AllBits[i] << "\t" << AllEncryptedBits[i] << endl;
    }
    */
    return 0;
    //test comment
}
