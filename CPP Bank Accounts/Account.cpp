#include "Account.h"

Account::Account() {}
Account::~Account() {}
void Account::setAccountNum(int anum) { account_num = anum; }
void Account::setBalance(double bal) { balance = bal; }
void Account::setAccountState(char state) { account_state = state; }
int Account::getAccountNum() { return account_num; }
double Account::getBalance() { return balance; }
char Account::getAccountState() { return account_state; }
