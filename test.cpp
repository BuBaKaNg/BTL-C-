#include "myheader.h"

using namespace std;

int main(){
    vector<Admin*> admins = loadToAdmins();
    admins[0]->setName("Le Dui Bau");
    for(Admin* admin: admins){
        cout << admin->toString() << endl;
    }
    saveToAdmins(admins);
}
