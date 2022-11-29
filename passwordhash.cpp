#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <functional>
#include <map>
#include "passwordhash.h"

using namespace std;

map <char, string> map_for_encryption;

void encryption(string& object);
char ReChange(char& symbol);

int passwordhash(string& login, string& password)
{
    ifstream input("information.k");
    ifstream info_for_encryption("jk911.save");
    ofstream output;

    if (!info_for_encryption.is_open())
    {
        cout << "Can't find correct file.\n Do you want to continue? Y/N\n";
        char symbol;
        do
        {
            symbol = getch();
            ReChange(symbol);
        } while (symbol != 'N' && symbol != 'Y');
        if (symbol == 'N') return 0;
    }

    char letter;
    string code;

    while (info_for_encryption >> letter >> code)
        map_for_encryption[letter] = code;

    encryption(login);
    encryption(password);

    hash <string> h;

    string login_h = to_string(h(login));
    string password_h = to_string(h(password));

    info_for_encryption.close();

    if (!input.is_open())
    {
        output.open("information.k");
        output << 0 << ' ' << 0 << '\n';
        output.close();
        input.open("information.k");
    }

    output.open("information.k", ios_base::app | ios_base::out);
    output << login_h << ' ' << password_h << '\n';
    return 0;
}

void encryption(string& object)
{
    string cipher = "";
    for (int i = 0; i < object.size(); i++)
    {
        if (map_for_encryption[object[i]] == "")
            cipher += to_string(CHAR_MAX - object[i]);
        else cipher += map_for_encryption[object[i]];
    }
    object = cipher;
}
char ReChange(char& symbol)
{
    if (symbol >= 'a' && symbol <= 'z') symbol += 'A' - 'a';
}
