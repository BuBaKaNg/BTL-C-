#include "myheader.h"
#include "Transaction.h"
using namespace std;

Transaction::Transaction(int id, string message){
    this->transactionId = id;
    this->message = message;
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