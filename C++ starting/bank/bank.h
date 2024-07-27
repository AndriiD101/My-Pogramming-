#ifndef BANKACOUNT_H
#define BANKACOUNT_H

#include <string>
using namespace std;

class BankAccount{
    public:
        BankAccount(string owner);

        BankAccount(string owner, int balance);

        void deposit(int amount);

        void withdraw(int amount);

        string get_owner() const;

        int get_balance() const;
        
    private:
        string owner;
        int balance;
};

#endif