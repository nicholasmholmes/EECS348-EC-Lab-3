# EECS348-EC-Lab-3
# Objective:
Get familiar with an IDE, C++ programming. You will also learn how to push your projects from the Git repository to GitHub. The C++ programming experience will include inheritance and operator overloading

# Problem Description

Design a simple banking system that utilizes inheritance and operator overloading to handle transactions between different types of bank accounts.

# Classes
Account:

Base class for all types of bank accounts.
Properties: accountNumber, accountHolder, balance.
Methods:
displayDetails(): Display account details.
deposit(amount): Deposit money into the account.
withdraw(amount): Withdraw money from the account (ensure sufficient balance).
SavingsAccount:

Derived class from the Account class.
Additional properties: interestRate.  
Override the withdraw method to enforce a minimum balance.
CurrentAccount:

Derived class from the Account class.
Additional properties: overdraftlimit. 
Override the withdraw method to allow overdrafts up to the specified limit.
Operator Overloading
Overload the + operator to allow transferring money between accounts.
Overload the << operator to display account details.
Problem Requirements:
Create instances of SavingsAccount and CurrentAccount.  
Demonstrate deposit, withdrawal, and balance inquiry operations for both account types.
Transfer money from one account to another using operator overloading.
Ensure proper validation for withdrawal operations based on account type.
Display the details of all accounts after each transaction using the << operator.
The main() function should be similar to the following:

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);
    
    savings.displayDetails();
    current.displayDetails();

    // Transfer 300 from savings to current
    current = current + savings;

    savings.displayDetails();
    current.displayDetails();

    return 0;
}

The expected output should be:

Account Details for Savings Account (ID: S123):
   Holder: John Doe
   Balance: $1000.00
   Interest Rate: 2.00%

Account Details for Current Account (ID: C456):
   Holder: Jane Doe
   Balance: $2000.00
   Overdraft Limit: $500.00

Account Details after deposit and withdrawal:
Account Details for Savings Account (ID: S123):
   Holder: John Doe
   Balance: $1500.00
   Interest Rate: 2.00%

Account Details for Current Account (ID: C456):
   Holder: Jane Doe
   Balance: $1000.00
   Overdraft Limit: $500.00

Account Details after transfer:
Account Details for Savings Account (ID: S123):
   Holder: John Doe
   Balance: $1200.00
   Interest Rate: 2.00%

Account Details for Current Account (ID: C456):
   Holder: Jane Doe
   Balance: $1300.00
   Overdraft Limit: $500.00
