
/* * Tạo một lớp hình tròn với 
    - bán kính 
    - các phương thức để tính chu vi, diện tích của hình tròn.
*/
#include <iostream>
#include <string>

using namespace std;

class DongVat {
    private:
        string ten;
        int8_t tuoi;
        double trongLuong;
        int8_t chieuCao;
    public:
        DongVat(string sTen, int8_t iTuoi, double dTrongLuong, int8_t dChieuCao);
        double tinhBMI();
        bool soSanhTuoi();
        bool soSanhTrongLuong();
};

DongVat::DongVat(string sTen, int8_t iTuoi, double dTrongLuong, int8_t dChieuCao){
    ten = sTen;
    tuoi = iTuoi;
    trongLuong = dTrongLuong;
    chieuCao = dChieuCao;

    cout << "Thuoc tinh cua " << ten << endl;
    printf("\tTuoi: %d\n", tuoi);
    printf("\tTrong luong: %.1fkg\n", trongLuong);
    printf("\tChieu cao: %dcm\n", chieuCao);
}

double DongVat::tinhBMI(){
    return (trongLuong*703)/(chieuCao*chieuCao);
}

bool DongVat::soSanhTuoi(){
    if()

}

bool DongVat::soSanhTrongLuong(){

}
 
int main()
{
    DongVat dv("Dog", 2, 4, 20);
    cout << "Chi so BMI: " << dv.tinhBMI() << endl;

    DongVat dv1("Meo", 2, 8, 30);
    if()
    
    return 0;
}
