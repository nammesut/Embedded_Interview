#include <iostream>
#include <math.h>

using namespace std;

class Sach {
    private:
        string tenSach;
        string tacGia;
        uint8_t namXuatBan;
        uint8_t soLuong;
    public: 
        Sach(string sTenSach = "", string sTacGia = "", uint8_t uSoLuong = 0);
        void thongTinSach();
        void muonSach(string sTenSach, string sTacGia, uint8_t uSoLuong);
        void traSach(string sTenSach, string sTacGia, uint8_t uSoLuong);
};

Sach::Sach(string sTenSach, string sTacGia, uint8_t uSoLuong){
    tenSach = sTenSach;
    tacGia = sTacGia;
    soLuong = uSoLuong;
}

void Sach::thongTinSach(){
    cout << "Ten sach: " << tenSach << endl;
    cout << "Tac gia: " << tacGia << endl;
    cout << "So luong: " << (int)soLuong << endl;
}

void Sach::muonSach(string sTenSach, string sTacGia, uint8_t uSoLuong){
    cout << "Ten sach muon: " << tenSach << endl;
    cout << "Tac gia: " << tacGia << endl;
    soLuong -= uSoLuong;
    cout << "So luong muon: " << (int)uSoLuong << endl;
} 

void Sach::traSach(string sTenSach, string sTacGia, uint8_t uSoLuong){
    cout << "Ten sach tra: " << tenSach << endl;
    cout << "Tac gia: " << tacGia << endl;
    soLuong += uSoLuong;
    cout << "So luong tra: " << (int)uSoLuong << endl;
} 

int main()
{
    Sach sa("Doraemon", "Fuji", 10);
    sa.muonSach("Doraemon", "Fuji", 5);
    sa.thongTinSach();
    
    // sa.traSach("Doraemon", "Fuji", 2);
    
    // sa.thongTinSach();
    return 0;
}
