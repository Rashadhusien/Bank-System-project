#pragma once
#include "Person.h"
#include "Client.h"
class Employee: public Person
{
	double salary;
public:
	Employee() {
		salary = 0;
	}
	Employee(int id, string name, string password, double salary) :Person(id, name, password) {
		setSalary(salary);
	}
	void setSalary(double salary) {
		if (Validation::isSalaryValid(salary)) { 
			this->salary = salary;


		}
		else {
			this->salary= 0;
			cout << "\nInvalid salary: Min Salary 500 \n";
		}
	}
	double getSalary() {
		return salary;
	}

	void addClient(Client& client) {
		clients.push_back(client);
	}
	Client* searchClient(int id) {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			if (cIt->getId() == id)
				return cIt._Ptr;
		}
		return  NULL;
	}
	void clientsList() {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			cIt->printData();
			cout << "\n===============================\n" << endl;
		}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
	void printData() {
		Person::displayInfo();
		cout << "\nsalary : " << salary << endl;
	}
};

static vector<Employee>employees; 
static vector<Employee>::iterator eIt; 
