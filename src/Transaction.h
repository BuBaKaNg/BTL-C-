#include "myheader.h"
using namespace std;

class Transaction {
    private:
        int transactionId;
        string userId;
        string message;

    public:
        // constructor
        Transaction();
        Transaction(int id, string message, string userId);
        int getTransactionId();
        string getMessage();
        string getUserID();
        void setTransactionId(int id);
        void setMessage(string message);
        void setUserID(string userID);
        void writeToFile(ofstream& ofs);
        void readFromFile(ifstream& ifs);
};