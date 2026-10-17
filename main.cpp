#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string number, double amount) {
        accountNumber = number;
        balance = amount;
    }

    void showInfo() {
        std::cout << "Account number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << " UAH" << std::endl;
    }

    virtual double calculateIncome() {
        return 0;
    }

    virtual ~BankAccount() = default;
};

class DebitAccount : public BankAccount {
private:
    double monthlyFee;

public:
    DebitAccount(std::string number, double amount, double fee)
        : BankAccount(number, amount) {
        monthlyFee = fee;
    }

    double calculateIncome() override {
        return -monthlyFee;
    }
};

class CreditAccount : public BankAccount {
private:
    double monthlyInterestRate;

public:
    CreditAccount(std::string number, double debt, double rate)
        : BankAccount(number, debt) {
        monthlyInterestRate = rate;
    }

    double calculateIncome() override {

        return -balance * monthlyInterestRate / 100;
    }
};

class DepositAccount : public BankAccount {
private:
    double monthlyInterestRate;

public:
    DepositAccount(std::string number, double amount, double rate)
        : BankAccount(number, amount) {
        monthlyInterestRate = rate;
    }

    double calculateIncome() override {
        return balance * monthlyInterestRate / 100;
    }
};

int main() {
    DebitAccount debit("UA001", 10000, 50);
    CreditAccount credit("UA002", 5000, 2);
    DepositAccount deposit("UA003", 20000, 1);

    BankAccount* account;

    std::cout << "DEBIT ACCOUNT" << std::endl;
    std::cout << "Monthly fee: 50 UAH" << std::endl;
    account = &debit;
    account->showInfo();
    std::cout << "Monthly income: " << account->calculateIncome() << " UAH" << std::endl;

    std::cout << std::endl;

    std::cout << "CREDIT ACCOUNT" << std::endl;
    std::cout << "The balance represents debt. Monthly interest rate: 2%" << std::endl;
    account = &credit;
    account->showInfo();
    std::cout << "Monthly income: " << account->calculateIncome() << " UAH" << std::endl;

    std::cout << std::endl;

    std::cout << "DEPOSIT ACCOUNT" << std::endl;
    std::cout << "Monthly interest rate: 1%" << std::endl;
    account = &deposit;
    account->showInfo();
    std::cout << "Monthly income: " << account->calculateIncome() << " UAH" << std::endl;

    return 0;
}