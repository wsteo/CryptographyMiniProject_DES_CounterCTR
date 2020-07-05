<<<<<<< Updated upstream
#include "Decryption.h"

int main()
{
=======

#include "DecryptCounter.h"


int main()
{


>>>>>>> Stashed changes
    //string Key = "abcdefgh";
    KeyGen();
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);

    string str;
    cin >> str;
<<<<<<< Updated upstream
=======

    string CipherText=EncryptionCounter(str);
    cout<<"\nCipher Text\t\t: ";
    cout<<CipherText<<endl;

    string PlainText=DecryptionCounter(CipherText);
    cout<<"\nPlain Text\t\t: ";
    cout<<PlainText<<endl;

    /*int counterC=counter;

    string ciphertxt=AllEncryptedChars;
    int stringSizeC = ceil(ciphertxt.length() / 8.0) * 8 * 8;

    for (int i = 0; i < stringSizeC; i = i + 64){
        cout<<"\n\nCounter:"<< counter;

        stringstream ss;
        ss << counter;
        string ctr;
        ss >> ctr;

        ciphertext(ciphertxt);

        string output = Encryption(ctr);
        EncryptCounter(output);

        for(int i=0;i<size3;i++){
            cipher[i]=AllBitsCipher[i];
            //cout<<AllBits[i];
        }
        cout<<endl;

        for(int i=0;i<size2;i++){
            cctr[i]=AllBits2[i];
            //cout<<AllBits2[i];
        }
        cout<<endl;

        XOR(cipher,cctr);
        cout<<"\nDecrypted Plain Text\t\t: ";
        for(int i=0;i<64;i++){
            cout<<xor3[i];
            DecryptedBit[i+k]=xor3[i];

            //ssx[i]>>EncryptedBit[i+j];
        }
        cout<<endl;

        k=k+64;

        counter--;
    }
    cout<<"\nDecrypt Bit\t\t: ";
    for(int i=0;i<stringSizeC;i++){
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
    cout<<"\nDecrypted Text\t\t: ";
    cout<<AllDecryptedChars<<endl;*/

>>>>>>> Stashed changes

    string cipherText = Encryption(str);
    cout << "Cipher Text: " << cipherText << endl;

    string plainText = Decryption(cipherText);
    cout << "Plain Text: " << plainText << endl;

    return 0;
}
