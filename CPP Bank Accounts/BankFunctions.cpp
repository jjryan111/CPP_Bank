#include "BankFunctions.h"
#include <iostream>
#include "Account.h"
#include "BankConstants.h"

using namespace std;

BankFunctions::BankFunctions() {}
BankFunctions::~BankFunctions() {}

void BankFunctions::closeAllAndExit(Account acts[MAXACCOUNTS]) {
    for (int i = 0; i < MAXACCOUNTS; i++) {
        closeAccount(acts, STARTACTNUM + i);
    }
}

void BankFunctions::addInterest(Account acts[MAXACCOUNTS], double rate) {
    for (int i = 0; i < MAXACCOUNTS; i++) {
        char astate = acts[i].getAccountState();
        if (acts[i].getAccountState() == 'o') {
            acts[i].setBalance(acts[i].getBalance() * (1 + (rate / 100)));
        }
    }
}

bool BankFunctions::closeAccount(Account acts[MAXACCOUNTS], int act_num) {
    bool done = false;
    int found = findAccount(acts, act_num);
    if (isOpenAccount(acts, act_num)) {
        acts[found].setAccountState('c');
        acts[found].setBalance(0);
        done = true;
    }
    return done;
}

bool BankFunctions::withdraw(Account acts[MAXACCOUNTS], int act_num, double withdrawal) {
    bool done = false;
    int found = findAccount(acts, act_num);
    if (isOpenAccount(acts, act_num) && acts[found].getBalance() > withdrawal) {
        acts[found].setBalance(acts[found].getBalance() - withdrawal);
        printAccount(acts, found);
        done = true;
    }
    return done;
}

bool BankFunctions::deposit(Account acts[MAXACCOUNTS], int act_num, double deposit) {
    int found = findAccount(acts, act_num);
    bool done = false;
    if (isOpenAccount(acts, act_num)) {
        acts[found].setBalance(acts[found].getBalance()+ deposit);
        printAccount(acts, found);
        done = true;
    }
    return done;
}

bool BankFunctions::balanceInquiry(Account acts[MAXACCOUNTS], int act_num) {
    int found = findAccount(acts, act_num);
    bool done = false;
    if (isOpenAccount(acts, act_num)) {
        printAccount(acts, found);
        done = true;
    }
    return done;
}

bool BankFunctions::isOpenAccount(Account acts[MAXACCOUNTS], int act_num) {
    int found = findAccount(acts, act_num);
    if (found < MAXACCOUNTS && acts[found].getAccountState() == 'o') {
        return true;
    }
    else {
        return false;
    }
}
int BankFunctions::findAccount(Account acts[MAXACCOUNTS], int act_num) {
    int ctr = 0;
    bool act_found = false;
    while ((acts[ctr].getAccountNum() <= UPPERACTBOUNDARY) && act_found == false) {
        if (acts[ctr].getAccountNum() == act_num) {
            act_found = true;
            return ctr;
        }
        ctr++;
    }
    return ctr;
}

bool BankFunctions::openNewAccount(Account acts[MAXACCOUNTS], double init_dep) {
    int ctr = 0;
    bool act_created = false;
    while (acts[ctr].getAccountNum() <= (STARTACTNUM + MAXACCOUNTS) && acts[ctr].getAccountState() == 'o') {
        ctr++;
    }
    if (ctr < (UPPERACTBOUNDARY)) {
        acts[ctr].setAccountState('o');
        acts[ctr].setBalance( acts[ctr].getBalance() + init_dep);
        act_created = true;
        printAccount(acts, ctr);
    }
    else {
        cout << "Max accounts reached.\n";
    }
    return act_created;
}

void BankFunctions::printAccount(Account acts[MAXACCOUNTS], int ctr_num) {
    cout << acts[ctr_num].getAccountNum() << "\t" << "$" << acts[ctr_num].getBalance() << endl;
}

void BankFunctions::printAllAccounts(Account acts[MAXACCOUNTS], char state) {
    for (int i = 0; i < MAXACCOUNTS; i++) {
        if (acts[i].getAccountState() == state) {
            printAccount(acts, i);
        }
    }
}

void BankFunctions::setupAccounts(Account acts[MAXACCOUNTS]) {
    for (int i = 0; i < MAXACCOUNTS; i++) {
        acts[i].setAccountNum(i + STARTACTNUM);
        acts[i].setBalance(0);
        acts[i].setAccountState('c');
    }
}

