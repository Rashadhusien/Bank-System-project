#pragma once
#include "Person.h"
#include "Validation.h"

class Client : public Person
{
	double balance;

public:
	Client() : balance(0) {}
	Client(int id, string name, string password, double balance) : Person(id, name, password) {
		setBalance(balance);
	}

	void setBalance(double balance) {
		if (Validation::isBalanceValid(balance)) {
			this->balance = balance;
			cout << "\nSuccessful operation!\n" << endl;
		}
		else {
			this->balance = 0;
			cout << "\nFailed: Invalid Balance\n";
		}
	}

	double getBalance() const {
		return balance;
	}

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "\nSuccessful operation!\n" << endl;
			cout << "\nNew Balance = " << balance << endl;
		}
		else {
			cout << "\nTransaction failed: Invalid deposit amount.\n" << endl;
		}
	}

	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			cout << "\nSuccessful operation!\n" << endl;
			cout << "\nNew Balance = " << balance << endl;
		}
		else {
			cout << "\nTransaction failed: Insufficient balance.\n" << endl;
		}
	}

	void transferTo(Client& another, double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			another.balance += amount;
			cout << "\nSuccessful operation!\n" << endl;
			cout << "\nNew Balance = " << balance << endl;
		}
		else {
			cout << "\nTransaction failed: Insufficient balance.\n" << endl;
		}
	}

	void checkBalance()  {
		cout << "\nCurrent balance: " << balance << endl;
	}

	void printData()  {
		Person::displayInfo();
		cout << "\nBalance: " << balance << endl;
	}
};

static vector<Client>clients; 
static vector<Client>::iterator cIt; 

