#include <iostream>
#include <iomanip>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double bal)
        : accountNumber(number), accountHolder(holder), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient balance.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    void decreaseBalance(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds.\n";
        }
    }

    void increaseBalance(double amount) {
        balance += amount;
    }

    virtual void printDetails(std::ostream& os) const {
        os << "Account Details (ID: " << accountNumber << "):\n"
           << "   Holder: " << accountHolder << "\n"
           << "   Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Account& acc);
};

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    acc.printDetails(os);
    return os;
}

class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double bal, double rate)
        : Account(number, holder, bal), interestRate(rate) {}

    void withdraw(double amount) override {
        if (balance - amount < 500) {  // Assuming 500 as minimum balance
            std::cout << "Cannot withdraw. Minimum balance requirement not met.\n";
        } else {
            Account::withdraw(amount);
        }
    }

    void printDetails(std::ostream& os) const override {
        Account::printDetails(os);
        os << "   Interest Rate: " << std::fixed << std::setprecision(2) << interestRate * 100 << "%\n";
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double bal, double limit)
        : Account(number, holder, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
        } else {
            std::cout << "Overdraft limit exceeded.\n";
        }
    }

    void printDetails(std::ostream& os) const override {
        Account::printDetails(os);
        os << "   Overdraft Limit: $" << std::fixed << std::setprecision(2) << overdraftLimit << "\n";
    }
};

// Updated operator overloading for transferring money
CurrentAccount& operator+(CurrentAccount& lhs, SavingsAccount& rhs) {
    double transferAmount = 300; // Assume a fixed transfer amount
    if (rhs.getBalance() >= transferAmount) {
        rhs.decreaseBalance(transferAmount);
        lhs.increaseBalance(transferAmount);
    } else {
        std::cout << "Insufficient balance in savings account for transfer.\n";
    }
    return lhs;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    std::cout << savings << current;

    savings.deposit(500);
    current.withdraw(1000);

    std::cout << "\nAccount Details after deposit and withdrawal:\n";
    std::cout << savings << current;

    // Transfer 300 from savings to current
    current = current + savings;

    std::cout << "\nAccount Details after transfer:\n";
    std::cout << savings << current;

    return 0;
}
