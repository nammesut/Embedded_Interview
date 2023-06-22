
/* * Tạo một lớp hình tròn với 
    - bán kính 
    - các phương thức để tính chu vi, diện tích của hình tròn.
*/
#include <iostream>

#define PI 3.14

using namespace std;

class HinhTron {
    private:
        double banKinh;
    public:
        HinhTron(double R);
        double tinhChuVi();
        double tinhDienTich();
};

HinhTron::HinhTron(double R){
    banKinh = R;
    cout << "Ban kinh hinh tron: " << banKinh << endl;
}

double HinhTron::tinhChuVi(){
    return (2 * banKinh * PI); 
}

double HinhTron::tinhDienTich(){
    return banKinh * banKinh * PI; 
}
 
int main()
{
    HinhTron ht(4);

    cout << "Dien tich: " << ht.tinhDienTich() << endl;
    cout << "Chu vi: " << ht.tinhChuVi() << endl;
    
    return 0;
}
