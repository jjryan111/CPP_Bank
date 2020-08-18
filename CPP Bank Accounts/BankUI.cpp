#include "BankUI.h"
#include <iostream>
#include <string>
#include "ValidNum.h"
#include "BankFunctions.h"

using namespace std;

	BankUI::BankUI() {}
	char BankUI::getInput() {
		char in_char = ' ';
		system("CLS");
		cout << "###########################################" << endl;
		cout << "# Welcome to the Guh Banking System       #" << endl;
		cout << "# Pick from the following options:        #" << endl;
		cout << "# (o)pen account       (b)alance inquiry  #" << endl;
		cout << "# (d)eposit            (w)withdrawal      #" << endl;
		cout << "# (c)lose account      (i)nterest         #" << endl;
		cout << "# (p)rint accounts     (e)xit             #" << endl;
		cout << "###########################################" << endl;
		cout << endl;
		cout << "Make a choice (obdwcipe): ";
		cin >> in_char;
		return in_char;
	}
	char BankUI::validateInput(char inp) {
		char valid_choices[] = "obdwcipe";
		if (strchr(valid_choices, inp) != NULL) {
			return inp;
		}
		else {
			cout << "Invalid choice. Try again\n";
			return 0;
		}
	}
	void BankUI::performAction(BankFunctions bf, Account acts[], char inp) {
		ValidNum vn;
		string entry;
		int num;
		double transaction;
		bool done;
		switch (inp) {
		case 'o':
			transaction = vn.validateEntry("Enter initial deposit: ", 0);
			if (transaction != -1) {
				done = bf.openNewAccount(acts, transaction);
				if (done) {
					cout << "New account opened and $" << transaction << " deposited.\n";
					system("pause");
				}
			}				
			break;
		case 'b':
			num = vn.validateEntry("Enter account number: ");
			if (num != -1) {
				done = bf.balanceInquiry(acts, num);
				system("pause");
			}
			else {
				cout << "Invalid or closed account.\n";
			}
			break;
		case 'd':
			num = vn.validateEntry("Enter account number: ");
			if (num != -1) {
				transaction = vn.validateEntry("Enter deposit amount: ", 0);
				if (transaction != -1) {
					done = bf.deposit(acts, num, transaction);
					if (done) {
						cout << "$" << transaction << " deposited into account " << num << endl;
						system("pause");
					}
				}
				else {
					cout << "Invalid or closed account.\n";
				}
			}
			break;
		case 'w':
			num = vn.validateEntry("Enter account number: ");
			if (num != -1) {
				transaction = vn.validateEntry("Enter withdrawal amount: ", 0);
				if (transaction != -1) {
					done = bf.withdraw(acts, num, transaction);
					if (done) {
						cout << "$" << transaction << " received from account " << num << endl;
						system("pause");
					}
				}
				else {
					cout << "Invalid or closed account.\n";
				}
			}
			break;
		case 'c':
			num = vn.validateEntry("Enter account number: ");
			if (num != -1) {
				done = bf.closeAccount(acts, num);
				if (done) {
					cout << "Account " << num << " closed." << endl;
					system("pause");
				}
			}
			else {
				cout << "Invalid account.\n";
			}
			break;
		case 'i':
			transaction = vn.validateEntry("Enter interest rate: ", 0);
			if (transaction != -1) {
				bf.addInterest(acts, transaction);
				cout << "All open accounts increased by " << transaction << "%" << endl;
				system("pause");
			}
			break;
		case 'p':
			bf.printAllAccounts(acts, 'o');
			system("pause");
			break;
		case 'e':
			bf.closeAllAndExit(acts);
			cout << "Closed all accounts. Exiting." << endl;
			system("pause");
			break;
		}
	}
