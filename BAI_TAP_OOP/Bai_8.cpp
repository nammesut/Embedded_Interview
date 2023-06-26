
/* * Tạo một lớp hình tròn với 
    - bán kính 
    - các phương thức để tính chu vi, diện tích của hình tròn.
*/
#include <iostream>

using namespace std;

class TaiKhoan {
    private:
        string tenTK;
        uint16_t soTK;
        uint32_t soDuTK = 0;
    public:
        TaiKhoan(string sTenTK = "", uint16_t iSoTK = 0);
        void nopTien(uint32_t fSoTienNop);
        void rutTien(uint32_t fSoTienRut);
        void kiemTraSoDu();
};

TaiKhoan::TaiKhoan(string sTenTK, uint16_t iSoTK){
    tenTK = sTenTK;
    soTK = iSoTK;
}

void TaiKhoan::nopTien(uint32_t fSoTienNop){
    cout << "=> Da nap " << fSoTienNop << " vao so TK " << soTK << endl;
    soDuTK += fSoTienNop;
}


void TaiKhoan::kiemTraSoDu(){
    cout << "Thong tin tai khoan:" << endl;
    cout << " - Ten tai khoan: " << tenTK << endl;
    cout << " - So tai khoan: " << soTK << endl;
    cout << " - So du: " << TaiKhoan::soDuTK << " VND" << endl;
}

void TaiKhoan::rutTien(uint32_t fSoTienRut){
    soDuTK -= fSoTienRut;
    cout << "=> Da rut so tien " << fSoTienRut << " VND" << " tu so TK " << soTK << endl;
    cout << "Thong tin tai khoan sau khi rut tien: " << endl;
    cout << " - Ten tai khoan: " << tenTK << endl;
    cout << " - So tai khoan: " << soTK << endl;
    cout << " - So du: " << TaiKhoan::soDuTK << " VND" << endl;
}

int main()
{
    TaiKhoan tk("Nam", 7777);

    tk.nopTien(1500000);
    tk.kiemTraSoDu();

    tk.rutTien(1200000);

    
    return 0;
}
