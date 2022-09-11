# include <iostream>
#include <iomanip>
using namespace std;

void showMenu()
{
    cout << "##########MENU##########\n";
    cout << "1. Check balance\n"; 
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";
    cout << "########################\n";
}

void make_deposit(double &balance, double money)
{
    balance += money;
}

void make_withdraw(double &balance, double money)
{
    balance -= money;
}

int main()
{
    int option;
    double balance = 500.00;

    do{
        showMenu(); 
        cout << "Option: ";
        cin >> option;

        switch (option)
        {
            case 1:
                cout << "Balance is: $" << setprecision(2) << fixed << balance << endl;
                break;
            case 2:
                double deposit_amount;
                cout << "Deposit amount: ";
                cin >> deposit_amount;
                make_deposit(balance, deposit_amount);
                cout << "Current balance: $" << setprecision(2) << fixed << balance << endl;
                break;
            case 3:
                double withdraw_amount;
                cout << "Withdraw amount: ";
                cin >> withdraw_amount;
                if (withdraw_amount <= balance)
                {
                    make_withdraw(balance, withdraw_amount);
                    cout << "Current balance: $" << setprecision(2) << fixed << balance << endl;
                }
                else
                {
                    cout << "Not enough money!\n";
                }
                break;
        }
        cout << "\n\n\n";
    } while (option != 4);

    return 0;
}