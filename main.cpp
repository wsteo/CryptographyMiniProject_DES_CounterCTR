#include "Decryption.h"
#include <sstream>
#include <iostream>

int size_,AllBits[64],size2,AllBits2[64],cctr[64],plain[64];
int xor3[64];
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

void XOR(int AllBits[],int AllBits2[]){
    for(int i=0;i<64;i++){
        xor3[i]=AllBits[i*counter]^AllBits2[i];
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

int main()
{
    //string Key = "abcdefgh";
    KeyGen();
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    string str;
    cin >> str;
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

        cout <<"Plain Text(FULL)\t: ";

        for(int i=0;i<size_;i++){
            cout<<plain[i];
        }

        cout <<"\nPlain Text (64bit)\t: ";

        for(int i=0;i< 64 ;i++){
            cout<<plain[i*counter];
        }
        cout <<"\nEncrypted Counter\t: ";
        for(int i=0;i<size2;i++){
            cout<<cctr[i];
        }

        XOR(plain,cctr);
        cout<<"\nCipher Text\t\t: ";
        for(int i=0;i<64;i++){
            cout<<xor3[i];
        }

        //XORintoComplete(xor3,encryptedText);
        counter++;
    }


    //cout << "Cipher Text: " << cipherText << endl;
    //string plainText = Decryption(cipherText);
    //cout << "Plain Text: " << plainText << endl;

    return 0;
}
