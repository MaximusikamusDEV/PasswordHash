#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <functional>
#include <map>

using namespace std;

map <char, string> map_for_encryption;

void encryption(string& object);
char ReChange(char& symbol);

int passwordhash(string& s, const char& c)
{
    ifstream input("information.k");
    ifstream info_for_encryption("jk911.save");
    ofstream output;

    if (!info_for_encryption.is_open())
    {
        cout << "Can't find correct file.\n Do you want to continue? Y/N\n";
        char symbol;
        symbol = getch();
        ReChange(symbol);
        while (symbol != 'Y' && symbol != 'N')
        {
            symbol = getch();
            ReChange(symbol);
        }
        if (symbol == 'N') return 0;
    }

    char letter;
    string code;

    while (info_for_encryption >> letter >> code)
        map_for_encryption[letter] = code;

    ReChange(c);

    string login = "", password = "", word = "";
    hash <string> h;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            login = word;
            word = "";
            continue;
        }
        word += s[i];
    }
    password = word;

    encryption(login);
    encryption(password);

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

    string h_login, h_password;

    while (input >> h_login >> h_password)
    {
        if (h_login == login_h)
        {
            if (c == 'L')
            {
                if (h_password == password_h)
                    return 1;
            }
            else if (c == 'R')
            {
                cout << "Login is already registered in the system.\n";
                return 0;
            }
        }
    }
    input.close();
    output.open("information.k", ios_base::app | ios_base::out);
    if (c == 'R')
    {
        cout << "Register completed successfully.\n";
        output << login_h << ' ' << password_h << '\n';
        return 1;
    }
    if (c == 'L')
    {
        cout << "Login or password incorrect.\n";
        return 0;
    }
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
