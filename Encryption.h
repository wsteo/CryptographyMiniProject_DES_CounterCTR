#include <iostream>
#include <cmath>
#include "KeyGenLectureExample.h"

using namespace std;

int block[64], IP[64], leftB[32], rightB[32], expansion[48], xor1[48];
int sub[32],perm[32],temp_rightB[32],finalBlock[64];;

void PrintDebug(){
    cout << "\n---PRINT DEBUG---" <<endl;
    cout << endl;
    cout << "Expanded: ";
    for (int m = 0; m<48; m++){
        cout << expansion[m];
    }
    cout << endl;

    cout << "XORed\t: ";
    for (int m = 0; m<48; m++){
        cout << xor1[m];
    }
    cout << endl;

    cout << "Substitution: \t";
    for (int m = 0; m<32; m++){
        cout << sub[m];
    }
    cout << endl;

    cout << "Permutation: \t";
    for (int m = 0; m<32; m++){
        cout << perm[m];
    }
    cout << endl;

    cout << "XOR after Permutation: ";
    for (int m = 0; m<32; m++){
        cout << temp_rightB[m];
    }

    //left block same with right block before function
    cout << "\nLeft Block: ";
    for (int m = 0; m<32; m++){
        cout << leftB[m];
    }
    cout << endl;

    //xor after permutation
    cout << "Right Block: ";
    for (int m = 0; m<32; m++){
        cout << rightB[m];
    }
    cout << endl;
    cout <<"\n---End---"<< endl;
}

void XOR_1_Encryption_Function(int round){
    for(int i=0; i<48; i++){
        xor1[i] = expansion[i]^rKeys[round-1][i];
    }
}

void XOR2_Permutation_Function(){
    for(int i=0;i<32;i++){
        temp_rightB[i]=perm[i]^leftB[i];
    }
}

void Substitute(){

    int s1[4][16]=
    {
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    };

    int s2[4][16]=
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    };

    int s3[4][16]=
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    };

    int s4[4][16]=
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    };

    int s5[4][16]=
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    };

    int s6[4][16]=
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    };

    int s7[4][16]=
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    };

    int s8[4][16]=
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    };

    int a[8][6];
    int k=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<6;j++){
            a[i][j]=xor1[k++];
        }
    }
    k=0;
    for(int i=0;i<8;i++){
        int row=a[i][5]*2 + a[i][0]*1;
        int column=a[i][4]*8+a[i][3]*4+a[i][2]*2+a[i][1]*1;

        int counter=i+1;
        int value;
        switch(counter) {
            case 1:
                value = s1[row][column];
                break;
            case 2:
                value = s2[row][column];
                break;
            case 3:
                value = s3[row][column];
                break;
            case 4:
                value = s4[row][column];
                break;
            case 5:
                value = s5[row][column];
                break;
            case 6:
                value = s6[row][column];
                break;
            case 7:
                value = s7[row][column];
                break;
            case 8:
                value = s8[row][column];
                break;
                default:
                    cerr << "Wrong number" << endl;
                    break;
        }

        for(int j=0;j<4;j++){
            sub[k++]=value%2;
            value=value/2;
        }

    }
}

void Expansion_Function(){
    int k=0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 4; j ++){
            expansion [i * 6 + j + 1] = rightB[k++];
        }
    }
    expansion[0] = rightB[31];
    expansion[47] = rightB[0];

    for (int i = 6,j = 3; i < 43; i = i + 6, j = j + 4){
        expansion[i] = rightB[j];
    }

    for (int i = 5,j = 4; i < 42; i = i + 6, j = j + 4){
        expansion[i] = rightB[j];
    }
}

void InverseIP () {
    for(int i=0, j=39; i<64; i+=8, j--){
        finalBlock[i]= block[j];
    }
    for(int i=1, j=7; i<64; i+= 8, j--){
        finalBlock[i]= block[j];
    }
    for(int i=2, j=47; i<64; i+= 8, j--){
        finalBlock[i]= block[j];
    }
    for(int i=3, j=15; i<64; i+= 8, j--){
        finalBlock[i]= block[j];
    }
    for(int i=4, j=55; i<64; i+= 8, j--){
        finalBlock[i]= block[j];
    }
    for(int i=5, j=23; i<64; i+= 8, j--){
        finalBlock[i]= block[j];
    }
    for(int i=6, j=63; i<64; i+= 8, j--){
        finalBlock[i]= block[j];
    }
    for(int i=7, j=31; i<64; i+= 8, j--){
        finalBlock[i]= block[j];
    }

}

void Perm(){
    //Permutation
    perm[0]=sub[15];
    perm[1]=sub[6];
    perm[2]=sub[19];
    perm[3]=sub[20];
    perm[4]=sub[28];
    perm[5]=sub[11];
    perm[6]=sub[27];
    perm[7]=sub[16];
    perm[8]=sub[0];
    perm[9]=sub[14];
    perm[10]=sub[22];
    perm[11]=sub[25];
    perm[12]=sub[4];
    perm[13]=sub[17];
    perm[14]=sub[30];
    perm[15]=sub[9];
    perm[16]=sub[1];
    perm[17]=sub[7];
    perm[18]=sub[23];
    perm[19]=sub[13];
    perm[20]=sub[31];
    perm[21]=sub[26];
    perm[22]=sub[2];
    perm[23]=sub[8];
    perm[24]=sub[18];
    perm[25]=sub[12];
    perm[26]=sub[29];
    perm[27]=sub[5];
    perm[28]=sub[21];
    perm[29]=sub[10];
    perm[30]=sub[3];
    perm[31]=sub[24];
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

string Encryption(string PlainText){
    int size_ = ceil(PlainText.length() / 8.0) * 8 * 8;
    int AllBits [size_];
    for (int i = 0; i<size_; i++){
        AllBits[i]=0;
    }

    int k = 0;
    for (int i = 0; i < PlainText.length(); i++) {
        int n = PlainText[i];
        for(int j = 0 ; j < 8; j++) {
            AllBits[k++] = n % 2;
            n = n / 2;
        }
    }

    /*
    for (int i = size_ - 1; i >= 0; i--){
        cout << AllBits[i];
    }*/

    int AllEncryptedBits[size_];
    int m = 0;
    for (int i = 0 ; i <size_/64;i++){
        for (int j = 0; j < 64; j++){
            block[j] = AllBits[i * 64 + j];
        }


    //Initial Permutation Function
    IP_Function();

    //Divide into 2 sub blocks, left and right
    for (int m = 0; m<32; m++){
        leftB[m] = IP[m];
    }

    for (int m = 0; m<32; m++){
        rightB[m] = IP[m + 32];
    }
/*
    cout << "Left: \t";
    for (int m = 0; m<32; m++){
        cout << leftB[m];
    }
    cout << endl;
    cout << "Right: \t";
    for (int m = 0; m<32; m++){
        cout << rightB[m];
    }
*/
    //Start for the ROUND
    for (int round = 1; round < 17; round++){
        //cout<< "\nRound: " << round;

        //Expansion
            Expansion_Function();

        //XOR operation
            XOR_1_Encryption_Function(round);

        //Substitution
            Substitute();

        //Permutation
            Perm();

            XOR2_Permutation_Function();

            for(int i=0;i<32;i++){
                leftB[i]=rightB[i];
            }
            for(int i=0;i<32;i++){
                rightB[i]=temp_rightB[i];
            }
            //PrintDebug();
        }
        //end of round funtion

        //swapping operation
        int w = 0;
        for (int i = 0; i< 32; i++){
            block[w++] = rightB[i];
        }
        for (int i = 0; i< 32; i++){
            block[w++] = leftB[i];
        }

    //Inverse Initial Permutation
        InverseIP();
        /*
        cout<<"\nInverse Initial Permutation\n";
        for (int m = 0; m< 64; m++){
            cout << block[m];
        }
        cout << endl;

        for (int m = 0; m< 64; m++){
            cout << finalBlock[m];
        }
        cout << endl;
        */
        for (int i=0; i<64; i++){
            AllEncryptedBits[m++] = finalBlock[i];
        }
    }
/*
    for(int i=0;i<size_;i++){
        cout << AllEncryptedBits[i];
    }
    cout << endl;
*/
    string AllEncryptedChars;
    for (int i = 0; i < size_/8; i++){
        int val = 0;
        for (int j = 0;j <8; j++){
            val += AllEncryptedBits[i * 8 + j] * pow(2, j);
        }
        AllEncryptedChars.push_back(char(val));
    }
    return AllEncryptedChars;
}
