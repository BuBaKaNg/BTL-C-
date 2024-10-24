#ifndef _GLOBAL_FUNCTION_
#define _GLOBAL_FUNCTION_

#include "myheader.h"


using namespace std;

//LOAD DỮ LIỆU TỪ FILE =================================================================

static int maxWalletId;
static int maxUserId;
static TotalWallet* totalWallet;

vector<Admin*> loadToAdmins(){ // Hàm này load lên danh sách admin
    vector<Admin*> admins;
    ifstream ifs("D:\\material\\C++\\RewardWallet\\db_admin.txt");
    while (ifs.good()) {
        Admin* admin = new Admin();
        admin->readFromFile(ifs);
        
        // Kiểm tra nếu đọc thành công thông tin user
        if (ifs.fail()) {
            delete admin;
            break;  // Dừng nếu không còn dữ liệu hợp lệ
        }

        admins.push_back(admin);
    }
    ifs.close();
    return admins;
}

vector<UserWithWallet*> loadToUsers(){ // hàm này load lên danh sách user
    vector<UserWithWallet*> users;
    ifstream ifs("D:\\material\\C++\\RewardWallet\\db_user.txt");
     while (ifs.good()) {
        UserWithWallet* user = new UserWithWallet();
        user->readFromFile(ifs);
        
        // Kiểm tra nếu đọc thành công thông tin user
        if (ifs.fail()) {
            delete user;
            break;  // Dừng nếu không còn dữ liệu hợp lệ
        }

        users.push_back(user);
    }
    ifs.close();
    return users;
}

vector<Transaction*> loadTransactionsById(string userId){ 
/* hàm này load lên danh sách các transaction dựa trên id của user*/
    vector<Transaction*> transactions;
    ifstream ifs("D:\\material\\C++\\RewardWallet\\db_transaction.txt");
    while(!ifs.eof()){
        Transaction* transaction = new Transaction();
        transaction->readFromFile(ifs);
        if(transaction->getUserId() == userId){
            transactions.push_back(transaction);
        }
    }
    ifs.close();
    return transactions;
}

void loadConfig(){
    //Hàm này load lên ví tổng
    ifstream ifs("D:\\material\\C++\\RewardWallet\\db_config.txt");
    int value;
    ifs >> value;
    totalWallet->setOriginPoint(value);
    ifs.ignore();
    ifs >> value;
    totalWallet->setRemainPoint(value);
    ifs.ignore();
    ifs >> maxWalletId;
    ifs.ignore();
    ifs >> maxUserId;
    ifs.ignore();
    ifs.close();
} 
//________________________________________________________________

//GHI LẠI DỮ LIỆU XUỐNG FILE 

    void saveToAdmins(vector<Admin*> admins){
    /* hàm này ghi danh sách admin xuống file*/
        ofstream ofs("D:\\material\\C++\\RewardWallet\\db_admin.txt", ios::trunc);
        for(auto admin : admins){
            admin->writeToFile(ofs);
        }
        ofs.close();
    }

    void saveToUsers(vector<UserWithWallet*> users){
    /* hàm này ghi danh sách user xuống file*/
        ofstream ofs("D:\\material\\C++\\RewardWallet\\db_user.txt", ios::trunc);
        for(auto user : users){
            user->writeToFile(ofs);
        }
        ofs.close();
    }

    void saveToConfig(TotalWallet* totalWallet){
    // Hàm này ghi xuống ví tổng
        ofstream ofs("D:\\material\\C++\\RewardWallet\\db_config.txt", ios::trunc);
        ofs << totalWallet->getOriginPoint();
        ofs << '\n' << totalWallet->getRemainPoint();
        ofs << '\n' << maxWalletId;
        ofs << '\n' << maxUserId;
        ofs << '\n';
        ofs.close();        
    }

//________________________________________________________________

//CÁC HÀM BỔ SUNG =================================================================
    bool isValidTotal(TotalWallet* totalWallet, vector<UserWithWallet*>& users){
        /*Hàm này dùng để check tiền trong hệ thống có được bảo toàn không*/
        int sum = 0;
        for(UserWithWallet* user : users){
            sum += user->getBalance();
        }
        return sum + totalWallet->getRemainPoint() == totalWallet->getOriginPoint();
    }

//________________________________________________________________________________

//SINH WALLET ID
string generateWalletId(){
    // Hàm này sinh ra wallet id mới
    maxWalletId++;
    string walletId = to_string(maxWalletId);
    while(walletId.length() < 9){
        walletId = "0" + walletId;
    }

    return "WALLET" + walletId;
}

//SINH USER ID

string generateUserId(){
    // Hàm này sinh ra user id mới
    maxUserId++;
    string userId = to_string(maxUserId);
    while(userId.length() < 9){
        userId = "0" + userId;
    }

    return "USER" + userId;
}

#endif