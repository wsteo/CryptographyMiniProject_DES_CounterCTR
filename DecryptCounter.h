#include "EncryptCounter.h"
int counterC=1;

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

void XORDecrypt(int AllBitsCipher[],int AllBits2[]){
    for(int i=0;i<64;i++){
        xor4[i]=AllBitsCipher[i*counterC]^AllBits2[i];
    }
}


string DecryptionCounter(string str){
    int j=0;
    int DecryptedBit[1000];
    int pl=0;

    int stringSize = ceil(str.length() / 8.0) * 8 * 8;

    for (int i = 0; i < stringSize; i = i + 64){
        cout<<"\n\nCounter:"<< counterC;

        stringstream ss;
        ss << counterC;
        string ctr;
        ss >> ctr;

        ciphertext(str);


        for(int i=0;i<size3;i++){
            cipher[i]=AllBitsCipher[i];
            //cout<<AllBits[i];
        }
        cout<<endl;

        string output = Encryption(ctr);
        EncryptCounter(output);

        for(int i=0;i<size2;i++){
            cctr[i]=AllBits2[i];
            //cout<<AllBits2[i];
        }
        cout<<endl;

        cout <<"Cipher Text(FULL)\t: ";

        for(int i=0;i<size3;i++){
            cout<<cipher[i];
        }

        cout <<"\nCipher Text (64bit)\t: ";

        for(int i=0;i< 64 ;i++){
            cout<<cipher[i+pl];
        }
        cout<<endl;
        pl=pl+64;
        //cout<<pl<<endl;
        cout <<"\nEncrypted Counter\t: ";
        for(int i=0;i<size2;i++){
            cout<<cctr[i];
        }

        XORDecrypt(cipher,cctr);
        cout<<"\nXORTxtCtr\t\t: ";
        for(int i=0;i<64;i++){
            cout<<xor4[i];
            DecryptedBit[i+j]=xor4[i];

            //ssx[i]>>EncryptedBit[i+j];
        }
        cout<<endl;

        j=j+64;

        //XORintoComplete(xor3,encryptedText);
        counterC++;
    }
    cout<<"\nDecrypt Bit\t\t: ";
    for(int i=0;i<stringSize;i++){
        cout<<DecryptedBit[i];
    }
    cout<<endl;

    string AllDecryptedChars;
    for (int i = 0; i < size3/8; i++){
        int val = 0;
        for (int j = 0;j <8; j++){
            val += DecryptedBit[i * 8 + j] * pow(2, j);
        }
        AllDecryptedChars.push_back(char(val));
    }

    return AllDecryptedChars;
}
