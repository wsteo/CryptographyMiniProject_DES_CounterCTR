#include "Encryption.h"

void XOR_1_Decryption_Function(int round){
    for(int i=0; i<48; i++){
        xor1[i] = expansion[i]^rKeys[16-round][i];
    }
}

string Decryption(string CipherText){
    int size_ = ceil(CipherText.length() / 8.0) * 8 * 8;
    int AllBits [size_];
    for (int i = 0; i<size_; i++){
        AllBits[i]=0;
    }

    int k = 0;
    for (int i = 0; i < CipherText.length(); i++) {
        int n = (unsigned char)CipherText[i];
        for(int j = 0 ; j < 8; j++) {
            AllBits[k++] = n % 2;
            n = n / 2;
        }
    }

    /*
    for (int i = size_ - 1; i >= 0; i--){
        cout << AllBits[i];
    }*/

    int AllDecryptedBits[size_];
    int m = 0;
    for (int i = 0 ; i <size_/64;i++){
        for (int j = 0; j < 64; j++){
            block[j] = AllBits[i * 64 + j];
        }


        //Initial Permutation Function
        IP_Function();

        //Divide into 2 sub blocks, left and right
        for (int m = 0; m<32; m++){
            leftB[m] = IP[m];
        }

        for (int m = 0; m<32; m++){
            rightB[m] = IP[m + 32];
        }

        cout << "Left: \t";
        for (int m = 0; m<32; m++){
            cout << leftB[m];
        }
        cout << endl;
        cout << "Right: \t";
        for (int m = 0; m<32; m++){
            cout << rightB[m];
        }

        //Start for the ROUND
        for (int round = 1; round < 17; round++){
        cout<< "\nRound: " << round;

        //Expansion
            Expansion_Function();

        //XOR operation
            XOR_1_Decryption_Function(round);

        //Substitution
            Substitute();

        //Permutation
            Perm();

            XOR2_Permutation_Function();

            for(int i=0;i<32;i++){
                leftB[i]=rightB[i];
            }
            for(int i=0;i<32;i++){
                rightB[i]=temp_rightB[i];
            }
            cout<<"\nAfter Round: "<< round;
            PrintDebug();
        }
        //end of round funtion

        //swapping operation
        int w = 0;
        for (int i = 0; i< 32; i++){
            block[w++] = rightB[i];
        }
        for (int i = 0; i< 32; i++){
            block[w++] = leftB[i];
        }

    //Inverse Initial Permutation
        InverseIP();

        cout<<"\nInverse Initial Permutation\n";
        for (int m = 0; m< 64; m++){
            cout << block[m];
        }
        cout << endl;

        for (int m = 0; m< 64; m++){
            cout << finalBlock[m];
        }
        cout << endl;

        for (int i=0; i<64; i++){
            AllDecryptedBits[m++] = finalBlock[i];
        }
    }

    for(int i=0;i<size_;i++){
        cout << AllDecryptedBits[i];
    }
    cout << endl;

    string AllDecryptedChars;
    for (int i = 0; i < size_/8; i++){
        int val = 0;
        for (int j = 0;j <8; j++){
            val += AllDecryptedBits[i * 8 + j] * pow(2, j);
        }
        AllDecryptedChars.push_back(char(val));
    }
    return AllDecryptedChars;
}
