#pragma once
#include "BankFunctions.h"
class BankUI
{
private:
public:
	BankUI();
	char getInput();
	char validateInput(char inp);
	void performAction(BankFunctions bf, Account acts[], char inp);
};

