#ifndef USER_H // dùng để xem mã nguồn đã được define chưa ?
#define USER_H // định nghĩa file 1 lần duy nhất nếu sau này có file nào cố gắng biến dịch 1 lần nữa sẽ bị chặn

// Khai báo thư viện

#include "myheader.h"
// #include <Wallet.h>
using namespace std;

class User{
    private:
    // thuộc tính
        string userId;
        string accountName;
        string password;
        string email;
        string role;
        string phoneNumber;
        string message;
    // phương thức
    public:
        //Constructor
        User();
        User(string id, string account, string password, string email, string phoneNumber);
        //setter and getter
        void setAccountName(string accountName);
        void setPassword(string password);
        void setEmail(string email);
        void setPhoneNumber(string phoneNumber);
        void setRole(string role);
        void setUserId(string userId);
        void setMessage(string message);
        string getAccountName();
        string getPassword();
        string getEmail();
        string getPhoneNumber();
        string getRole();
        string getUserId();
        string getMessage();
        //----------------------------------------------------------------        
        /*Thay đổi profile gồm 3 option
        1.đổi phone, 2. đổi email, 3. đổi email*/
        void updateInfor(); 
        void UpdateInfor();   
        void writeToFile(ofstream &ostream);  
        void readFromFile(ifstream &istream); 
        void print();
        void toString();
};

#endif