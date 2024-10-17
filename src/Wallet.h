#ifndef WALLET_H //Check xem đã được define chưa để tránh biên dịch lỗi và tăng tính rõ ràng
#define WALLET_H

#include "myheader.h"

using namespace std;

class Wallet {
    private:
        string WalletID;
        int balance; // giả sử là tất cả user đều < 1 tỷ điểm
    public:
    // Constructor
        Wallet(string WalletID, int balance);
        void setWalletID(string walletID);
        void setBalance(int balance);
        string getWalletID();
        int getBalance();
};

#endif