#ifndef _TOTAL_WALLET
#define _TOTAL_WALLET
#include "myheader.h"
using namespace std;
//TOTAL WALLET =================================================================
class TotalWallet{
    private:
    //THUỘC TÍNH =================================================================
    int remainPoint;
    int originPoint;
    //________________________________________________________________
    public:
    //CONSTRUCTOR =================================================================
    TotalWallet(){}
    TotalWallet(vector<UserWithWallet*> list, int total) : remainPoint(total) {}
    //________________________________________________________________

    //GETTER, SETTER =================================================================
    int getRemainPoint(){return this->remainPoint;}
    void setRemainPoint(int remainPoint){this->remainPoint = remainPoint;}
    int getOriginPoint(){return this->originPoint;}
    void setOriginPoint(int originPoint){this->originPoint = originPoint;}
    //________________________________________________________________

    //ĐỌC FILE =================================================================
    void readFromFile(ifstream &ifs){
        string line;
        getline(ifs,line);
        this->setRemainPoint(stoi(line));
    }
    //________________________________________________________________
};
//__________________________________________________________________
#endif