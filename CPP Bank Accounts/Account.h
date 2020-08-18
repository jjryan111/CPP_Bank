#pragma once
class Account
{
private:
    int account_num=0;
    double balance=0;
    char account_state='c';
public:

    Account();
    ~Account();
    void setAccountNum(int anum);
    void setBalance(double bal);
    void setAccountState(char state);
    int getAccountNum();
    double getBalance();
    char getAccountState();
};

