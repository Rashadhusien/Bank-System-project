#pragma once

#include <Windows.h>
#include "AdminManager.h"
class Screens
{
private:


	static void welcome() {
		system("Color 0e");
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Welcome To Our Bank !!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		Sleep(4000);
		system("cls");
		system("Color 0b");
	}

	static void loginOptions() {
		cout << "(1) Admin\n";
		cout << "(2) Employee\n";
		cout << "(3) Client\n\n";
		cout << "Login as : ";
	}

	static int loginAs() {
		loginOptions();
		int option;
		cin >> option;
		if (option == 1 || option == 2 || option == 3) {
			system("cls");
			return option;
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invalid(int option) {
		system("cls");
		cout << "\nInvalid ID or Password\n";
		loginScreen(option);
	}

	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}
	static void loginScreen(int option) {
		loginOptions();
		int id;
		string password;
		cout << "\nPlease Enter Your ID : ";
		cin >> id;
		cout << "\nPlease Enter Your Password : ";
		cin >> password;
		switch (option)
		{
		case 1:
			system("cls");
			if (AdminManager::login(id, password) != NULL) {
				while (AdminManager::adminOptions(AdminManager::login(id, password)));
				logout();
			}
			else {
				invalid(1);
				break;
			}
		case 2:
			system("cls");
			if (EmployeeManager::login(id, password) != NULL) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)));
				logout();
			}
			else {
				invalid(2);
				break;
			}
		case 3:
			system("cls");
			if (ClientManager::login(id, password) != NULL)
			{
				while (ClientManager::clientOptions(ClientManager::login(id, password)));
				logout();
			}
			else invalid(3);
			break;
		default:
			system("cls");
			loginOptions();
			break;
		}
	}
public:
	static void runApp() {
		FileManager f;
		f.getAllData();
		welcome();
		loginScreen(loginAs());
	}
};

