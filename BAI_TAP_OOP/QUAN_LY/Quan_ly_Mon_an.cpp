#include <iostream>
#include <string>
#include <list>

using namespace std;

class QuanLyMonAn {
    private:
        uint8_t id;
        string tenMon;
        int gia;
        int soBan;

        list<QuanLyMonAn> databaseQuanLy;
    public:
        QuanLyMonAn(string tenMonAn = "", int giaTien = 0);
        uint8_t getId();
        void hienThiDanhSach();
        void hienThi();

        void manHinhQuanLy();
        void quanLyThemMon();
        void quanLySuaMon(QuanLyMonAn qlm);
        void quanLyXoaMon();
        int thietLapSoBan();

        void manHinhNhanVien();


};

QuanLyMonAn::QuanLyMonAn(string tenMonAn, int giaTien){
    tenMon = tenMonAn;
    gia = giaTien;
}

uint8_t QuanLyMonAn::getId(){
    static uint8_t ID = 100;
    id = ID;
    ID++;
    return this->id;
}

void QuanLyMonAn::hienThiDanhSach(){
    int stt = 1;
	printf("\n\t%7s\t%7s\t%12s\t%8s","STT", "ID", "TEN MON", "GIA");
	
    for(QuanLyMonAn item : databaseQuanLy){
        printf("\n\t%7d\t%7d\t%12s\t%8d", stt++, item.id, item.tenMon.c_str(), item.gia);
    }
}

void QuanLyMonAn::hienThi(){
    QuanLyMonAn qlm;
    int option;
    do{
        printf("\n\n\t\t     QUAN LY NHA HANG\n\n");
        printf("\t***************** MENU *******************\n");
        printf("\t**  1. Quan ly                          **\n");
        printf("\t**  2. Nhan vien                        **\n");
        printf("\t**  0. Thoat                            **\n");
        printf("\t******************************************\n");
        printf("Chon mot trong cac lua chon tren: ");
        scanf("%d", &option);
 		switch(option)
 		{
            case 0:
		 		printf("Ban da chon thoat chuong trinh\n");
                break;
 			case 1:
			 	qlm.manHinhQuanLy();
 				break;
 			case 2:
		 		qlm.manHinhNhanVien();
 				break;
        }
 		if(option == 0)
 			break;
    }while(1);
}

void QuanLyMonAn::manHinhQuanLy(){
    QuanLyMonAn qlm;
    int option;
    
    string tenMonAn;
    int giaTien;
    do{
        printf("\n\n\t\t      MAN HINH QUAN LY\n\n");
        printf("\t******************MENU ******************\n");
        printf("\t**  1. Them mon                        **\n");
        printf("\t**  2. Sua mon                         **\n");
        printf("\t**  3. Xoa mon                         **\n");
        printf("\t**  4. Danh sach mon                   **\n");
        printf("\t**  5. Thiet lap so ban                **\n");
        printf("\t**  0. Quay lai                        **\n");
        printf("\t*****************************************\n");
        printf("Chon mot trong cac lua chon tren: ");
        scanf("%d", &option);
 		switch(option)
 		{
            case 0:
		 		printf("Ban da chon thoat\n");
                break;
 			case 1:
                qlm.quanLyThemMon();
 				break;
            case 2:
			 	qlm.quanLySuaMon(qlm);
 				break;
            case 4:
			 	qlm.hienThiDanhSach();
 				break;
            case 5:
			 	soBan = qlm.thietLapSoBan();
 				break;
        }
 		if(option == 0)
 			break;
    }while(1);
}
    
void QuanLyMonAn::quanLyThemMon(){
    string tenMonAn;
    int giaTien;

    cout << "Nhap tenMon: ";
    cin >> tenMonAn;

    cout << "Nhap gia: ";
    cin >> giaTien;

    QuanLyMonAn qlm(tenMonAn, giaTien);
    qlm.getId();
    databaseQuanLy.push_back(qlm);
}

void QuanLyMonAn::quanLySuaMon(QuanLyMonAn qlm){
    qlm.hienThiDanhSach();
    
    uint8_t ID;
    string tenSuaMon;
    printf("\nNhap id: ");
    scanf("%d", &ID);

    int option;
    do{
        printf("\t************************* MENU **************************\n");
        printf("\t**  1. Sua ten                                         **\n");
        printf("\t**  2. Sua gia                                         **\n");
        printf("\t**  0. Quay lai                                        **\n");
        printf("\t*********************************************************\n");
        printf("Chon mot trong cac lua chon tren: ");
        scanf("%d", &option);
 		switch(option)
 		{
            case 0:
		 		printf("Ban da chon thoat\n");
                break;
 			case 1:
                for(QuanLyMonAn item : databaseQuanLy){
                    if(ID == item.id){
                        cout << "Nhap ten sua: ";
                        cin >> tenSuaMon;
                        item.tenMon = tenSuaMon;
                        break;
                    }
                }
 				break;
            case 4:
                qlm.hienThiDanhSach();
                break;
        }
 		if(option == 0)
 			break;
    }while(1);

}

void QuanLyMonAn::quanLyXoaMon() {
    int ID;

    cout << "Nhap ID can xoa mon: ";
    cin >> ID;

    auto position = databaseQuanLy.begin();
    for(auto item : databaseQuanLy) {
        if(item.id == ID) {
            cout << "Danh sach mon sau khi xoa bang ID " << ID << " !" << endl;
            Database.erase(position);
        }
        position++;
    }
    hienThiDanhSach();
}
    
int QuanLyMonAn::thietLapSoBan(){
    int SOBAN;
    int option;
    cout << "Nhap so ban: ";
    scanf("%d", &SOBAN);

    do{
        printf("\n\t************ MENU *************\n");
        printf("\t**  0. Quay lai                **\n");
        printf("\t*********************************\n");
        printf("Nhan 0 de quay lai! ");
        scanf("%d", &option);
        switch(option){
            case 0:
                break;
        } 
        if(option == 0)
 			break;
    }while(1);
    return SOBAN;
}

void QuanLyMonAn::manHinhNhanVien(){
    printf("\n\t%7s\t","SO BAN");
	for(int i = 1; i <= soBan; i++){
        printf("\t%3d", i);
    }
    
    // printf("\n\t%7d\t%7d\t%12s\t%8d", stt++, item.id, item.tenMon.c_str(), item.gia);
}

int main()
{   
    QuanLyMonAn qlm;
    qlm.hienThi();
    
    
    return 0;
}
