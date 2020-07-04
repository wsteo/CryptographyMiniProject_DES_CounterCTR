#include "Decryption.h"
#include <sstream>
#include <iostream>

int size_,AllBits[64],size2,AllBits2[64],cctr[64],plain[64];
int xor3[64];

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
        xor3[i]=AllBits[i]^AllBits2[i];
    }
}
int main()
{
    int counter = 1;

    stringstream ss;
    ss << counter;
    string ctr;
    ss >> ctr;

    //string Key = "abcdefgh";
    KeyGen();
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    string str;
    cin >> str;

    plaintext(str);

    for(int i=0;i<size_;i++){
        plain[i]=AllBits[i];
        //cout<<AllBits[i];
    }
    cout<<endl;

    string output = Encryption(ctr);
    EncryptCounter(output);
    cout << output <<endl;

    for(int i=0;i<size2;i++){
        cctr[i]=AllBits2[i];
        //cout<<AllBits2[i];
    }
    cout<<endl;

    cout <<"Plain Text: "<<endl;

    for(int i=0;i<size_;i++){
        cout<<plain[i];
    }

    cout <<"\nEncrypted Counter: "<<endl;

    for(int i=0;i<size_;i++){
        cout<<cctr[i];
    }

    XOR(plain,cctr);
    cout<<"\nCipher Text: " <<endl;
    for(int i=0;i<64;i++){
        cout<<xor3[i];
    }

    //cout << "Cipher Text: " << cipherText << endl;
    //string plainText = Decryption(cipherText);
    //cout << "Plain Text: " << plainText << endl;

    return 0;
}
