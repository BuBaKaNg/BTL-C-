#include "myheader.h"
#include "Transaction.h"
using namespace std;


Transaction::Transaction(){}
Transaction::Transaction(int id, string message, string userId){
    this->transactionId = id;
    this->message = message;
    this->userId = userId;
}

void Transaction::setMessage(string message){
    this->message = message;
}

void Transaction::setTransactionId(int id){
    this->transactionId = id;
}

string Transaction::getMessage(){
    return this->message;
}

int Transaction::getTransactionId(){
    return this->transactionId;
}

void Transaction::setUserID(string userID){
    this->userId = userID;
}

string Transaction::getUserID(){
    return this->userId;
}

void Transaction::writeToFile(ofstream& ofs){
    ofs << this->userId;
    ofs << this->transactionId << "\n";
    ofs << this->message;
}

void Transaction::readFromFile(ifstream& ifs){
    ifs >> this->userId;
    ifs >> this->transactionId;
    getline(ifs, this->message);
}