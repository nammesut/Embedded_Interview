#include "Food.hpp"
#include "Table_Info.hpp"

ThongTinBan::ThongTinBan(uint8_t uBan, bool bTrangThai) {
    ban = uBan;
    trangThai = bTrangThai;
}

uint8_t ThongTinBan::getBan() {
    return ban;
}

bool ThongTinBan::getTrangThai() {
    return trangThai;
}

void ThongTinBan::themMon(Food mMon, uint8_t uSoLuong) {
    int ID;
    string TEN_MON;

    cout << "Nhap ID: ";
    cin >> ID;
    cout << "Nhap ten mon: ";
    cin >> TEN_MON;
    cout << "Nhap so luong: ";
    cin >> uSoLuong;
}