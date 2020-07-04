#include "Decryption.h"
#include <sstream>
#include <iostream>


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

    string cipherText = Encryption(ctr);
    cout << "Cipher Text: " << cipherText << endl;

    string plainText = Decryption(cipherText);
    cout << "Plain Text: " << plainText << endl;

    return 0;
}
