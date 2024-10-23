#ifndef _WALLET_
#define _WALLET_
#include "myheader.h"

using namespace std;
//WALLET =================================================
class Wallet {
    
    //THUỘC TÍNH ============================================
    private:
    string userId;
    string walletId;
    int balance;
    //________________________________________________________________

    public:
    //CONSTRUCTOR ================================================
    Wallet(){}
    Wallet(string userId, string walletId, int balance) : userId(userId), walletId(walletId), balance(balance) {}
    //________________________________________________________________

    //GETTET, SETTER========================================
    string getUserId(){
        return userId;
    }
    string getWalletId(){
        return walletId;
    }
    int getBalance(){
        return balance;
    }
    void setUserId(string userId){
        this->userId = userId;
    }
    void setWalletId(string walletId){
        this->walletId = walletId;
    }
    void setBalance(int balance){
        this->balance = balance;
    }
    //________________________________________________________________

    //ĐỌC FILE =================================================
    void readFromFile(ifstream& ifs){
        ifs >> walletId >> balance;
    }
    //________________________________________________________________
};

#endif