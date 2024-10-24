#ifndef _USER_WITH_WALLET_
#define _USER_WITH_WALLET_
#include "myheader.h"

using namespace std;
/*USER WITH WALLET
    - Được kế thừa từ user các thông tin
    - Được kế thừa 1 số phương thức cơ bản
*/
class UserWithWallet : public User{
    private:
    //THUỘC TÍNH =================================================================
    string walletId;
    int balance;
    //________________________________________________________________
    public:
    //CONSTRUCTOR =================================================
    UserWithWallet(){}
    UserWithWallet(string userId, string account, string password,string name, string phoneNumber, string email, string walletId, int balance)
     : User(userId, account, password, name, phoneNumber, email){
        this->walletId = walletId;
        this->balance = balance;
    }
    //________________________________________________________________

    //GETTER, SETTER =================================================
    string getWalletId(){return this->walletId;}
    void setWalletId(string walletId){this->walletId = walletId;}
    int getBalance(){return this->balance;}
    void setBalance(int balance){this->balance = balance;}
    //________________________________________________________________

    //ĐỌC FILE =================================================
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
        getline(ifs, line);
        this->setWalletId(line);
        int balance;
        ifs >> balance;
        ifs.ignore();
        this->setBalance(balance);
    }
    //________________________________________________________________

    //GHI FILE =================================================================
    void writeToFile(ofstream& ofs){
        ofs << this->getUserId();
        ofs << '\n' << this->getAccount();
        ofs << '\n' <<this->getPassword();
        ofs << '\n' << this->getName();
        ofs << '\n' << this->getEmail();
        ofs << '\n' << this->getPhoneNumber();
        ofs << '\n' << this->getWalletId();
        ofs << '\n' << to_string(this->getBalance());
        ofs << '\n';
    }
    //________________________________________________________________

    string toString(){
       return User::toString() + " " +  this->getWalletId() + " " + to_string(this->getBalance());

    }

    void showInfor(){
        User::showInfor();
        cout << "Wallet ID: " << this->getWalletId() << endl;
        cout << "Balance: " << this->getBalance() << endl;
    }

    void trade(vector<UserWithWallet*> &users){
        cout << "________________________________________________" << endl;
        string walletId;
        int amount;
        cout << "Enter wallet ID you want to trade: ";
        cin >> walletId;
        cin.ignore();
        cout << "Enter amount to trade: ";
        cin >> amount;
        cin.ignore();
        for(auto user : users){
            if(user->getWalletId() == walletId){
                if(this->getBalance() >= amount){
                    this->setBalance(this->getBalance() - amount);
                    user->setBalance(user->getBalance() + amount);                    
                }
                else{
                    cout << "Balance not enough" << endl;
                }
                return;
            }
        }
        cout << "Wallet ID not found" << endl;
    }
};
#endif 