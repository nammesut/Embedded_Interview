# Embedded Interview
<details>
    <summary>Compiler</summary>
Quy trình  biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/cb11786e-5c5d-4242-ad65-aed8faf26c21)
    
1. Giai đoàn tiền xử lý (Pre-processor)
   - Nhận mã nguồn
   - Xóa bỏ tất cả chú thích, comments của chương trình
   - Các chỉ thị #include và #define cũng sẽ được gọi và thay thế vào chương trình.

2. Giai đoạn dịch NNBC sang Asembly (Compiler)
   - Phân tích cú pháp (syntax) của mã nguồn NNBC
   - Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

3. Giai đoạn dịch asembly sang ngôn ngữ máy (Asembler)
   - Dich chương trình => Sang mã máy 0 và 1
   - Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

4. Giai đoạn liên kết (Linker)
   - Liên kết (file .c hoặc file thư viện .lib) lại với nhau để tạo thành chương trình đích duy nhất. Còn gọi là đóng gói.

> Tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.

</details>
<details>
    <summary>Phân vùng nhớ</summary>
 
![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/afd63e5d-7b2b-498a-bc7b-ecaff73d3b60)

- Text:
  - Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction.
  - Chứa khai báo hằng số (biến const) trong chương trình (.rodata)
    
- Data (initialized data):
  - Quyền truy cập là read-write.
  - Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
  - Được giải phóng khi kết thúc chương trình.
    
- bss (uninitialized data):
  - Quyền truy cập là read-write.
  - Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không hoặc không khởi tạo.
  - Được giải phóng khi kết thúc chương trình.
    
- Stack:
  - Quyền truy cập là read-write.
  - Được sử dụng cấp phát cho biến local, input parameter của hàm,…
  - Được giải phóng khi ra khỏi block code/hàm.

- Heap:
  - Quyền truy cập là read-write.
  - Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
  - Được giải phóng khi gọi hàm free,…

</details>
<details>
    <summary>Thao tác bit</summary>

- AND (&): Ngõ ra là 1 nếu 2 bit đều là 1, một trong 2 bit bằng 0 là 0.
- OR (|): Ngõ ra là 1 nếu một trong 2 bit là 1, 2 bit đều bằng 0 là 0.
- XOR (^): Ngõ ra là 1 nếu tổng số bit 1 là lẻ, ngược lại.
- NOT (!): Đảo trạng thái bit 0 -> 1, ngược lại.

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/4d43c5ca-f4f4-4700-a279-1e7864c05fc3) - ![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/1cdce440-aac2-403b-88d7-112b70166af6) - ![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/42e332b2-5f34-4241-8b57-9a0bf21cd331) - ![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/c267b2a8-d145-42b3-8bb4-e20def09c03a) 
- Dịch bit sang phải (>>): Bỏ đi n bit bên phải đồng thời dịch sang phải và thêm n bit 0 bên trái.
- Dịch bit sang trái (<<): Bỏ đi n bit bên trái đồng thời dịch sang trái và thêm n bit 0 bên phải.

Ví dụ: Hiển thị giá trị PORTA dưới dạng nhị phân.
https://github.com/nammesut/Embedded_Interview/blob/e1c9b211326006765745b7dca61a079875b06b6b/ON_TAP/Bit_Operator.c#L4-L16

Ví dụ:
```ruby
uint8_t PORTA = 0b00010000;
PORTA = PORTA | (0b10000000 >> 2); 

Kết quả: 0b00110000
```

Giải thích:
```ruby
10000000 >> 2 = 00100000
PORTA = 00010000 | 00100000 = 00110000
```

### Set, clear, toggle, test 1 bit
- Set 1 bit thứ n lên 1:

```ruby
output |= (1 << n);
```
- Clear 1 bit thứ n về 0:

```ruby
output &= ~(1 << n);
```
- Toggle 1 bit thứ n:

```ruby
output ^= (1 << n);
```
- Test 1 bit là 1 hay 0:

```ruby
output & (1 << n);
```

Ví dụ: Clear bit thứ 3 từ trái sang về 0
```ruby
uint8_t PORTA = 0b00010000;
PORTA = PORTA & ~(0b10000000 >> 3); 

Kết quả: 0b00000000
```

Giải thích:
```ruby
10000000 >> 3 = 00010000 //~(11101111)
PORTA = 11101111 & 00010000 = 00000000
```
</details>

<details>
    <summary>Struct và Union</summary>
        
### Size of Struct
- Cách tính kích thước của một struct:
1. Địa chỉ của struct bắt đầu từ 0.
2. Địa chỉ của một biến bên trong struct luôn chia hết cho kích thước của biến đó.

Ví dụ 1: Tính kích thước của Struct
```ruby
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
```ruby
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
```ruby
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

### Size of Union
Kích thước của 1 union được tính bằng kích thước của member lớn nhất trong nó và các member trong union sẽ dùng chung 1 địa chỉ.

Ví dụ 1:
https://github.com/nammesut/Embedded_Interview/blob/38703243ed84673125d71a9d3612eb018e1cb7e9/ON_TAP/Size_of_Struct_Union.c#L25-L36

Giải thích: 
- Trong Union 1: Kích thước của member lớn nhất trong union là a với 5 phần tử mỗi phần tử 1byte nên size của union trên là 5bytes.
- Trong Union 2: Kích thước của member lớn nhất trong union là char với 17 phần tử mỗi phần tử 1byte là 17bytes nhưng kiểu dữ liệu lớn nhất là double 8bytes nên khi được lưu trên bộ nhớ sẽ được sắp xếp theo kiểu align 8bytes (ví dụ ảnh dưới).

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/70e0e960-33a2-481e-ace7-a80df82c08f4)

</details>

<details>
    <summary>Từ khóa Extern và biến Static</summary>
    
### Extern
- Là tham chiếu của một biến, hàm cùng tên nào đó và đã được định nghĩa bên ngoài.
- Biến được tham chiếu phải được khai báo toàn cục và có thể nằm trong một file khác.

Ví dụ:
- File 1:

```ruby
static int a = 10;
void test(){
    printf("%d\n", a++);
}
```
- File 2:

```ruby
extern void test();

test();
test();

Kết quả: 10 11
```
### Static cục bộ
Biến được khởi tạo 1 lần và tồn tại suốt vòng đời chương trình và giá trị không bị mất đi ngay cả khi kết thúc hàm.

Ví dụ:
```ruby
void test(){
    static int a = 10;
    printf("%d\n", a++);
}

test();
test();
test();

Kết quả: 10 11 12
```

### Static toàn cục
Giống như biến toàn cục nhưng sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không thể truy cập được kể cả dùng từ khóa extern. 

Ví dụ:
```ruby
static int a = 10;

void test(){
    printf("%d\n", a++);
}

test();
test();
test();

Kết quả: 10 11 12
```
</details>
    
<details>
    <summary>Pointer</summary>
    
### Pointer
Giá trị của pointer sẽ là địa chỉ của một biến khác mà nó trỏ đến.

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/e763a28a-4257-4099-a2f3-3a7513df5ca7)

> Nên khai báo pointer và gán nó giá trị NULL hoặc địa chỉ của biến khác.

### Con trỏ hàm
Ví dụ 1:
```ruby
void tong(int a, int b){
    printf("%d\n", a+b);
}

void (*ptr)(int, int) = NULL; 
ptr = &tong;
/* Or: void (*ptr)(int, int) = &tong */

ptr(6, 10);

Kết quả: 16
```

Ví dụ 2: Khai báo con trỏ hàm với input parameter là con trỏ hàm khác
```ruby
void tong(int a, int b){
    printf("%d\n", a+b);
}

void tinhtoan(int a, int b, void (*ptr)(int, int)){
    ptr(a, b);
}

tinhtoan(7, 10, tong);

Kết quả: 17
```
### Con trỏ void
Khác với con trỏ thường chỉ lưu được địa chỉ của biến mà nó trỏ đến cùng kiểu dữ liệu với nó, ví dụ:
```ruby
int a = 10;
int *ptr = &a;
float *p = &a;  //error
```
thì con trỏ void có thể lưu tất cả các địa chỉ có kiểu dữ liệu khác nhau nhưng muốn lấy giá trị tại địa chỉ đó phải ép kiểu dữ liệu về đúng kiểu nó trỏ đến
```ruby
void tong(int a, int b){
    printf("%d\n", a+b);
}

int a = 10;
double b = 1.2;

void *ptr = &a;
printf("%d\n", *(int *)ptr);

ptr = &b;
printf("%f\n", *(double *)ptr);

ptr = &tong;
((void (*)(int, int))ptr)(12, 10);

Kết quả: 10 1.200000 22
```
</details>
