#include "myheader.h"
#include "UserWithWallet.h"
using namespace std;

UserWithWallet::UserWithWallet(){}

bool UserWithWallet::isEqual(UserWithWallet* other){
    if(this->getAccountName() == other->getAccountName() && this->getPassword() == other->getPassword()){
        return true;
    }
}
Wallet* UserWithWallet::getWallet(){
    return wallet;
        }
vector<Transaction*> UserWithWallet::getTransactions(){
    return transactions;
        }
void UserWithWallet::setTransactions(vector<Transaction*> transactions){
    this->transactions = transactions;
        }
void UserWithWallet::setWallet(Wallet* wallet){
    this->wallet = wallet;
}

void UserWithWallet::writeToFile(ofstream& ofs){
    User::writeToFile(ofs); 
    ofs << this->wallet->getWalletID();
    ofs << "\n" << this->wallet->getBalance();
}

void UserWithWallet::readFromFile(ifstream& ifs){
        User::readFromFile(ifs);
        string line;
        getline(ifs,line);
        int balance;
        ifs >> balance;
        ifs.ignore();
        Wallet* wallet = new Wallet(line, balance);
        this->setWallet(wallet);
}

void UserWithWallet::showTransaction(ifstream& ifs){
    vector<Transaction*> listTransaction;
    while(!ifs.eof()){
        Transaction* transaction = new Transaction();
        transaction->readFromFile(ifs);
        if(transaction->getUserID() == this->getUserId()){
            listTransaction.push_back(transaction);
        }
    }
    for(auto transaction : listTransaction){
        cout << "Transaction ID: " << transaction->getTransactionId() << endl;
        cout << "Message: " << transaction->getMessage() << endl;
    }
    listTransaction.clear();
}

void UserWithWallet::Trade(ifstream& ifs){
    string walletId;
    cout << "Please enter the wallet id you want to trade: ";
    cin >> walletId;
    int point;
    cout << "Please enter the point to trade: ";
    cin >> point;
    while(!ifs.eof()){
        UserWithWallet* userWithWallet = new UserWithWallet();
        userWithWallet->readFromFile(ifs);
        if(userWithWallet->getWallet()->getWalletID() == walletId){
            if(this->getWallet()->getBalance() >= point){
                int newPoint = this->getWallet()->getBalance() - point;
                this->getWallet()->setBalance(newPoint);
            }
            int oldBalance = userWithWallet->getWallet()->getBalance();
            userWithWallet->getWallet()->setBalance(oldBalance + point);
        }
    }
    
}