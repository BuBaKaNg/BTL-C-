#include <bits/stdc++.h>
#include "User.cpp"

using namespace std;

int main(){
    User* user = new User("1","John ose", "password123", "john.doe@example.com", "0123456789");

    ofstream ofs("D:\\material\\C++\\Project\\src\\test_ghi_file.txt", ios::app);
    ifstream ifs("D:\\material\\C++\\Project\\src\\test_ghi_file.txt");
    if (!ifs.is_open()) {
        cout << "Error: Cannot open file for writing" << endl;
        return 1;
    }
    ofs.close();  // Đóng file sau khi ghi xong
    ifs.close();
    return 0;
}