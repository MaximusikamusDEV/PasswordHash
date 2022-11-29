#include <iostream>
#include <fstream>
#include "Enter.h"
#include "passwordhash.h"
#include "Find.h"

using namespace std;

int main()
{
    enter();

    ifstream fin("UserData.txt");

    string Login, Password;
    fin >> Login >> Password;
    fin.close();

    passwordhash(Login, Password);

    Find();

    return 0;
}
