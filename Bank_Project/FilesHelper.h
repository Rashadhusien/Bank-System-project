#pragma once
#include <fstream>
#include "Admin.h"
#include "Parser.h"
class FilesHelper
{
private:
	static void lastId(string filename, int id) {
		ofstream lastIdFile;
		lastIdFile.open(filename);
		lastIdFile << id;
		lastIdFile.close();
	}
public:
	static int getLast(string filename) {
		int id;
		ifstream lastIdFile;
		lastIdFile.open(filename);
		lastIdFile >> id;
		
		return id;
	}
	static void saveClient(Client c) {
		int id = getLast("clientsLastID.txt");
		ofstream clfile;
		clfile.open("data/clients.txt", ios::app);
		clfile << id + 1 << ' ' << c.getName() << ' ' << c.getPassword() << ' ' << c.getBalance() << endl;
		clfile.close();
		lastId("clientsLastID.txt", id + 1);
	}
	static void saveEmployee(string fileName, string lastID, Employee e) {
		int id = getLast(lastID);
		ofstream emfile;
		emfile.open("data/employee.txt", ios::app);
		emfile << id + 1 << ' ' << e.getName() << ' ' << e.getPassword() << ' ' << e.getSalary() << endl;
		emfile.close();
		lastId(lastID, id + 1);
	}
	static void getClients() {
		string line;
		ifstream clfile("data/clients.txt");
		if (!clfile.is_open()) {
			cout << "\nError opening the file\n" << endl;
			return;
		}
		cout << "\nFile Content: " << endl;
		while (getline(clfile, line)) {
			
			clients.push_back(Parser::parseToClient(line));

		}
		clfile.close();
	}
	static void getEmployees() {
		string line;
		ifstream emfile("data/employee.txt");
		if (!emfile.is_open()) {
			cout << "\nError opening the file" << endl;
			return;
		}
		cout << "\nFile content: " << endl;
		while (getline(emfile, line))
		{
			employees.push_back(Parser::employeeParser(line));
		}
		emfile.close();
	}
	static void getAdmins() {
		string line;
		ifstream adfile("data/admin.txt");
		if (!adfile.is_open()) {
			cout << "\nError opening the file" << endl;
			return;
		}
		while (getline(adfile, line)) {
			admins.push_back(Parser::adminParser(line));
		}
		adfile.close();
	}
	static void clearFile(string fileName, string lastID) {
		ofstream file, fileId;
		file.open(fileName, ios::trunc);
		file.close();

		fileId.open(lastID, ios::trunc);
		fileId.close();
	}
};

