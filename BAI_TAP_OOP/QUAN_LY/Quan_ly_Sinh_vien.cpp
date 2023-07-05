#include <iostream>
#include <string>
#include <list>

using namespace std;

class SinhVien {
    private:
        uint8_t id;
        string ten;
        string gioiTinh;
        uint16_t tuoi;
        float diemToan;
        float diemLy;
        float diemHoa;
        float diemTB;
        string hocLuc;

        list<SinhVien> Database;
    public:
        SinhVien(string TEN = "", string GIOI_TINH = "", uint16_t TUOI = 0, 
                    float TOAN = 0, float LY = 0, float HOA = 0);
        uint8_t getId();
        float getDiemTrungBinh();
        void themThongTin();
        void hienThiDanhSach();
        void xoaSinhVien();
        void hienThi();


};

SinhVien::SinhVien(string TEN, string GIOI_TINH, uint16_t TUOI, float TOAN, float LY, float HOA){
    ten = TEN;
    gioiTinh = GIOI_TINH;
    tuoi = TUOI;
    diemToan = TOAN;
    diemLy = LY;
    diemHoa = HOA;
}

uint8_t SinhVien::getId(){
    static uint8_t ID = 100;
    id = ID;
    ID++;
    return this->id;
}

float SinhVien::getDiemTrungBinh(){
    diemTB = (diemToan + diemLy + diemHoa)/3;
    if(diemTB >= 8)
        hocLuc = "Gioi";
    else if(diemTB >= 6.5)
        hocLuc = "kha";
    else if(diemTB >= 5)
        hocLuc = "Trung binh";
    else    hocLuc = "Yeu";
    return diemTB;
}

void SinhVien::themThongTin(){
    string TEN;
    string GIOITINH;
    uint16_t TUOI;
    float DTOAN;
    float DLY;
    float DHOA;

    cout << "Nhap ten: ";
    cin >> TEN;

    cout << "Nhap gioi tinh: ";
    cin >> GIOITINH;

    cout << "Nhap tuoi: ";
    cin >> TUOI;

    cout << "Nhap diem toan: ";
    cin >> DTOAN;

    cout << "Nhap diem ly: ";
    cin >> DLY;

    cout << "Nhap diem hoa: ";
    cin >> DHOA;

    SinhVien sv(TEN, GIOITINH, TUOI, DTOAN, DLY, DHOA);
    sv.getId();
    sv.getDiemTrungBinh();
    Database.push_back(sv);
}

void SinhVien::hienThiDanhSach(){
	printf("\n%10s\t%12s\t%12s\t%8s\t%8s\t%8s\t%8s\t%8s\t%10s", "ID", "HO TEN", "GIOI TINH", "TUOI", "TOAN", "LY", "HOA", "DTB", "HOC LUC");
	
    for(SinhVien item : Database){
        printf("\n%10d\t%12s\t%8s\t%8d\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%10s", item.id, item.ten.c_str(), item.gioiTinh.c_str(), 
                item.tuoi, item.diemToan, item.diemLy, item.diemHoa, item.diemTB, item.hocLuc.c_str());
    }
}

void SinhVien::xoaSinhVien(){
    int count = 0;
    uint8_t ID;
    list<SinhVien>::iterator it;
    printf("Nhap id: ");
    scanf("%d", &ID);
    printf("%d\n", ID);

    for(it = Database.begin(); it != Database.end(); it++){
        if(it->id == ID){
            Database.erase(it);
            cout << "Da tim thay" << endl;
        }
    }
}

void SinhVien::hienThi(){
    SinhVien sv;
    int x;
    do{
        printf("\n\t\t      CHUONG TRINH QUAN LY SINH VIEN\n\n");
        printf("\t************************* MENU **************************\n");
        printf("\t**  1. Them sinh vien                                  **\n");
        printf("\t**  2. Hien thi danh sach sinh vien                    **\n");
        printf("\t**  0. Thoat chuong trinh                              **\n");
        printf("\t*********************************************************\n");
        printf("Chon mot trong cac lua chon tren: ");
        scanf("%d", &x);
 		switch(x)
 		{
            case 0:
		 		printf("Ban da chon thoat chuong trinh\n");
                break;
 			case 1:
		 		printf("Ban da chon 1. Them sinh vien.\n");
		 		printf("_________________________________________________\n\n");
			 	sv.themThongTin();
 				break;
 			case 2:
 				printf("Ban da chon 2. Hien thi danh sach sinh vien.\n");
		 		sv.hienThiDanhSach();
 				break;
            case 3:
		 		sv.xoaSinhVien();
 				break;
        }
 		if(x == 0)
 			break;
    }while(1);
}
    
int main()
{   
    SinhVien sv;
    sv.hienThi();
    
    
    return 0;
}
