#ifndef _GLOBAL_FUNCTION_
#define _GLOBAL_FUNCTION_
#include "myheader.h"

using namespace std;

//LOAD DỮ LIỆU TỪ FILE =================================================================

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

TotalWallet* loadTotalWallet(){
    //Hàm này load lên ví tổng
    TotalWallet* totalWallet = new TotalWallet();
    ifstream ifs("D:\\material\\C++\\RewardWallet\\db_total_wallet.txt");
    int value;
    ifs >> value;
    totalWallet->setOriginPoint(value);
    ifs.ignore();
    ifs >> value;
    totalWallet->setRemainPoint(value);
    ifs.ignore();
    ifs.close();
    return totalWallet;
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

    void saveToTotalPoint(TotalWallet* totalWallet){
    // Hàm này ghi xuống ví tổng
        ofstream ofs("D:\\material\\C++\\RewardWallet\\db_total_point.txt", ios::trunc);
        ofs << totalWallet->getOriginPoint();
        ofs << '\n' << totalWallet->getRemainPoint();
        ofs << '\n';
        ofs.close();        
    }

//________________________________________________________________

#endif