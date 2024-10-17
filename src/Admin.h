#ifndef ADMIN_H
#define ADMIN_H

#include "myheader.h"
#include "UserWithWallet.h"
#include "Wallet.h"
// Kế thừa class user
class Admin : public User {
    private:
        vector<UserWithWallet*> listUser;
    public:
        //Constructor
        Admin(string account, string password, string email, string phoneNumber);
        vector<UserWithWallet*> getUserWithWallet();
        void setUserWithWallet(vector<UserWithWallet*> listUser);
        
        void showList(ifstream& ifs); 
        void updateInforOfUser(User* user); 
        UserWithWallet createAccount(string account, string password, string email, string phoneNumber); 
};
#endif