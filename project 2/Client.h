#pragma once
#include "Person.h"

#include"Vector.h"
class Client : public Person
{
protected :
	double balance;
  
public:
	Client():Person() {
		
        balance = 0;
	}
    Client(int id, const string& name, const string& password, double balance) : Person(id, name, password) , balance(balance) {
        setBalance(balance);
    }
    Client(const Client& other)
        : Person(other), balance(other.balance) {
    }
    void setBalance(double balance) {
        if (Validation::isBalance(balance)) {
            this->balance = balance;
        }
        else {
            cout << "invalid Balance and Balance must be at least 1500"<< endl;
        }
    }
   
    double getBalance()   {
        return balance;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount for deposit!"<<endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && (balance - amount) >= 1500) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount for withdrawal or insufficient funds!" <<endl;
        }
    }
    void transferTo(double amount, Client& recipient) {
        if (amount > 0 && (balance - amount) >= 1500) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transfer successful. New balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount for transfer or insufficient funds!\n";
        }
    }
    void checkBalance() const {
        cout << "Balance: " << balance << endl;
    }
    void displayInfoClient() const {
        cout << "Client info: " << endl;
        Person::displayInfoPerson();
       cout << " Balance: " << balance << endl;
    }
};

