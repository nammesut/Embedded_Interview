#ifndef TABLE_INFO_HPP
#define TABLE_INFO_HPP
#include <iostream>
#include <list>
#include "Food.hpp"

using namespace std;

class ThongTinBan {
    private: 
        uint8_t ban;
        bool trangThai;
        typedef struct {
            Food mon;
            uint8_t soLuong;
        }typeMon;
        list<typeMon> Database_Mon;
    public:
        ThongTinBan(uint8_t uBan, bool bTrangThai);
        uint8_t getBan();
        bool getTrangThai();
        void themMon(Food mMon, uint8_t uSoLuong);
        void suaMon(uint8_t uId, uint8_t uSoLuong);
        void xoaMon(uint8_t uId);
};

#endif