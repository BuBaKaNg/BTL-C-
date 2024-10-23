#ifndef _TRANSACTION_
#define _TRANSACTION_
#include "myheader.h"

using namespace std;
//TRANSACTION ============================================================
class Transaction{
    //THUỘC TÍNH
    private:
    string transactionId;
    string userId;
    string message;
    public:
    //CONSTRUCTOR ============================================================
    Transaction(){};
    Transaction(string id, string userId, string message) : transactionId(id), userId(userId), message(message){};
    //________________________________________________________________

    //GETTER, SETTER ========================================================
    string getTransactionId(){return transactionId;};
    string getUserId(){return userId;};
    string getMessage(){return message;};
    void setTransactionId(string id){transactionId = id;};
    void setUserId(string userId){this->userId = userId;};
    void setMessage(string message){this->message = message;};
    //________________________________________________________________

    //ĐỌC FILE =================================================
    void readFromFile(ifstream& ifs){
        string line;
        getline(ifs, line);
        this->setUserId(line);
        getline(ifs, line);
        this->setTransactionId(line);
        getline(ifs, line);
        this->setMessage(line);
    }
    //________________________________________________________________

    //GHI FILE =================================================
    void writeToFile(ofstream& ofs){
        ofs << this->getUserId() << "\n";
        ofs << this->getTransactionId() << "\n";
        ofs << this->getMessage() << "\n";
    }
    //________________________________________________________________
};  
//________________________________________________________________

#endif