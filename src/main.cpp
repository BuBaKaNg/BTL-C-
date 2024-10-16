#include "myheader.h"
#include "User.cpp"
#include "view.cpp"
#include "GlobalFunction.cpp"

using namespace std;

int main(){
    while(1){
        startScreen();
        int choose; cin >> choose; 
        switch(choose){
            case 1:
                logging();
            case 2:
            case 0:
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }
}