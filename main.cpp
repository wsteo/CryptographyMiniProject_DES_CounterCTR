#include "DecryptCounter.h"

int main()
{
    string key = "abcdefgh";
    KeyGen(key);
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    cout<<"The maximum number you can type here is 9999"<<endl;
    cout<<"Enter Secret Counter (number only)\t\t: ";
    int ctr;
    cin>>ctr;

    cout<<"Enter Plain Text\t\t\t\t: ";
    string str;
    cin >> str;

    cout<<"\n\n------Encrypt------"<<endl;
    string CipherText=EncryptionCounter(str,ctr);
    cout<<"\nCipher Text\t\t: ";
    cout<<CipherText<<endl;

    cout<<"\n\n------Decrypt------"<<endl;
    string PlainText=DecryptionCounter(CipherText,ctr);
    cout<<"\nPlain Text\t\t: ";
    cout<<PlainText<<endl;

    return 0;
}
