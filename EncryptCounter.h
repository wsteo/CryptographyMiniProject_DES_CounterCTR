#include "Decryption.h"
#include <sstream>
#include <iostream>
#include <time.h>
#include <iomanip>

int size_,AllBits[1000],size2,AllBits2[64],cctr[64],plain[64],size3,cipher[64],AllBitsCipher[1000];
int xor3[64],xor4[64];
//int counter = 1;
string nonce;

string randomStringGen(int string_len){
    string randomStr;
    //char alpha_num[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
    string alpha_num = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL)); //initialize the random number generator with seed
    for (int i=0; i<string_len;i++){
        randomStr[i] = alpha_num[rand() % alpha_num.length()];
    }
    return randomStr;
}

string GetNonce(int stringLen){
    string nonceValue = randomStringGen(stringLen);
    string temp;
    for (int i=0; i<stringLen;i++){
        temp.push_back(nonceValue[i]);
    }
    cout<<endl;
    return temp;
}

void plaintext(string PlainText){
    size_ = ceil(PlainText.length() / 8.0) * 8 * 8;
    AllBits [size_];
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
}

void EncryptCounter(string output){
    size2 = ceil(output.length() / 8.0) * 8 * 8;
    AllBits2 [size2];
    for (int i = 0; i<size2; i++){
        AllBits2[i]=0;
    }

    int k = 0;
    for (int i = 0; i < output.length(); i++) {
        int n = (unsigned char)output[i];
        for(int j = 0 ; j < 8; j++) {
            AllBits2[k++] = n % 2;
            n = n / 2;
        }
    }
}

void XOR(int tempBits1[],int tempBits2[]){
    for(int i=0;i<64;i++){
        xor3[i]=tempBits1[i]^tempBits2[i];
    }
}

string EncryptionCounter(string str,int counter){
    int pl_ctr=0;
    int EncryptedBit[3000];
    int tempPlText[3000];
    int stringSize = ceil(str.length() / 8.0) * 8 * 8;
    int counterview = 1;
    nonce = GetNonce(4);

    for (int i = 0; i < stringSize; i = i + 64){
        cout<<"Counter:"<< counterview <<endl;

        stringstream ss;
        ss << setw(4) << setfill('0') <<counter%9999;
        string ctr;
        ss >> ctr;

        string nonceAndCtr = nonce + ctr;
        cout<<"Nonce\t\t\t: "<<nonce<<endl;
        cout<<"Counter\t\t\t: "<<ctr<<endl;
        cout<<"Complete Counter\t: "<<nonceAndCtr<<endl;
        plaintext(str);

        for(int i=0;i<stringSize;i++){
            plain[i]=AllBits[i];
        }

        string output = Encryption(nonceAndCtr);
        EncryptCounter(output);

        for(int i=0;i<size2;i++){
            cctr[i]=AllBits2[i];
            //cout << cctr[i];
        }

        cout <<"Plain Text(FULL)\t: ";

        for(int i=0;i<size_;i++){
            cout<<plain[i];
        }

        cout <<"\nPlain Text Block(64bit)\t: ";
        for (int location = 0; location < 64; location++){
            cout << plain[location+(pl_ctr*64)];
            tempPlText[location] = plain[location+(pl_ctr*64)];
        }

        cout <<"\nEncrypted Counter\t: ";
        for(int i=0;i<size2;i++){
            cout<<cctr[i];
        }

        XOR(tempPlText,cctr);

        cout<<"\nResults of XOR\t\t: ";
        for(int i=0;i<64;i++){
            cout<<xor3[i];
            EncryptedBit[i+(64*pl_ctr)]=xor3[i];
        }

        pl_ctr++;
        counter++;
        counterview++;
        cout << endl;
    }

    cout<<"\nEncrypt Bit\t\t: ";
    for(int i=0;i<size_;i++){
        cout<<EncryptedBit[i];
    }
    cout<<endl;

    string AllEncryptedChars;
    for (int i = 0; i < stringSize/8; i++){
        int val = 0;
        for (int j = 0;j <8; j++){
            val += EncryptedBit[i * 8 + j] * pow(2, j);
        }
        AllEncryptedChars.push_back(char(val));
    }

    return AllEncryptedChars;
}
