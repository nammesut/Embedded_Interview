#include <iostream>
#include <string>
#include <list>

using namespace std;

/*-----------------------------Class Mon-------------------------------------*/
class MonAn {
    private:
        uint8_t id;
        string tenMon;
        uint32_t giaMon;
        void setId();
    public:
        MonAn(string sTenMon, uint32_t dGiaMon);
        uint8_t getId();
        string getTenMon();
        uint32_t getGia();
};

MonAn::MonAn(string sTenMon, uint32_t dGiaMon){
    tenMon = sTenMon;
    giaMon = dGiaMon;
    setId();
}

void MonAn::setId(){
    static uint8_t ID = 100;
    id = ID;
    ID++;
}

uint8_t MonAn::getId(){
    return id;
}

string MonAn::getTenMon(){
    return tenMon;
}

uint32_t MonAn::getGia(){
    return giaMon;
}

/*--------------------------------Class Quan ly----------------------------------*/

class QuanLy {
    private: 
        list<MonAn> Database;
        uint8_t soBan;
        void themMon();
        void suaMon();
        void xoaMon();
        void danhSach();
        void lapSoBan();
    public: 
        QuanLy();
        list<MonAn> getDatabase();
        uint8_t getSoBan();
};

QuanLy::QuanLy(){
    int key = 0;
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
        scanf("%d", &key);
 		switch(key)
 		{
            case 0:
		 		printf("Ban da chon thoat chuong trinh\n");
                break;
 			case 1:
			 	themMon();
 				break;
            case 2:
                suaMon();
                break;
            case 3:
                xoaMon();
                break;
            case 4:
                danhSach();
                break;
            case 5:
                lapSoBan();
                break;
        }
 		if(key == 0)
 			break;
    }while(1);	
}

list<MonAn> QuanLy::getDatabase(){
    return this->Database;
}

uint8_t QuanLy::getSoBan(){
    return this->soBan;
}

void QuanLy::themMon(){
    string TEN_MON;
    uint32_t GIA_MON;

    cout << "Nhap ten mon: ";
    cin >> TEN_MON;
    cout << "Nhap gia: ";
    cin >> GIA_MON;

    MonAn mon(TEN_MON, GIA_MON);
    Database.push_back(mon);
}

void QuanLy::suaMon() {
    int ID, key;
    string TEN_MON;
    uint32_t GIA_MON;

    cout << "Nhap ID can sua mon: ";
    cin >> ID;

    auto position = Database.begin();
    for(auto item : Database) {
        if(item.getId() == ID) {
            do {
            printf("\t***************** MENU *******************\n");
            printf("\t**  1. Sua ten                          **\n");
            printf("\t**  2. Sua gia                          **\n");
            printf("\t**  0. Thoat                            **\n");
            printf("\t******************************************\n");
            printf("Chon mot trong cac lua chon tren: ");
            scanf("%d", &key);
            } while(key != 1 && key != 2 && key != 0);

            switch (key) {
                case 1:
                    cout << "Nhap ten: ";
                    cin >> TEN_MON;
                    break;
                case 2:
                    cout << "Nhap gia: ";
                    cin >> GIA_MON;
                    break;
                default:
                    break;
            }
        }
        position++;
    }
    cout << "Danh sach mon sau khi sua bang ID " << ID << " !" << endl;
    danhSach();
}

void QuanLy::xoaMon() {
    int ID;

    cout << "Nhap ID can xoa mon: ";
    cin >> ID;

    auto position = Database.begin();
    for(auto item : Database) {
        if(item.getId() == ID) {
            cout << "Danh sach mon sau khi xoa bang ID " << ID << " !" << endl;
            Database.erase(position);
        }
        position++;
    }
    danhSach();
}

void QuanLy::danhSach() {
    int stt = 1;

	printf("\n\t%7s\t%7s\t%12s\t%8s","STT", "ID", "TEN MON", "GIA");

    for(MonAn item : Database){
        printf("\n\t%7d\t%7d\t%12s\t%8d", stt++, item.getId(), item.getTenMon().c_str(), item.getGia());
    }
}

void QuanLy::lapSoBan() {
    int SO_BAN;

    cout << "Nhap so ban: ";
    cin >> SO_BAN;
    soBan = SO_BAN;
    cout << "Da thiet lap so ban!" << endl;
}

/*--------------------------------Class Thong tin ban----------------------------------*/

class ThongTinBan {
    private: 
        uint8_t ban;
        bool trangThai;
        typedef struct {
            MonAn mon;
            uint8_t soLuong;
        }typeMon;
        list<typeMon> Database_Mon;
    public:
        ThongTinBan(uint8_t uBan, bool bTrangThai);
        uint8_t getBan();
        bool getTrangThai();
        void themMon(MonAn mMon, uint8_t uSoLuong);
        void suaMon(uint8_t uId, uint8_t uSoLuong);
        void xoaMon(uint8_t uId);
};

ThongTinBan::ThongTinBan(uint8_t uBan, bool bTrangThai) {
    ban = uBan;
    trangThai = bTrangThai;
}

uint8_t ThongTinBan::getBan() {
    return ban;
}

bool ThongTinBan::getTrangThai() {
    return trangThai;
}

void ThongTinBan::themMon(MonAn mMon, uint8_t uSoLuong) {
    int ID;
    string TEN_MON;

    cout << "Nhap ID: ";
    cin >> ID;
    cout << "Nhap ten mon: ";
    cin >> TEN_MON;
    cout << "Nhap so luong: ";
    cin >> uSoLuong;

    for(auto item : QuanLy::getDatabase()) {

    }
}

/*--------------------------------Class Nhan vien----------------------------------*/

class NhanVien {
    private:
        list<MonAn> Database;
        list<ThongTinBan> Database_Ban;
    public:
        NhanVien(list<MonAn> lDatabase, uint8_t uSoBan);
        void hienThiAllBan(uint8_t uSoBan);
};

NhanVien::NhanVien(list<MonAn> lDatabase, uint8_t uSoBan) {
    int SO_BAN;

    Database.assign(lDatabase.begin(), lDatabase.end());
    
    printf("\n\t%7s\t", "So ban");
    for(int i = 1; i <= uSoBan; i++) {
        printf("\t%3d", i);
        ThongTinBan ban(i, false);

        Database_Ban.push_back(ban);
    }

    printf("\n\t%7s\t", "Trang thai");
    for(auto item : Database_Ban) {
        if(item.getTrangThai() == false)
            printf("\t%3c", 'O');
        else
            printf("\t%3c", 'X');
    }

    cout << "Chon ban: ";
    cin >> SO_BAN;



}



/*--------------------------------Main----------------------------------*/

typedef enum {
    QUAN_LY = 1,
    NHAN_VIEN
}tydeMenu;

int main()
{
    int key = 0;
    do{
        printf("\n\n\t\t     QUAN LY NHA HANG\n\n");
        printf("\t***************** MENU *******************\n");
        printf("\t**  1. Quan ly                          **\n");
        printf("\t**  2. Nhan vien                        **\n");
        printf("\t**  0. Thoat                            **\n");
        printf("\t******************************************\n");
        printf("Chon mot trong cac lua chon tren: ");
        scanf("%d", &key);
 		switch((tydeMenu)key) {
            case 0:
		 		printf("Ban da chon thoat chuong trinh\n");
                break;
 			case QUAN_LY:
			 	QuanLy ql;
 				break;
            case NHAN_VIEN:
			 	NhanVien nv(ql.getDatabase(), ql.getSoBan());
 				break;
        }
 		if(key == 0)
 			break;
    }while(1);

    return 0;
}
