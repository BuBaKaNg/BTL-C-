#ifndef _ADMIN_
#define _ADMIN_
#include "myheader.h"

using namespace std;

//ADMIN =================================================================
/*
    - được kế thừa từ lớp user
*/
class Admin : public User{
    public:
    //CONSTRUCTOR =================================================================
    Admin(){}
    Admin(string id, string account, string password, string name, string email, string phoneNumber) :
        User(id, account, password, name, email, phoneNumber){

        }
    //ĐỌC FILE =================================================================
    void readFromFile(ifstream& ifs){
        string line;
        getline(ifs, line);
        this->setUserId(line);
        getline(ifs, line);
        this->setAccount(line);
        getline(ifs, line);
        this->setPassword(line);
        getline(ifs, line);
        this->setName(line);
        getline(ifs, line);
        this->setEmail(line);
        getline(ifs, line);
        this->setPhoneNumber(line);
    }
    //________________________________________________________________


    //GHI FILE =================================================================
    void writeToFile(ofstream& ofs){
        ofs << this->getUserId() << "\n";
        ofs << this->getAccount() << "\n";
        ofs << this->getPassword() << "\n";
        ofs << this->getName() << "\n";
        ofs << this->getEmail() << "\n";
        ofs << this->getPhoneNumber() << "\n";
    }
    //________________________________________________________________________________________________________________________________


    void showList(){
        vector<UserWithWallet*> users = loadToUsers();
        cout << "====================== LIST USERS ======================" << endl;
        cout << endl;
        for(auto user : users){
            cout << "*****************************************" << endl;
            cout << "User id : " << user->getUserId() << endl;
            cout << "Name : " << user->getName() << endl;
            cout << "Email : " << user->getEmail() << endl;
            cout << "Phone number : " << user->getPhoneNumber() << endl; 
            cout << "Wallet id : " << user->getWalletId() << endl;
            cout << "Balance : " << user->getBalance() << endl;
            cout << "******************************************" << endl;
            cout << endl;
        }
    }

    void updateInforOfUser(string userId){
        vector<UserWithWallet*> users = loadToUsers();
        for(auto user : users){
            if(user->getUserId() == userId){
                user->updateInfor();
            }
        }
    }

    UserWithWallet* createAccount(string account, string name, string password, string email, string phoneNumber, int amount){
        /*hàm này tạo tài khoản cho khách hàng*/
        string userId = generateUserId();
        string walletId = generateWalletId();
        UserWithWallet* user = new UserWithWallet(userId, account, name, password, email, phoneNumber, walletId, amount);
        totalWallet->setRemainPoint(totalWallet->getRemainPoint() - amount);
        return user;
    }

    //TO STRING =================================================================
    string toString(){
        return User::toString();
    }
    //________________________________________________________________
};

#endif
