#include <iostream>
#include "KeyGen.h"

using namespace std;

/*
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}*/

int main()
{
    int rKeys [16][48];
    KeyGen(rKeys);
    cout << "All Sub Keys: " << endl;
    PrintAllSubKeys (rKeys);
    return 0;
}
