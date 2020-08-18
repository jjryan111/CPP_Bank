// CPP Bank Accounts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BankUI.h"
#include "BankFunctions.h"
#include "Account.h"
#include "BankConstants.h"

using namespace std;



int main()
{
    char in_choice = ' ';
    BankFunctions bf;
    Account act_array[MAXACCOUNTS];
    bf.setupAccounts(act_array);
    BankUI ui;
    do {
        in_choice = ui.getInput();
        in_choice = ui.validateInput(in_choice);
        if (in_choice != 0) {
            ui.performAction(bf, act_array, in_choice);
        }
    } while (in_choice != 'e');
}

