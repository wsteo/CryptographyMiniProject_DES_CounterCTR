#include <iostream>
#include <cmath>
#include "KeyGen.h"

using namespace std;

int block[64], IP[64];

void IP_Function()
{
    int count_=0;
    for (int i = 57; i < 64; i = i+2)
    {
        for (int k = i; k> 0; k -= 8)
        {
            IP[count_++] = block[k];
        }
    }

    for (int i = 56; i < 63; i = i+2)
    {
        for (int k = i; k>= 0; k -= 8)
        {
            IP[count_++] = block[k];
        }
    }
}

int main()
{
    int rKeys [16][48];
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
        IP_Function();
        for (int j = 0; j < 64; j++){
            AllEncryptedBits[i * 64 + j] = IP[j];
        }
    }

    for (int i =0; i <size_; i++){
        cout << AllBits[i] << "\t" << AllEncryptedBits[i] << endl;
    }
    cout << endl;
    return 0;
}
