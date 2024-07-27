#include <iostream>
#include "bank.h"
using namespace std;
// g++ -std=c++11 main.cpp bank.cpp -o main


int main(){
    BankAccount my_account("Andrii Denysenko", 5000);
    BankAccount bobs_account("Bob");

    bobs_account.deposit(500);
    cout << bobs_account.get_balance() << endl;

    my_account.withdraw(500);
    cout << my_account.get_balance() << endl;


    return 0;
}