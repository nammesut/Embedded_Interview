#include <iostream>
#include <math.h>

using namespace std;

class Diem2D {
    private:
        int8_t toaDoX;
        int8_t toaDoY;
    public: 
        Diem2D(int8_t x1, int8_t y1, int8_t x2, int8_t y2);   
        Diem2D(int8_t x1, int8_t y1, int8_t x2, int8_t y2, int8_t x3, int8_t y3);

        void setToaDo(int8_t x, int8_t y);
        int8_t getToaDo();
};

Diem2D::Diem2D(int8_t x1, int8_t y1, int8_t x2, int8_t y2){
    toaDoX = x1;
    toaDoY = y1;
    printf("%d %d\n", toaDoX, toaDoY);
}

int main()
{


    // ptOXY.tinhKhoangCach();
    // ptOXY.tinhDienTich();

    return 0;
}
