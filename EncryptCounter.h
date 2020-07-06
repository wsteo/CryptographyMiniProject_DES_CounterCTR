#include "Decryption.h"
#include <sstream>
#include <iostream>
int size_,AllBits[64],size2,AllBits2[64],cctr[64],plain[64],size3,cipher[64],AllBitsCipher[64];
int xor3[64],xor4[64];
int counter = 1;

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
    AllBits [size2];
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

void XORintoComplete(int xorFunction[], int encryptedText[]){

    for (int i = 0; i<size_; i++){
        encryptedText[i]=0;
    }


    cout << "\nEncrypted Text: ";
    for(int i=0;i<size_;i++){
        cout<<encryptedText[i];
    }

}

string EncryptionCounter(string str){
    int pl_ctr=0;
    int EncryptedBit[2000];

    int stringSize = ceil(str.length() / 8.0) * 8 * 8;

    for (int i = 0; i < stringSize; i = i + 64){
        cout<<"\n\nCounter:"<< counter;

        stringstream ss;
        ss << counter;
        string ctr;
        ss >> ctr;

        plaintext(str);

        for(int i=0;i<size_;i++){
            plain[i]=AllBits[i];
        }

        string output = Encryption(ctr);
        EncryptCounter(output);

        for(int i=0;i<size2;i++){
            cctr[i]=AllBits2[i];
        }
        cout<<endl;

        cout <<"Plain Text(FULL)\t: ";

        for(int i=0;i<size_;i++){
            cout<<plain[i];
        }


        int tempPlText[64];
        cout <<"\nPlain Text (64bit)\t: ";
        for (int location = 0; location < 64; location++){
            cout << plain[location+(pl_ctr*64)];
            tempPlText[location] = plain[location+(pl_ctr*64)];
        }

        cout <<"\nEncrypted Counter\t: ";
        for(int i=0;i<size2;i++){
            cout<<cctr[i];
        }

        XOR(tempPlText,cctr);

        cout<<"\nXORTxtCtr\t\t: ";
        for(int i=0;i<64;i++){
            cout<<xor3[i];
            EncryptedBit[i+(64*pl_ctr)]=xor3[i];
        }

        cout<<endl;

        pl_ctr++;
        counter++;
    }

    cout<<"\nEncrypt Bit\t\t: ";
    for(int i=0;i<size_;i++){
        cout<<EncryptedBit[i];
    }
    cout<<endl;

    string AllEncryptedChars;
    for (int i = 0; i < size_/8; i++){
        int val = 0;
        for (int j = 0;j <8; j++){
            val += EncryptedBit[i * 8 + j] * pow(2, j);
        }
        AllEncryptedChars.push_back(char(val));
    }

    return AllEncryptedChars;
}
