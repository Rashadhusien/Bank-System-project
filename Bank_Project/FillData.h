#pragma once
#include "Validation.h"
class FillData
{
public: 
	static string enterName() {
		string name;
		cout << "\nEnter Your Name : ";
		//cin >> name;
		cin.ignore();
		getline(cin, name);
		while (!Validation::isNameValid(name)) {
			cin.ignore();
			cout << "\nName Is Not Valid!\n";
			cout << "\nPlease, Enter A Valid Name: ";
			//cin >> name;
			getline(cin, name);

		}
		return name;

	}

	static string enterPassword() {
		string password;
		cout << "\nEnter Your Password: ";
		cin >> password;
		while (!Validation::isPasswordValid(password)) {
			cout << "\nPassword Is Not Valid!\n";
			cout << "\nPlease, Enter A Valid Password: ";
			cin >> password;

		}

		return password;
	}

	static double enterBalance() {
		double balance;
		cout << "\nEnter Client's Balance: ";
		cin >> balance;
		while (!Validation::isBalanceValid(balance)) {
			cout << "\nBalance Is Not Available!\n";
			cout << "\nPlease, Enter A Valid Balance: ";
			cin >> balance;

		}

		return balance;
	}

	static double enterSalary() {
		double salary;
		cout << "\nEnter Employee's Salary: ";
		cin >> salary;
		while (!Validation::isSalaryValid(salary)) {
			cout << "\nSalary Is Not Available!\n";
			cout << "\nPlease, Enter A Valid Salary: ";
			cin >> salary;
		}
		return salary;
	}
};

