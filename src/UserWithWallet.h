#ifndef USER_WITH_WALLET
#define USER_WITH_WALLET
// Khai báo file
#include "myheader.h"
#include "Wallet.h"
#include "User.h"
#include "Transaction.h"

using namespace std;

//Class User thông thường
class UserWithWallet : public User {
    private: 
        Wallet* wallet;
        vector<Transaction*> transactions;
    public: 
    //Constructor
        UserWithWallet();
        Wallet* getWallet();
        vector<Transaction*> getTransactions();
        void setTransactions(vector<Transaction*> transactions);
        void setWallet(Wallet* wallet);
        void Trade(ifstream& ifs);
        bool isEqual(UserWithWallet* other); //Dùng để so sánh user
        void writeToFile(ofstream& ofs);
        void readFromFile(ifstream& ifs);
        void showTransaction(ifstream& ifs);
};

#endif