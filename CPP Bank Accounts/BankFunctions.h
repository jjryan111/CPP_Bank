#pragma once
#include "Account.h"
#include "BankConstants.h"
class BankFunctions
{
private:
    
public:
    BankFunctions();
    ~BankFunctions();
    void setupAccounts(Account act_array[MAXACCOUNTS]);
    void printAllAccounts(Account acts[MAXACCOUNTS], char state);
    void printAccount(Account acts[MAXACCOUNTS], int act_num);
    bool openNewAccount(Account acts[MAXACCOUNTS], double init_dep);
    bool isOpenAccount(Account acts[MAXACCOUNTS], int act_num);
    int findAccount(Account acts[MAXACCOUNTS], int act_num);
    bool balanceInquiry(Account acts[MAXACCOUNTS], int act_num);
    bool deposit(Account acts[MAXACCOUNTS], int act_num, double deposit);
    bool withdraw(Account acts[MAXACCOUNTS], int act_num, double withdrawal);
    bool closeAccount(Account acts[MAXACCOUNTS], int act_num);
    void addInterest(Account acts[MAXACCOUNTS], double rate);
    void closeAllAndExit(Account acts[MAXACCOUNTS]);
};

