#include "Enter.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>

using namespace std;


void enter()
{
    const int StartSize = 1000;

    char Pass[StartSize];
    char Login[StartSize];
    char Comment[StartSize];

    do
    {
        cout << "Enter your login: ";
        cin >> Login;

        cout << "Enter your password: ";
        cin >> Pass;

        int size;

        size = strlen(Pass);

        if (size < 8)
        {
            cout << "Your's password size is too low. Try again\n";
            continue;
        }

        bool fllett = 0, flnum = 0, flspec = 0;
        bool fl1, fl2;

        for (int i = 0; i < size; i++)
        {
            fl1 = 0;
            fl2 = 0;

            if (Pass[i] >= 'a' && Pass[i] <= 'z' || Pass[i] >= 'A' && Pass[i] <= 'Z')
            {
                fllett = 1;
                fl1 = 1;
            }

            if (Pass[i] >= '0' && Pass[i] <= '9')
            {
                flnum = 1;
                fl2 = 1;
            }

            if (fl1 == 0 && fl2 == 0)
                flspec = 1;

        }

        if (flspec == 0 || flnum == 0 || fllett == 0)
        {
            cout << "Your password is uncorrect. Please try again\n";
            continue;
        }


        size = strlen(Login);

        if (size < 8)
        {
            cout << "Your Login size is too low. Please try again\n";
            continue;
        }

        flspec = 0;
        flnum = 0;

        if (strchr(Login, '@') != nullptr)
            flspec = 1;

        if (strchr(Login, '.') != nullptr)
            flnum = 1;

        if (flnum == 0 || flspec == 0)
        {
            cout << "We can't find your email adress. Please try again\n";
            continue;
        }
        break;
    }
    while (true);

    cout << "Enter your message: ";
    cin.get();
    cin.getline(Comment, StartSize);

    ofstream fout;

    fout.open("UserData.txt");

    fout << "Login: " << Login << " Password: " << Pass << endl << "Text:" << endl << Comment;

    fout.close();

    fout.open("Data.txt");


    fout << Comment;

    fout.close();

}
