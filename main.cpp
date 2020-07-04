#include "Decryption.h"

int main()
{
    //string Key = "abcdefgh";
    KeyGen();
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    string str;
    cin >> str;

    string cipherText = Encryption(str);
    cout << "Cipher Text: " << cipherText << endl;

    string plainText = Decryption(cipherText);
    cout << "Plain Text: " << plainText << endl;

    return 0;
}
