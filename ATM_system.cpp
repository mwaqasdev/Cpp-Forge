#include <iostream>
#include <windows.h>

#include <string>

using namespace std;

class User
{
private:
    string name;
    string password;

public:
    double balance = 0;

    User(string a, string b)
    {
        name = a;
        password = b;
    }

    bool checkPassword(string pass)
    {
        HANDLE console_color;

        // Color of the console
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);

        // P is color code according to your need.
        SetConsoleTextAttribute(console_color, 33 | 43);

        if (pass == password)
        {
            cout << "Credientials accepted!";
            return 1;
        }
        else
            cout << "Wrong password...";
        return 0;
    }

    bool checkName(string nam)
    {
        if (nam == name)
        {
            cout << "Name is OK!";
            return 1;
        }
        else
            cout << "Invalid username...";
        return 0;
    }
};

// start menu
int startMenu()
{
    // Set text color for welcome message
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    cout << "\n\n***** Main Menu ***** \n";
    cout << "=================" << endl;
    cout << "   Menu Options  " << endl;
    cout << "=================" << endl;
    cout << " 1. Balance \n";
    cout << " 2. Deposit \n";
    cout << " 3. Withdram \n";
    cout << " 4. Exit \n";
    cout << "=================" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    cout << " Selection >. ";

    int op;
    cin >> op;

    return op;
}

int main()
{

    User u1 = User("haadi", "1234");

    string n, p;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    cout << "\n ***** Welcome to ATM ***** \n";
    cout << "\n >_ Enter username: ";
    cin >> n;

    cout << " >_ Enter password: ";
    cin >> p;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    if (u1.checkName(n) && u1.checkPassword(p))
    {
    start:
        int i;
        i = startMenu();

        switch (i)
        {
        case 1:
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "Your current account balance is: " << u1.balance;
            break;
        }
        case 2:
        {
            double dep;
            cout << "\nEnter the amount to deposit: ";
            cin >> dep;

            u1.balance += dep;

            break;
        }
        case 3:
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 33 | 43);
            double wd;
            cout << "\nEnter the amount to withdraw: ";
            cin >> wd;

            if (wd > u1.balance)
                cout << "Not enough balance\n";
            else
                u1.balance -= wd;

            break;
        }
        case 4:
            break;
        }

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n\n ***** Would you like to continue ***** \n";
        cout << " 1. Yes \n";
        cout << " 2. No \n";
        cout << " Selection: ";

        int in;
        cin >> in;

        if (in == 1)
        {
            system("cls");
            goto start;
        }
    }

    system("Pause");
}