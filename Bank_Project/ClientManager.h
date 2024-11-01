#pragma once
#include "FilesHelper.h"
#include "FileManager.h"
#include "FillData.h"
class ClientManager
{
private:
	static void clientMenu() {
		cout << "[ 1 ] Check Balance" << endl;
		cout << "[ 2 ] Withdrow" << endl;
		cout << "[ 3 ] Deposit" << endl;
		cout << "[ 4 ] Transfer Amount" << endl;
		cout << "[ 5 ] Update Password" << endl;
		cout << "[ 6 ] Display Info" << endl;
		cout << "[ 7 ] Back To Client Menu" << endl;
		cout << "[ 8 ] Logout" << endl;
		
	}
public:
	static void updatePassword(Person* person) {
		string Password = FillData::enterPassword();
		person->setPassword(Password);
		cout << "Password Updated Successfully!\n";
	}

	static Client* login(int id, string password) {
		for (cIt = clients.begin(); cIt != clients.end();cIt++) {

			if (cIt->getId() == id && cIt->getPassword() == password) {
				return cIt._Ptr;
			}
		}

		return NULL;
	}

	static void back(Client* client) {
		clientOptions(client);
	}

	static bool clientOptions(Client* client) {
		clientMenu();
		cout << "\nChoose an Option...\n";
		int option;
		cin >> option;
		Employee employee;
		double amount;
		FileManager f;
		switch (option)
		{
		case 1:
			system("cls");
			client->checkBalance();
			break;
		case 2:
			system("cls");
			cout << "\nEnter the Amount: ";
			cin >> amount;
			client->withdraw(amount);
			f.updateClient();
			break;
		case 3:
			system("cls");
			cout << "\nEnter the Amount: ";
			cin >> amount;
			client->deposit(amount);
			f.updateClient();
			break;
		case 4:
			system("cls");
			cout << "\nEnter The ID: ";
			int id;
			cin >> id;
			while (employee.searchClient(id) == NULL) {
				cout << "\nInvalid ID!\n";
				cout << "\nPlease, Enter A Valid ID: ";
				cin >> id;

			}
			cout << "\nEnter The Amount: ";
			cin >> amount;
			client->transferTo(*employee.searchClient(id), amount);
			f.updateClient();
			break;
		case 5:
			system("cls");
			updatePassword(client);
			f.updateClient();
			break;
		case 6:
			system("cls");
			client->displayInfo();
			break;
		case 7:
			system("cls");
			back(client);
			break;
		case 8:
			system("cls");
			return false;
			break;

		default:
			system("cls");
			cout << "\nPlease Enter An Exists Number From the Menu!\n";
			clientOptions(client);
			break;
		}

		char op = 'y';
		if (op == 'y' || op == 'Y') {
			cout << "\nDo You Want Another Option? (Y/N)\n";
			cin >> op;
			system("cls");
			if (op == 'y' || op == 'Y') {
				clientOptions(client);
			}
			else {
				return false;
			}
		}

		return false;

	}
};

