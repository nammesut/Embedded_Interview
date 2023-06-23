
/* * Tạo một lớp hình tròn với 
    - bán kính 
    - các phương thức để tính chu vi, diện tích của hình tròn.
*/
#include <iostream>

#define NAM_HIEN_TAI 2023

using namespace std;

class Nguoi {
    private:
        string ten;
        int16_t namSinh;
        string diaChi;
    public:
        Nguoi(string sTen, int16_t iNamSinh, string sDiaChi);
        void inThongTin();
        int16_t tinhTuoi();
};

Nguoi::Nguoi(string sTen, int16_t iNamSinh, string sDiaChi){
    ten = sTen;
    namSinh = iNamSinh;
    diaChi = sDiaChi;
}

void Nguoi::inThongTin(){
    cout << "Thong tin ly lich" << endl;
    cout << "\tTen: " << ten << endl;
    printf("\tNam sinh: %d\n", namSinh);
    cout << "\tDia chi: " << diaChi << endl;
}

int16_t Nguoi::tinhTuoi(){
    return NAM_HIEN_TAI - namSinh;
}
 
int main()
{
    Nguoi ng("Nguyen Hoang Nam", 2000, "TP. HCM");

    ng.inThongTin();
    cout << "Tuoi: " << ng.tinhTuoi() << endl;
    
    return 0;
}
