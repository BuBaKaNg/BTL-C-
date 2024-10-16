#include "myheader.h"
using namespace std;

class Transaction {
    private:
        int transactionId;
        string message;
    public:
        Transaction(int id, string message);
        int getTransactionId();
        string getMessage();
        void setTransactionId(int id);
        void setMessage(string message);
};