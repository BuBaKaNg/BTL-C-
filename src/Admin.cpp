#include "myheader.h"
#include "Admin.h"
using namespace std;

vector<UserWithWallet*> Admin::getUserWithWallet(){
    return this->listUser;
}

void Admin::setUserWithWallet(vector<UserWithWallet*> listUser){
    this->listUser = listUser;
}

