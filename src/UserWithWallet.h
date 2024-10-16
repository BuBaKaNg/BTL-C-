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
        Transaction* transaction;
    public: 
    //Constructor
        UserWithWallet(string, string, string, string);
        void Trade(UserWithWallet* other, int point);
        bool isEqual(UserWithWallet* other); //Dùng để so sánh user
};

#endif