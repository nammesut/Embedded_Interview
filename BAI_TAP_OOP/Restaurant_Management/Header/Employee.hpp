#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
#include <list>
#include "Food.hpp"
#include "Table_Info.hpp"
using namespace std;

class NhanVien {
    private:
        list<Food> Database;
        list<ThongTinBan> Database_Ban;
    public:
        NhanVien(list<Food> lDatabase, uint8_t uSoBan);
        void hienThiAllBan(uint8_t uSoBan);
};

#endif