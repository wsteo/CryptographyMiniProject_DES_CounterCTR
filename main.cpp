#include "Encryption.h"

int main()
{
    string Key = "abcdefg";
    KeyGen(Key);
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    string str;
    cin >> str;

    string cipherText = Encryption(str);
    cout << "Cipher Text: " << cipherText << endl;
    return 0;
}
