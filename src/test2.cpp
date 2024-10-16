#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 6;
    ofstream ofs("D:\\material\\C++\\Project\\src\\test_ghi_file.bin", ios::binary);
    ofs.write((char *)&n, sizeof(n));
    ofs.close();
    int r;
    ifstream ifs("D:\\material\\C++\\Project\\src\\test_ghi_file.bin", ios::binary);
    ifs.read((char *)&r, sizeof(r));
    cout << r << endl;

}