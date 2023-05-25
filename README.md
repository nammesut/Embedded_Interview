# Embedded Interview
## Thao tác Bit
- AND (&): Ngõ ra là 1 nếu 2 bit đều là 1, một trong 2 bit bằng 0 là 0.
- OR (|): Ngõ ra là 1 nếu một trong 2 bit là 1, 2 bit đều bằng 0 là 0.
- XOR (^): Ngõ ra là 1 nếu tổng số bit 1 là lẻ, ngược lại.
- NOT (!): Đảo trạng thái bit 0 -> 1, ngược lại.

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/4d43c5ca-f4f4-4700-a279-1e7864c05fc3) - ![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/1cdce440-aac2-403b-88d7-112b70166af6) - ![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/42e332b2-5f34-4241-8b57-9a0bf21cd331) - ![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/c267b2a8-d145-42b3-8bb4-e20def09c03a) 
- Dịch bit sang phải (>>): Bỏ đi n bit bên phải đồng thời dịch sang phải và thêm n bit 0 bên trái.
- Dịch bit sang trái (<<): Bỏ đi n bit bên trái đồng thời dịch sang trái và thêm n bit 0 bên phải.

Ví dụ:
```
Chương trình:

uint8_t PORTA = 0b00010000;
PORTA = PORTA | (0b10000000 >> 2); 

Kết quả: 0b00110000
```

Giải thích:
```
10000000 >> 2 = 00100000
PORTA = 00010000 | 00100000 = 00110000
```

## Set, clear, toggle, test 1 bit
- Set 1 bit thứ n lên 1:

```
output |= (1 << n);
```
- Clear 1 bit thứ n về 0:

```
output &= ~(1 << n);
```
- Toggle 1 bit thứ n:

```
output ^= (1 << n);
```
- Test 1 bit là 1 hay 0:

```
output & (1 << n);
```

Ví dụ: Clear bit thứ 3 từ trái sang về 0
```
Chương trình:

uint8_t PORTA = 0b00010000;
PORTA = PORTA & ~(0b10000000 >> 3); 

Kết quả: 0b00000000
```

Giải thích:
```
10000000 >> 3 = 00010000 //~(11101111)
PORTA = 11101111 & 00010000 = 00000000
```
## Size of Struct
- Cách tính kích thước của một struct:
1. Địa chỉ của struct bắt đầu từ 0.
2. Địa chỉ của một biến bên trong struct luôn chia hết cho kích thước của biến đó.

Ví dụ 1: Tính kích thước của Struct
```
Chương trình:

struct sizeofStruct
{
    char a;
    int b;
    double c;
}str;

printf("%lu \n", sizeof(str));

Kết quả: 16
```

Giải thích:

- Trong struct trên kiểu dữ liệu cao nhất là double có 8bytes nên dữ liệu sẽ được lưu theo kiểu align 8bytes.
- Biến a là biến đầu nên có địa chỉ là 0.

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/ecef806a-af14-4b34-9e45-c80f2b955d62)

- Biến b phải chia hết cho 4 và có địa chỉ là 4.

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/241f9883-5ac6-4fa2-9afb-a4959d6b342e)

- Biến c phải chia hết cho 8 và có địa chỉ là 8.

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/165806ca-8b12-4bf7-a6e9-36279ec3c522)

Ví dụ 2: Tính kích thước của struct gồm mảng các phần tử
```
Chương trình:

struct sizeofStruct
{
    uint32_t a[3];
    uint8_t b[4];
    uint16_t c[2];
}str;

printf("%lu \n", sizeof(str));

Kết quả: 20
```

Giải thích:

- Trong struct trên kiểu dữ liệu cao nhất là uint32_t có 4byte nên dữ liệu sẽ được lưu theo kiểu align 4bytes.
- Kích thước của phần tử a là 12bytes:

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/a9aa7aee-ef4e-42d1-9169-ba4bcd0af062)

- Kích thước của phần tử b là 4bytes:

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/d9e2d3bc-ad58-4a88-9925-388f9262093d)

- Kích thước của phần tử c là 4bytes:

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/b45dad27-2f5f-4adc-849d-994e75ce9fd0)

Ví dụ 3:
```
Chương trình:

struct sizeofStruct
{
    uint8_t a[3];
    uint32_t b[2];
    uint16_t c[2];
}str;

printf("%lu \n", sizeof(str));

Kết quả: 16
```

Giải thích:

- Trong struct trên kiểu dữ liệu cao nhất là uint32_t có 4byte nên dữ liệu sẽ được lưu theo kiểu align 4bytes.
- Kích thước của phần tử a là 4bytes và dư 1 ô nhớ đệm:

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/cb1e9202-b9a8-430b-814c-5806f9dbe7b9)

- Lần quét thứ 1 còn dư 1 ô nhớ mà kiểu dữ liệu được lưu là kiểu align 4bytes không đủ nên thực hiện quét lần 2 và kích thước của phần tử b là 8bytes:

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/f20ef582-c8e3-4dfe-b114-afe089e56373)

- Kích thước của phần tử c là 4bytes:

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/11a6d444-07ee-44d1-863e-a43848c9d814)

## Union
### Size of Union
Kích thước của 1 union được tính bằng kích thước của member lớn nhất trong nó và các member trong union sẽ dùng chung 1 địa chỉ.

Ví dụ 1:
```
Chương trình:

union sizeofUnion
{
    uint8_t a[5];
    uint8_t b[3];
}uni;

printf("%lu \n", sizeof(uni));

Kết quả: 5
```

Giải thích: Kích thước của member lớn nhất trong union là a với 5 phần tử mỗi phần tử 1byte nên size của union trên là 5bytes.

Ví dụ 2:
```
Chương trình:

union sizeofUnion
{
    uint32_t a;
    uint8_t b[17];
    uint64_t c;
}uni;

printf("%lu \n", sizeof(uni));

Kết quả: 24
```

Giải thích: Kích thước của member lớn nhất trong union là char với 17 phần tử mỗi phần tử 1byte là 17bytes nhưng kiểu dữ liệu lớn nhất là double 8bytes nên khi được lưu trên bộ nhớ sẽ được sắp xếp theo kiểu align 8bytes (ví dụ ảnh dưới).

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/70e0e960-33a2-481e-ace7-a80df82c08f4)




