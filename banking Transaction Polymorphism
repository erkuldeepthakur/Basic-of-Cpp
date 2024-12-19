#include <iostream>
using namespace std;

class Account {
public:
    virtual void calculateInterest() = 0; // Pure virtual function
};

class SavingsAccount : public Account {
private:
    double balance;
    double rate;
    int time;

public:
    SavingsAccount(double b, double r, int t) : balance(b), rate(r), time(t) {}

    void calculateInterest() override {
        double interest = balance * (rate / 100) * time;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
private:
    double balance;
    double maintenanceFee;

public:
    CurrentAccount(double b, double fee) : balance(b), maintenanceFee(fee) {}

    void calculateInterest() override {
        balance -= maintenanceFee;
        cout << "Balance after fee deduction: " << balance << endl;
    }
};

int main() {
    int accountType;
    cout << "Account Type (1 for Savings, 2 for Current): ";
    cin >> accountType;

    if (accountType == 1) {
        double balance, rate;
        int time;
        cout << "Balance: ";
        cin >> balance;
        cout << "Interest Rate: ";
        cin >> rate;
        cout << "Time: ";
        cin >> time;

        SavingsAccount savings(balance, rate, time);
        savings.calculateInterest();
    } else if (accountType == 2) {
        double balance, fee;
        cout << "Balance: ";
        cin >> balance;
        cout << "Maintenance Fee: ";
        cin >> fee;

        CurrentAccount current(balance, fee);
        current.calculateInterest();
    } else {
        cout << "Invalid account type." << endl;
    }

    return 0;
}
