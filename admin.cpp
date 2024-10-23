#ifndef _ADMIN_
#define _ADMIN_
#include "myheader.h"
#include "user_with_wallet.cpp"

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

    //TO STRING =================================================================
    string toString(){
        return User::toString();
    }
};

#endif