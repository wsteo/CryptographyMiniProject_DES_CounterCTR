#include "EncryptCounter.h"

void ciphertext(string CipherText){
    size3 = ceil(CipherText.length() / 8.0) * 8 * 8;
    AllBitsCipher [size3];
    for (int i = 0; i<size3; i++){
        AllBitsCipher[i]=0;
    }

    int k = 0;
    for (int i = 0; i < CipherText.length(); i++) {
        int n = (unsigned char) CipherText[i];
        for(int j = 0 ; j < 8; j++) {
            AllBitsCipher[k++] = n % 2;
            n = n / 2;
        }
    }
}

void DecryptCounter(string output){
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

void XORDecrypt(int tempBits1[],int tempBits2[]){
    for(int i=0;i<64;i++){
        xor4[i]=tempBits1[i]^tempBits2[i];
    }
}

string DecryptionCounter(string str,int counterC){
    int DecryptedBit[3000];
    int pl_ctr=0;
    int tempPlText[3000];
    int stringSize = ceil(str.length() / 8.0) * 8 * 8;
    int counterviewC=1;

    for (int i = 0; i < stringSize; i = i + 64){
        cout<<"\nCounter:"<< counterviewC <<endl;

        stringstream ss;
        ss << setw(4) << setfill('0') << counterC%9999;
        string ctr;
        ss >> ctr;

        string nonceAndCtr = nonce + ctr;

        cout<<"Nonce\t\t\t: "<<nonce<<endl;
        cout<<"Counter\t\t\t: "<<ctr<<endl;
        cout<<"Complete Counter\t: "<<nonceAndCtr<<endl;

        ciphertext(str);

        for(int i=0;i<size3;i++){
            cipher[i]=AllBitsCipher[i];
            //cout<<AllBits[i];
        }

        string output = Encryption(nonceAndCtr);
        EncryptCounter(output);

        for(int i=0;i<size2;i++){
            cctr[i]=AllBits2[i];
            //cout<<AllBits2[i];
        }

        cout <<"Cipher Text(FULL)\t: ";

        for(int i=0;i<size3;i++){
            cout<<cipher[i];
        }


        cout <<"\nCipher Text Block(64bit): ";
        for (int location = 0; location < 64; location++){
            cout << cipher[location+(pl_ctr*64)];
            tempPlText[location] = cipher[location+(pl_ctr*64)];
        }

        cout <<"\nEncrypted Counter\t: ";
        for(int i=0;i<size2;i++){
            cout<<cctr[i];
        }

        XORDecrypt(tempPlText,cctr);
        cout<<"\nResult of XOR\t\t: ";
        for(int i=0;i<64;i++){
            cout<<xor4[i];
            DecryptedBit[i+(pl_ctr*64)]=xor4[i];
        }

        pl_ctr++;
        counterC++;
        counterviewC++;
        cout << endl;
    }
    cout<<"\nDecrypt Bit\t\t: ";
    for(int i=0;i<stringSize;i++){
        cout<<DecryptedBit[i];
    }
    cout<<endl;

    string AllDecryptedChars;
    for (int i = 0; i < size_/8; i++){
        int val = 0;
        for (int j = 0;j <8; j++){
            val += DecryptedBit[i * 8 + j] * pow(2, j);
        }
        AllDecryptedChars.push_back(char(val));
    }

    return AllDecryptedChars;
}

