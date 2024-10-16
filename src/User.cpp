#include "myheader.h"
#include "User.h"



using namespace std;

User::User(){};
User::User(string id, string account, string password, string email, string phoneNumber){
    this->userId = id;
    this->accountName = account;
    this->password = password;
    this->email = email;
    this->phoneNumber = phoneNumber;
}

void User::setAccountName(string accountName){
            this->accountName = accountName;
}
void User::setPassword(string password){
            this->password = password;
}

void User::setEmail(string email){
            this->email = email;
};
        
void User::setPhoneNumber(string phoneNumber){
    this->phoneNumber = phoneNumber;
}

void User::setUserId(string userId){
    this->userId = userId;
}

void User::setMessage(string message){
    this->message = message;
}

string User::getAccountName(){
    return accountName;
}
        
string User::getPassword(){
    return password;
}

string User::getEmail(){
    return email;
}
        
string User::getPhoneNumber(){
    return phoneNumber;
}

string User::getRole(){
    return role;
}

string User::getUserId(){
    return userId;
}

string User::getMessage(){
    return message;
}

void User::setRole(string role){
    this->role = role;
}

void User::writeToFile(ofstream &ofs){
    ofs << this->userId;
    ofs << this->accountName << "\n";
    ofs << this->password << "\n";
    ofs << this->email << "\n";
    ofs << this->phoneNumber << "\n";
    ofs << this->role;
}

void User::readFromFile(ifstream &ifs){
    string line;
    getline(ifs,line);
    this->userId = line;
    getline(ifs,line);
    this->accountName = line;
    getline(ifs,line);
    this->password = line;
    getline(ifs,line);
    this->email = line;
    getline(ifs,line);
    this->phoneNumber = line;
    getline(ifs,line);
    this->role = line;
}

void User::print(){
    cout << "1";
}

void User::toString(){
    cout << "User ID: " << userId << endl;
    cout << "Account Name: " << accountName << endl;
    cout << "Password: " << password << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Role: " << role << endl;
}

