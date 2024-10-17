#include "myheader.h"
#include "Admin.h"
using namespace std;

vector<UserWithWallet*> Admin::getUserWithWallet(){
    return this->listUser;
}

void Admin::setUserWithWallet(vector<UserWithWallet*> listUser){
    this->listUser = listUser;
}

void Admin::showList(ifstream& ifs){
    vector<UserWithWallet*> listUserWithWallet;
    while(!ifs.eof()){
        UserWithWallet* userWithWallet = new UserWithWallet();
        userWithWallet->readFromFile(ifs);
        listUserWithWallet.push_back(userWithWallet);
    }
    cout << "List User With Wallet:" << endl;
    for(auto user : listUserWithWallet){
        user->reviewInfor();
    }
}
