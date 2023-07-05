
/* * Tạo một lớp hình tròn với 
    - bán kính 
    - các phương thức để tính chu vi, diện tích của hình tròn.
*/
#include <iostream>

using namespace std;

class PhanSo {
    protected:
        int8_t tuSo;
        int8_t mauSo;
        double phanso;
    public:
        PhanSo(int8_t iTuSo_1, int8_t iMauSo_1, int8_t iTuSo_2, int8_t iMauSo_2);
        double Tong();
};

PhanSo::PhanSo(int8_t iTuSo_1, int8_t iMauSo_1, int8_t iTuSo_2, int8_t iMauSo_2){
    tuSo = iTuSo_1;
    mauSo = iMauSo;
    phanso = tuSo/mauSo;
    printf("%.1f\n", phanso);
}

double PhanSo::Tong(){
    return ( / p1.mauSo) + ((double)p2.tuSo / p2.mauSo);
}


 
int main()
{
    PhanSo ps1(2, 4);
    PhanSo ps2(5, 4);

    printf("%.1f\n", ps1.Tong());

    
    return 0;
}
