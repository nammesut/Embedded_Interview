
/* * Tạo một lớp hình chữ nhật với các thuộc tính 
    - chiều dài, chiều rộng 
    - và các phương thức tính chu vi, diện tích, đường chéo và kiểm tra xem 
      nó có phải là hình vuông hay không.
*/
#include <iostream>

using namespace std;

class HinhChuNhat {
    private:
        double chieuDai;
        double chieuRong;
    public:
        HinhChuNhat(double dai, double rong);
        double tinhChuVi();
        double tinhDienTich();
        double tinhDuongCheo();
        bool kiemTraHinhVuong();
};

HinhChuNhat::HinhChuNhat(double dai, double rong){
    chieuDai = dai;
    chieuRong = rong;
    cout << "Chieu dai: " << chieuDai << endl;
    cout << "Chieu rong: " << chieuRong << endl;
}

double HinhChuNhat::tinhChuVi(){
    return (chieuDai + chieuRong)*2; 
}

double HinhChuNhat::tinhDienTich(){
    return chieuDai * chieuRong; 
}

double HinhChuNhat::tinhDuongCheo(){
    return (chieuDai*chieuDai) + (chieuRong*chieuRong); 
}

bool HinhChuNhat::kiemTraHinhVuong(){
    if(chieuDai == chieuRong){
        return 1;
    }
    else{
        return 0;
    }
}
 
int main()
{
    HinhChuNhat hcn(4, 4);

    cout << "Dien tich: " << hcn.tinhDienTich() << endl;
    cout << "Chu vi: " << hcn.tinhChuVi() << endl;
    cout << "Duong cheo: " << hcn.tinhDuongCheo() << endl;

    if(hcn.kiemTraHinhVuong() == 1){
        cout << "Day la hinh vuong" << endl;
    }
    else{
        cout << "Day khong la hinh vuong" << endl;
    }
    return 0;
}
