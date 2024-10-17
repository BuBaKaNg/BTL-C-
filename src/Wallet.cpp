#include "myheader.h"
#include "Wallet.h"
using namespace std;

void Wallet::setWalletID(string id){
    this->WalletID = id;
}

void Wallet::setBalance(int balance){
    this->balance = balance;
}

string Wallet::getWalletID(){
    return this->WalletID;
}

int Wallet::getBalance(){
    return this->balance;
}