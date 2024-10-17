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

void User::setName(string name){
    this->name = name;
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

string User::getName(){
    return name;
}

void User::setRole(string role){
    this->role = role;
}

void User::writeToFile(ofstream &ofs){
    ofs << this->userId;
    ofs << this->name << "\n";
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
    this->name = line;
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

void User::modifyInfor(string option, string newInfor, string userId){
    vector<User*> users;
    ifstream ifs("D:\\material\\C++\\Project\\src\\User.txt");
    while(!ifs.eof()){
        User* user = new User();
        user->readFromFile(ifs);
        users.push_back(user);
    }
    ifs.close();
    if(option == "Name"){
        for(auto user : users){
            if(user->getUserId() == userId){
                user->setName(newInfor);
            }
        }
    } 
    else if(option == "Email"){
        for(auto user : users){
            if(user->getUserId() == userId){
                user->setEmail(newInfor);
            }
        }
    }
    else if(option == "Password"){
        for(auto user : users){
            if(user->getUserId() == userId){
                user->setPassword(newInfor);
            }
        }
    }
    else if(option == "phoneNumber"){
        for(auto user : users){
            if(user->getUserId() == userId){
                user->setPhoneNumber(newInfor);
            }
        }
    }
    else cout << "Invalid option" << endl; 
    ofstream ofs("D:\\material\\C++\\Project\\src\\User.txt", ios::out | ios::trunc);
    for(auto user : users){
        user->writeToFile(ofs);
    }
    ofs.close();
}

void User::updateInfor(){
    cout << "--------------------------------" << endl;
    cout << "What information do you want to change?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Email" << endl;
    cout << "3. Password" << endl;
    cout << "4. Phone Number" << endl;
    cout << "5. Exit" << endl;
    int choose; cin >> choose;

    if(choose == 1){
        cout << "Please enter the name you want to change: ";
        string newName; cin >> newName;
        modifyInfor("Name", newName, this->getUserId());
    }
    else if(choose == 2){
        cout << "Please enter the email you want to change: ";
        string newEmail; cin >> newEmail;
        modifyInfor("Email", newEmail, this->getUserId());
    }
    else if(choose == 3){
        cout << "Please enter the password you want to change: ";
        string newPassword; cin >> newPassword;
        modifyInfor("Password", newPassword, this->getUserId());
    }
    else if(choose == 4){
        cout << "Please enter the phone number you want to change: ";
        string newPhoneNumber; cin >> newPhoneNumber;
        modifyInfor("phoneNumber", newPhoneNumber, this->getUserId());
    }
    else if(choose == 5){
        return;
    }
    else{
        cout << "Invalid option! Please try again." << endl;
        updateInfor();
    }
}

void User::reviewInfor(){
    cout << "User ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Account Name: " << accountName << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Role: " << role << endl;
}

