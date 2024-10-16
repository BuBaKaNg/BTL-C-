#include "myheader.h"
#include "UserWithWallet.h"
using namespace std;

bool UserWithWallet::isEqual(UserWithWallet* other){
    if(this->getAccountName() == other->getAccountName() && this->getPassword() == other->getPassword()){
        return true;
    }
}