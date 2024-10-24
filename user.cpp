#ifndef _USER_
#define _USER_
#include "myheader.h"

using namespace std;
//USER =================================================================
class User{
    protected:
    //THUỘC TÍNH =================================================================
    string userId;
    string account;
    string password;
    string name;
    string email;
    string phoneNumber;
    //________________________________________________________________
    public:
    //CONSTRUCTOR =================================================================
    User(){}
    User(string userId, string account, string password, string name, string email, string phoneNumber):
        userId(userId), account(account), password(password), name(name), email(email), phoneNumber(phoneNumber){}
    //________________________________________________________________

    //GETTER, SETTER =================================================================
    string getUserId() { return userId; }
    string getAccount() { return account; }
    string getPassword() { return password; }
    string getName() { return name; }
    string getEmail() { return email; }
    string getPhoneNumber() { return phoneNumber; }
    void setUserId(string userId) { this->userId = userId; }
    void setAccount(string account) { this->account = account; }
    void setPassword(string password) { this->password = password; }
    void setName(string name) { this->name = name; }
    void setEmail(string email) { this->email = email; }
    void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
    //________________________________________________________________

    //PHƯƠNG THỨC
    void showInfor(){
        /*Hàm này dùng để đưa ra màn hình thông tin người dùng*/
        cout << "________________________________________________________________" << endl;
        cout << "User ID: " << this->getUserId() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Email: " << this->getEmail() << endl;
        cout << "Phone Number: " << this->getPhoneNumber() << endl;
    }
    void updateInfor(){
        /*Hàm này dùng để update infor người dùng và admin*/
        while(1){
            cout << "________________________________________________________________" << endl;
            int option;
            cout << "1. Update Name" << endl;
            cout << "2. Update Email" << endl;
            cout << "3. Update Phone Number" << endl;
            cout << "4. Update Password" << endl;
            cout << "0. Exit" << endl;
            cout << "Choose option:";
            cin >> option;
            cin.ignore();
            string new_infor;
            if(option == 1){
                cout << "Please enter your new name:";
                getline(cin, new_infor);
                this->setName(new_infor);
            }
            else if(option == 2){
                cout << "Please enter your new email:";   
                getline(cin, new_infor);         
                this->setEmail(new_infor);
            }
            else if(option == 3){
                cout << "Please enter your new phone number:"; 
                getline(cin, new_infor);
                this->setPhoneNumber(new_infor);
            }
            else if(option == 4){
                cout << "Please enter your new password:"; 
                getline(cin, new_infor);
                this->setPassword(new_infor);
            }
            else if(option == 0){
                return;
            }
        }
    }

    //TO STRING =================================================================
    string toString(){
        return this->getUserId() + " " + this->getName() + " " + this->getEmail() + " " + this->getPhoneNumber() +
        " " + this->getAccount() + " " + this->getPassword();
    }

    //________________________________________________________________
};
//________________________________________________________________
#endif