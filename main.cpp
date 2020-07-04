#include "Decryption.h"
#include <string>

int main()
{
    string Key = "abcdefgh";
    KeyGen(Key);
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    string str;
    cin >> str;
    cout << str.length();

    for (int i=0;i<10;i++){
        string cipherText = Encryption(str);
        cout << "Cipher Text: " << cipherText << endl;

        string plainText = Decryption(cipherText);
        cout << "Plain Text: " << plainText << endl;

    }


    return 0;
}
