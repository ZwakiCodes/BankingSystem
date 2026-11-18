#include <iostream>
using namespace std;

double balance = 500;
double depositAmount;
double withdrawamount;
double amount;
int account;

int option;

void checkbalance()
{
    cout << "Balance is R" << balance << endl;
}

void deposit(double deposits[], int &depCount)
{
    cout << "How much do wanna deposit R" << endl;
    cin >> depositAmount;
    balance = balance + depositAmount;
    cout << "Your new balance is R" << balance << endl;

    deposits[depCount] = depositAmount;
    depCount++;
}

void withdraw(double withdrawals[], int &withCount)
{
    cout << "How much do want to withdraw" << endl;
    cin >> withdrawamount;

    if (balance < withdrawamount)
    {
        cout << "Enter smaller amount " << endl;
    }
    else
    {
        balance = balance - withdrawamount;
        cout << "Withdraw was successful" << endl;
        cout << "Your new balance amount is R" << balance << endl;

        withdrawals[withCount] = withdrawamount;
        withCount++;
    }
}

void sendcash(double transfers[], int &sendCount)
{
    cout << "how much do want to send" << endl;
    cin >> amount;

    cout << "Enter account number" << endl;
    cin >> account;

    if (balance < amount)
    {
        cout << "enter smaller amount" << endl;
    }
    else
    {
        balance = balance - amount;
        cout << "Successful transfer" << endl;
        cout << "Your new balance is R" << balance << endl;
        cout << "You have sent R " << amount << " to the following account number " << account << endl;

        transfers[sendCount] = amount;
        sendCount++;
    }
}

void menu(double deposits[], int &depCount, double withdrawals[], int &withCount, double transfers[], int &sendCount)
{
    cout<< "========HELLO, WELCOME TO J.M BANKING SYSTEM======="<<endl;
    cout << "enter 1 to check balance " << endl;
    cout << "enter 2 to deposit " << endl;
    cout << "enter 3 to withdraw" << endl;
    cout << "enter 4 to send cash" << endl;
    cout << "enter 5 to view history" << endl;
    cin >> option;

    switch (option)
    {
        case 1:
            checkbalance();
            break;
        case 2:
            deposit(deposits, depCount);
            break;
        case 3:
            withdraw(withdrawals, withCount);
            break;
        case 4:
            sendcash(transfers, sendCount);
            break;
        case 5:
            cout << "Deposits:" << endl;
            for (int i = 0; i < depCount; i++)
            {
                cout << "R" << deposits[i] << endl;
            }
            cout << "Withdrawals:" << endl;
            for (int i = 0; i < withCount; i++)
            {
                cout << "R" << withdrawals[i] << endl;
            }
            cout << "Cash Sent:" << endl;
            for (int i = 0; i < sendCount; i++)
            {
                cout << "R" << transfers[i] << endl;
            }
            break;
    }
}

int main()
{
    // Arrays declared in int main
    double deposits[50];
    double withdrawals[50];
    double transfers[50];

    int depCount = 0;
    int withCount = 0;
    int sendCount = 0;

    char choice;

    // Loop that asks the customer if they want to continue or exit
    do
    {
        menu(deposits, depCount, withdrawals, withCount, transfers, sendCount);

        cout << "Do you want to continue or exit? (y to continue / n to exit): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using our service. Goodbye!" << endl;

    return 0;
}


