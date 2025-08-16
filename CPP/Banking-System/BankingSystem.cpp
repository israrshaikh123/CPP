#include <iostream>
#include <string>
using namespace std;

class BankAccount
{

protected:
    int AccountNumber;
    string AccountHolder;
    double balance;

public:
    BankAccount(int AccNo, string name, double initial)
        : AccountNumber(AccNo), AccountHolder(name), balance(0)
    {
        deposit(initial);
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        // cout << "Deposites $" << amount << " successfully.\n";
    }

    virtual bool withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdraw $ " << amount << "successfully.\n";
            return true;
        }
        cout << "Insufficiant balance.\n";
        return false;
    }
    virtual void displayInfo()
    {
        cout << "Account Holder: " << AccountHolder
             << ", Account No: " << AccountNumber
             << ", Balance: $" << balance << endl;
    }

    double GetBalance() { return balance; }
};

class SavingAccount : public BankAccount
{

    double InterestRate;

public:
    SavingAccount(int AccNo, string name, double bal, double rate) : BankAccount(AccNo, name, bal), InterestRate(rate)
    {
        cout << "Saving Account Created Successfully.\n";
    }

    void CalculateInterest()
    {
        double interest = balance * InterestRate / 100;
        balance += interest;

        cout << "Interest $" << interest << " Added at rate " << InterestRate << "%.\n";
    }
};

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount(int AccNo, string name, double bal)
        : BankAccount(AccNo, name, bal)
    {
        cout << "\n\n\nCurrent Account Created Successfully.\n";
    }

    bool withdraw(double amount) override
    {
        double OverdraftLimit = balance * 20 / 100;
        double TotalLimit = balance + OverdraftLimit;

        if (amount <= TotalLimit)
        {
            if (amount > balance)
            {
                cout << "Overdraft Used! Allowed Upto 20% Of Your Balance.\n";
            }

            balance -= amount;
            cout << "Withdraw $ : " << amount << " Successfully.\n";
            return true;
        }

        else
        {
            cout << "Withdrawal Denied! Exceeds Overdraft Limit.\n";
            return false;
        }
    }
};

class FixedDepositeAccount : public BankAccount
{
    double InterestRate;
    int DurationYears;

public:
    FixedDepositeAccount(int AccNo, string name, double bal, double rate, int years)
        : BankAccount(AccNo, name, bal), InterestRate(rate), DurationYears(years)
    {
        cout << "\n\nFD Acccount Created Successfully For "
             << DurationYears
             << " years at " << InterestRate << " %.\n"
             << endl;
    }
    bool withdraw(double amount) override
    {
        cout << "Withdraw is not allowed in FD Account before maturity!.\n";
        return false;
    }

    void displayInfo()
    {
        cout << "FD Details -> Principal: $" << balance
             << ", Rate: " << InterestRate << "%, Duration: "
             << DurationYears << " years.\n";
    }
};

int main()
{
    int choice;
    BankAccount *account = nullptr;

    cout << "WELCOME TO BANK.\n";
    cout << "1. Open Saving Account.\n";
    cout << "2. Open Current Account.\n";
    cout << "3. Open Fixed Deposit Account.\n";
    cout << "Enter Your Choice : ";
    cin >> choice;

    int AccNo;
    string name;
    double bal;

    cout << "Enter Your Account Number : ";
    cin >> AccNo;

    cout << "Enter Your Name : ";
    cin >> name;

    cout << "Enter Your Initial Balance : ";
    cin >> bal;

    if (choice == 1)
    {
        double rate;
        cout << "Enter The Rate Of Interest (%): ";
        cin >> rate;

        account = new SavingAccount(AccNo, name, bal, rate);
    }
    else if (choice == 2)
    {
        account = new CheckingAccount(AccNo, name, bal);
    }
    else if (choice == 3)
    {
        double rate;
        int years;

        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        cout << "Enter Duration (Years): ";
        cin >> years;

        account = new FixedDepositeAccount(AccNo, name, bal, rate, years);
    }
    else
    {
        cout << "Invalid Choice!\n";
    }

    int option;

    do
    {
        cout << "Account Menu\n";
        cout << "1. Deposit Money.\n";
        cout << "2. Withdraw Money.\n";
        cout << "3. Check Money.\n";
        cout << "4. Account Info.\n";
        cout << "0. Enter For Exit.\n";
        cout << "Enter Your Option : \n";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            double amount;
            cout << "Enter Amount to Deposit : ";
            cin >> amount;
            account->deposit(amount);
            break;
        }
        case 2:
        {
            double amount;
            cout << "Enter amount to withdraw : ";
            cin >> amount;
            account->withdraw(amount);
            break;
        }

        case 3:
        {
            cout << "Current Balance: $" << account->GetBalance() << endl;

            break;
        }
        case 4:
        {
            account->displayInfo();

            break;
        }

        case 0:
        {
            cout << "Thank you for banking with us!\n";

            break;
        }
        default:
            cout << "Invalid Choice";
            break;
        }
    } while (option != 0);

    return 0;
}