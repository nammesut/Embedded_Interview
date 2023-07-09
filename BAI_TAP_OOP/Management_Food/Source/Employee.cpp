#include "Employee.hpp"
#include "Table_Info.hpp"

using namespace std;

NhanVien::NhanVien(list<Food> lDatabase, uint8_t uSoBan) {
    int SO_BAN;

    Database.assign(lDatabase.begin(), lDatabase.end());
    
    printf("\n\t%7s\t", "So ban");
    for(int i = 1; i <= uSoBan; i++) {
        printf("\t%3d", i);
        ThongTinBan ban(i, false);

        Database_Ban.push_back(ban);
    }

    printf("\n\t%7s\t", "Trang thai");
    for(auto item : Database_Ban) {
        if(item.getTrangThai() == false)
            printf("\t%3c", 'O');
        else
            printf("\t%3c", 'X');
    }

    cout << "Chon ban: ";
    cin >> SO_BAN;



}