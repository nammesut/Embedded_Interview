# Embedded Interview
<details>
    <summary>Compiler</summary>
    
### Quy trình biên dịch cơ bản
    
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

### Các vùng nhớ cơ bản

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

### Stack và Heap
- Đều là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
  - Stack: lưu trữ biến cục bộ, tham số truyền vào hàm... Truy cập vào bộ nhớ này rất nhanh
  - Heap: lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi hàm malloc - calloc - realloc.
    
- Kích thước vùng nhớ:
  - Stack: cố định, tùy thuộc vào HĐH, ví dụ HĐH Windows là 1 MB, HĐH Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc HĐH của bạn).
  - Heap: không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
    
- Đặc điểm vùng nhớ:
  - Stack: quản lý bởi HĐH, dữ liệu sẽ tự động hủy khi hàm thực hiện xong.
  - Heap: quản lý bởi coder, dữ liệu sẽ không bị hủy khi hàm thực hiện xong, phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 
 
https://github.com/nammesut/Embedded_Interview/blob/209d825ae2fb2543a650ffca9017156878c1c013/ON_TAP/Phan_vung_nho.c#L1-L12
    
> Bộ nhớ stack là cố định nên không sử dụng lưu trữ quá nhiều sẽ tràn bộ nhớ, vd: hàm đệ quy vô hạn.

> Liên tục cấp phát vùng nhớ Heap mà không giải phóng sẽ bị tràn bộ nhớ or khởi tạo vùng nhớ quá lớn mà Heap không thể lưu được thì sẽ bị lỗi khởi tạo. 

</details>
<details>
    <summary>Macro, Inline, Function</summary>

### Macro
- Không phải là hàm or biến và được xử lý trong bước preprocessor.
- Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó => càng nhiều macro thì khiến chương trình tăng size nhiều hơn.
### Inline
- Inline về cơ bản nó sẽ không tạo ra lời gọi hàm mà chèn trực tiếp mã vào nơi hàm được gọi => tăng size (cụ thể là của file thực thi). 
- Khi được nạp vào ram, mỗi hàm sẽ có địa chỉ nhất định, khi gọi thì cpu sẽ jump tới địa chỉ đó. Viết inline thì compiler sẽ chèn luôn code của hàm đó vào, thay vì chèn địa chỉ, cpu chỉ chạy một mạch làm chương trình chạy nhanh.

Ví dụ: Tạo macro
https://github.com/nammesut/Embedded_Interview/blob/32289c9fc1395c62686a76bbab516c14f951578d/ON_TAP/Macro.c#L3-L27
### Hàm bình thường
Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình Program Counter hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.
    
```ruby
int max(int a, int b){
    return (a>b)?a:b;
}
    
int main(){
    printf("Max a va b: %d\n", max(3, 6));
    return 0;
}
```

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/cad85aed-99c1-48c8-9c14-bca7e5cf9e49)

Như ví dụ trên ảnh là VĐK 8bit, thì khi chương trình chạy 0x00 sẽ tạo ra PC có nhiệm vụ đếm chương trình lên 1bit đến 0x07 sẽ quay lại do có hàm while(1). Còn khi chương trình đang chạy tới 0x03 gặp 1 hàm có địa chỉ 0xc1, chương trình sẽ chạy hết 0x03 đồng thời Stack pointer sẽ lưu địa chỉ 0x04 và PC sẽ nhảy đến địa chỉ hàm 0xc1, đếm đến hết 0xc7 sẽ truy cập vào satck pointer lấy địa chỉ 0x04 gán cho PC và đếm từ 0x04 đến 0x07.
</details>

<details>
    <summary>Thao tác bit</summary>

### Các phép toán bit
    
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

### So sánh Struct và Union
| Giống nhau  | Khác nhau |
| ------------- | ------------- |
| Kiểu dữ liệu do người dùng tự định nghĩa | - struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding) - Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác|
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
    
### Con trỏ NULL
- Giá trị của pointer sẽ là địa chỉ của một biến khác mà nó trỏ đến.

![image](https://github.com/nammesut/Embedded_Interview/assets/133733103/e763a28a-4257-4099-a2f3-3a7513df5ca7)

- Null là một giá trị đặc biệt, điều đó có nghĩa là con trỏ đó chưa trỏ đến địa chỉ nào cả.
    
```ruby
int *ptr = NULL;
```

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
    
### Pointer to pointer
Pointer to pointer là một loại con trỏ dùng để lưu trữ địa chỉ của biến con trỏ.
    
https://github.com/nammesut/Embedded_Interview/blob/67e94c45c5a57d27f6937951e9b1b63226c22dbe/ON_TAP/Pointer.c#L34-L40
</details>

</details>
    
<details>
    <summary>C++: Class</summary>
        <details>
            <summary>Khái niệm</summary>
        
### Khái niệm
- `Class` thực chất là một `kiểu dữ liệu do người dùng định nghĩa`.
- Class hay lớp là một mô tả trừu tượng (abstract) của nhóm các `đối tượng (object)` có cùng bản chất.
- Một class trong C++ sẽ có các đặc điểm sau:
  
  - Các `thành phần dữ liệu` (thuộc tính hay `property`).
  - Các `phương thức` (hàm thành phần hay `method`).

Ví dụ 1: Khai báo 1 class cơ bản
```ruby
class Person { 
    public: 
        string firstName; // property 
        string lastName;  // property 
        int age;          // property 

        void fullname() { // method 
            cout << firstName << ' ' << lastName; 
        } 
};

Person person;    //object

person.firstName = "Nam"; 
person.lastName = "Nguyen";
 
person.fullname();
```
</details>

<details>
    <summary>Method declaration (Định nghĩa phương thức)</summary>
    
### Định nghĩa phương thức
Có `2` cách định nghĩa thi hành: 
1. Định nghĩa thi hành `trong lúc định nghĩa class`
```ruby
class Person { 
    public: 
        string firstName; // property 
        string lastName;  // property  

        void fullname() { // method 
            cout << firstName << ' ' << lastName; 
        } 
};
```
2. Định nghĩa thi hành `bên ngoài class`
```ruby
class Person { 
    public: 
        string firstName; // property 
        string lastName;  // property 

        void fullname(); // method
};

void Person::fullname(){
    cout << firstName << ' ' << lastName; 
}
```
> Đối với method nên triển khai theo cách thứ 2 để dễ quản lý source.
</details>

<details>
    <summary>Access modifiers (Phạm vi truy cập)</summary>
    
### Phạm vi truy cập
Có `3` phạm vi truy cập trong C++ là `public`, `private` và `protected`.
- `Public`: Các thuộc tính và phương thức thuộc public `đều có thể được truy cập trực tiếp` thông qua `object của class đó` hoặc `class kế thừa`
```ruby
class Person { 
    public: 
        string firstName; // property 
        string lastName;  // property 
        int age;          // property 

        void fullname() { // method 
            cout << firstName << ' ' << lastName; 
        } 
};

Person person;    //object

person.firstName = "Nam"; 
person.lastName = "Nguyen";
 
person.fullname();
```
- `Private`: Các member thuộc private của `class nào` thì `chỉ có class đó mới truy cập` được, `class kế thừa cũng không thể truy cập`.
- Được `sử dụng khi không muốn gán giá trị từ người dùng`.
```ruby
class Person { 
    public:  
        int age;          // property 
        void fullname(); // method
    private:
        string firstName; // property 
        string lastName;  // property
};

void Person::fullname(){
    firstName = "Nam";
    lastName = "Nguyen";

    cout << firstName << ' ' << lastName; 
} 
```

```ruby
class Person { 
    public:  
        void ages(int age);     // method
    private:
        int age;                // property 
};

void Person::ages(int age){
    Person::age = age;
    cout << age; 
}

Person ps;  // object

ps.ages(18);
```
- `Protected`: các phương thức và thuộc tính `chỉ có thể truy cập` qua các `class kế thừa` nó hoặc `chính nó`.
```ruby
class Person { 
    public:  
        void output(int ages);       // method
    protected:
        int age;           // property 
};

/* Truy cập age từ class chính nó */
void Person::output(int ages){
    age = ages;
    cout << age << endl;
}

/* Truy cập age qua class kế thừa */
class Chill : public Person{
    public:
        void out(int ages);
};

void Chill::out(int ages){
    age = ages;
    cout << age << endl;
}

Person ps;  // object
ps.output(20);
ps.age = 20;    // error vì age thuộc protected nên chỉ truy cập qua class kế thừa hoặc chính nó

Chill boy;
boy.out(12);
```
</details>

<details>
    <summary>Constructor</summary>
    
### Constructor
`Constructor` hay hàm có `tên trùng` với tên của class đó,  nó sẽ `được gọi ngay` khi `khởi tạo một object`. 

`Constructor` được viết trong phạm vi `public` và có thể `có input para`, `không input para` hoặc `input para mặc định`

Ví dụ Constructor `có input para`
```ruby
class Person { 
    public:  
        Person(int age);     // constructor có input para
        void output();       // method
    private:
        int age;           // property 
};

Person::Person(int age){    // Khởi tạo constructor
    Person::age = age; 
} 

void Person::output(){
    cout << age;
}

Person ps(18);  // object

ps.output();
```
Ví dụ Constructor `không input para`
```ruby
class Person { 
    public:  
        Person();     // constructor ko input para
        void output();       // method
    private:
        int age;           // property 
};

Person::Person(){    // Khởi tạo constructor
    Person::age = 18; 
} 

void Person::output(){
    cout << age;
}

Person ps;  // object

ps.output();
```
Ví dụ Constructor `input para mặc định`
```ruby
class Person { 
    public:  
        Person(int age = 18);     // constructor có input para mặc định
        void output();       // method
    private:
        int age;           // property 
};

Person::Person(int age){    // Khởi tạo constructor
    Person::age = age; 
} 

void Person::output(){
    cout << age;
}

Person ps(20);  // Hiển thị 20
// Person ps;  // Hiển thị mặc định là 18

ps.output();
```
</details>

<details>
    <summary>Overloading (Nạp chồng) và Overriding (Ghi đè)</summary>
    
### Overloading (Nạp chồng)
Cho phép trong `cùng một class` có thể có `nhiều phương thức cùng tên` nhưng `khác nhau về số lượng tham số` hoặc `kiểu dữ liệu`.
```ruby
class ToanHoc{
    public:
        void Tong(int a, int b){
            cout << "Tong: " << (a+b) << endl;
        }

        void Tong(int a, int b, int c){
            cout << "Tong: " << (a+b+c) << endl;
        }
};

ToanHoc th;
th.Tong(2, 4);       // = 6
th.Tong(2, 4, 5);    // = 11
```
Như ví dụ trên `hàm Tong` dùng để cộng hai số nguyên. Khi muốn cộng ba số nguyên không lại phải viết một hàm với tên khác (chẳng hạn Tong1) và truyền vào 3 số nguyên hay sao? Như vậy thì code sẽ trở nên phức tạp hơn trong khi hai hàm có cùng một mục đích là cộng các số nguyên lại với nhau. `Khi gọi hàm Tong` và truyền vào `số lượng tham số khác nhau` thì sẽ gọi tới `hàm có số lượng tham số tương ứng`.

### Overriding (Ghi đè)
Được sử dụng trong trường hợp `lớp con kế thừa từ lớp cha` và `muốn định nghĩa lại` một phương thức đã có mặt ở lớp cha, tuy nhiên phương thức ở lớp cha có thể phù hợp với lớp con này nhưng không phù hợp với lớp con khác, do đó lớp con cần ghi đè lại phương thức đó cho phù hợp.
```ruby
class Animal{
    public:
        void animalSound(){
            cout << "Sound" << endl;
        }   
};

class Dog : public Animal{
    public:
        void animalSound(){
            cout << "Gau gau" << endl;
        }
};

class Cat : public Animal{
    public:
        void animalSound(){
            cout << "Meo meo" << endl;
        }
};

Animal animal;
animal.animalSound();

Dog dog;
dog.animalSound();

Cat cat;
cat.animalSound();
```
Như ví dụ class Animal có phương thức animalSound đại diện cho tiếng kêu của động vật. Class Dog và Cat kế thừa từ class Animal, nhưng chó và mèo có tiếng kêu khác nhau nên phải implement phương thức animalSound cho mỗi lớp khác nhau.

### So sánh Overloading và Overriding
| Overloading  | Overriding |
| ------------ | -----------|
| `Thêm` hành vi cho phương thức  | `Thay đổi` hành vi hiện tại của phương thức  |
| `Có thể khác nhau` về số lượng và kiểu dữ liệu của tham số  | Số lượng và kiểu dữ liệu của tham số `phải giống nhau`  |
| Xảy ra trong `cùng một class` | Xảy ra `ở 2 class có quan hệ kế thừa` |

</details>
    
<details>
    <summary>OOP</summary>
    
### Đặc tính của OOP
Có `4 đặc tính` quan trọng trong OOP:

### `Inheritance (Tính kế thừa)`
- Một class `có thể kế thừa các thuộc tính` của một class khác đã tồn tại trước đó.
- Các kiểu kế thừa: `kế thừa public`, `kế thừa private` và `kế thừa protected`.
- Class con kế thừa thuộc tính của class cha thì class con gọi là `subclass`, và class cha là `superclass`.
```ruby
class Animal{
    public:
        void animalSound(){
            cout << "Sound" << endl;
        }   
};

class Dog : public Animal{
    public:
        void animalSound(){
            cout << "Gau gau" << endl;
        }
};

class Cat : public Animal{
    public:
        void animalSound(){
            cout << "Meo meo" << endl;
        }
};

Animal animal;
animal.animalSound();

Dog dog;
dog.animalSound();

Cat cat;
cat.animalSound();
```
### `Polymorphism (Tính đa hình)` 
- Là một khả năng làm cho một phương thức trong class `có thể đưa ra các kết quả hoàn toàn khác nhau`, tùy thuộc vào dữ liệu được xử lý.
- `Kiểu trả về` hoặc `input para` `có thể khác nhau`.
- `Tính đa hình` có thể được hiểu như `Overloading` và `Overriding`.
```ruby
class ToanHoc{
    public:
        void Tong(int a, int b);
        void Tong(int a, int b, int c);
        double Tong(int a, double b);
};

void ToanHoc::Tong(int a, int b){
    cout << "Tong: " << (a+b) << endl;
}

void ToanHoc::Tong(int a, int b, int c){
    cout << "Tong: " << (a+b+c) << endl;
}

double ToanHoc::Tong(int a, double b){
    return (double)a + b;
}

ToanHoc th;
th.Tong(2, 4);       // = 6
th.Tong(2, 4, 5);    // = 11
cout << "Tong: " << th.Tong(12, 3.5) << endl;
```
```ruby
class ToanHoc{
    public:
        void Sosanh2So(int a, int b);
        void Sosanh2So(double a, double b);
};

void ToanHoc::Sosanh2So(int a, int b){
    cout << "Hai so nguyen" << endl;
}

void ToanHoc::Sosanh2So(double a, double b){
    cout << "Hai so thuc" << endl;
}

ToanHoc th;
th.Sosanh2So(1, 2);
th.Sosanh2So(3.3, 5.3);
```
### `Abstraction (Tính trừu tượng)` 
- Là một khả năng mà chương trình `có thể bỏ qua sự phức tạp` bằng cách `tập trung vào cốt lõi của thông tin cần xử lý`.
- `Gọi tên một phương thức` và `thu về kết quả xử lý`, mà `không cần biết làm cách nào` đối tượng đó thao tác trong class. 
```ruby
class ToanHoc{
    public:
        void Nhap(int x, int y);
        void Xuat();
    private:
        int tong(int a, int b);
};
```
Như chương trình tính `tổng a và b` thì người dùng `chỉ cần nhập vào a b` và `kết quả trả về`, còn chương trình `tính toán bên trong chỉ có coder` mới có thể sửa.
### `Encapsulation (Tính đóng gói)` 
- `Không cho phép` người sử dụng các đối tượng `thay đổi trạng thái bên trong một đối tượng`, mà `chỉ có phương thức của đối tượng có thể thay đổi chính nó`.
- `Hai thuộc tính quan trọng` của tính đóng gói:
  -  `Data protection`: giữ các member dữ liệu của nó ở `private` or `protected` `tùy vào tính năng` sử dụng, `quyền truy cập và sửa đổi` các member này `bị hạn chế` để đảm bảo thao tác dữ liệu được `an toàn và bảo mật`.
  -  `Information Hiding`: `ẩn các triển khai nội bộ` với bên ngoài, `chỉ class chứa nó mới truy cập được`.
- `Dữ liệu và thông tin` sẽ được `đóng gói` lại, giúp các tác động bên ngoài một đối tượng `không thể làm thay đổi đối tượng` đó, nên sẽ `đảm bảo tính toàn 
vẹn` của đối tượng, cũng như `giúp dấu đi các dữ liệu` thông tin cần được che giấu.
```ruby
class ToanHoc{
    public:
        void set(int x, int y);
        void get();
    private:
        int a;
        int b;
};

void ToanHoc::set(int x, int y){
    a = x;
    b = y;
}

void ToanHoc::get(){
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

ToanHoc th;
th.set(12, 5);
th.get();
```
</details>
<details>
    <summary>Static, Template và Namespace</summary>

### Static
- Là biến thành viên ở `dạng tĩnh` và `tồn tại duy nhất` trong class.
- Do nó ở `dạng tĩnh` nên có thể `sử dụng trực tiếp` nó mà `không cần phải tạo đối tượng` từ class.

> Static ở dạng tĩnh nên `phải được khởi tạo lần đầu` để lưu địa chỉ cố định.

```ruby
class Person { 
    public:  
        void output(int ages);       // method
        static int age;           // property 
};

int Person::age;   // Khởi tạo static
//int Person::age = 18;    // Có thể khởi tạo và gán value

void Person::output(int ages){
    age = ages;
    cout << age << endl;
}

Person ps;  // object
ps.output(20);
```
- `Được sử dụng chung` cho tất cả các đối tượng được tạo ra từ class.
```ruby
class Person { 
    public:  
        static int age;           // property 
};

int Person::age;    // Khởi tạo static

Person ps1, ps2;  // object
ps1.age = 20;
ps2.age = 18;
cout << ps1.age << endl;
```
Khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng `static thì chỉ có một` và nói ngắn gọn là `dùng chung một biến static`. 
### Template
- Template (khuôn mẫu) là một từ khóa trong C++, và là một `kiểu dữ liệu trừu tượng` tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- Có `2` loại đó là `function template` và `class template`.
- Template giúp `định nghĩa tổng quát` cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.
```ruby
template <typename var1, typename var2>

var1 tong(var1 a, var2 b){
    return (var1)(a + b);
}

cout << "Tong: " << tong(12.5, 5) << endl;
```
### Namespace
- Namespace được sử dụng để `định nghĩa một phạm vi` nhằm mục đích `phân biệt` các hàm, lớp, biến, ... `cùng tên trong các thư viện khác nhau`. 
- `Member` trong 1 namespace có thể là `class, struct, ...`
- `Các member` trong namespace `phải khác tên nhau`, member trong `namespace A` có thể `trùng member` trong `namespace B`.
```ruby
namespace MemA {
    int a = 10;
    class Test{
        public:
            int x = 30;
    };
}

namespace MemB {
    int a = 20;
}

cout << MemA::a << endl;

MemA::Test m;
cout << m.x << endl;
```
Nếu như trong chương trình `chỉ khai báo 1 namespace` thôi thì có thể sử dụng `using namespace` để không phải gọi dài dòng như vd trên mà chương trình vẫn hiểu.
```ruby
namespace MemA {
    int a = 10;
    class Test{
        public:
            int x = 30;
    };
}

namespace MemB {
    int a = 20;
}

using namespace MemA;
using namespace MemB;    // error: khi in biến a sẽ không biết là của MemA hay MemB

cout << a << endl;

Test m;
cout << m.x << endl;
```
</details>

<details>
    <summary>Hàm ảo</summary>
    
### Giải thích
Hàm ảo là một cơ chế đặc biệt trong c++, khi 1 class cha (cơ sở) có 1 method và 1 class con (kế thừa) kế thừa class cha đó, nếu ở class con định nghĩa lại và chỉnh sửa method đó (được gọi là ghi đè) đồng thời ở class cha có 1 method liên quan đến class con tức là khi gọi 1 method khác của class cha và trong đó có lấy thông tin của class con đã định nghĩa lại thì sử dụng virtual, hàm ảo sẽ cho phép khi 1 object truy xuất đến member mà kế thừa từ class cha thì sẽ được overload load lại lấy method mới nhất của class con. Hiểu đơn giản, Virtual sẽ kiểm tra xem method ở class con có được ghi đè hay không, nếu có thì lấy method này không thì lấy ở class cha.
```ruby
class ToanHoc{
    public:
        virtual char *test(){
            return (char*)"Hello";
        }
        void display(){
            cout << test() << endl;
        }
};

class kethua : public ToanHoc {
    public:
        char *test(){
            return (char*)"New change";
        }
};

ToanHoc th;
th.display();

kethua kt;
kt.display();
```
</details>
</details>

<details>
    <summary>C++: Vector và List</summary>
        <details>
            <summary>Vector</summary>
            
### Vector
- Vector trong C++ là `một đối tượng` dùng `để chứa các đối tượng khác`, và các đối tượng được chứa này cũng `được lưu trữ một cách liên tiếp` trong vector.
- Cũng là `mảng (array)`, bản thân vetor `cũng sử dụng cấp phát động` để cấp phát và do vector có thư viện có sẵn nên có thể dễ dàng sử dụng.
- Nó hoàn toàn `có thể thay đổi size` trong `suốt quá trình làm việc` của chương trình.
> Nếu `vector không được sử dụng phải thu hồi vùng nhớ`.
### Modifiers
- `push_back()`: Hàm `thêm một phần tử` vào `vị trí sau cùng`. Nếu `kiểu truyền vào không giống` với kiểu của vector thì sẽ `bị ném ra`.
- `pop_back()`: Hàm `xóa phần tử cuối cùng`.
- `clear()`: Hàm `loại bỏ tất cả các phần tử` của vùng chứa vector. 
```ruby
vector<int> array;

array.push_back(2);
array.push_back(4);

for(int i = 0; i<array.size();i++){
    printf("%d\n", array[i]);
}
```
- `begin()`: Hàm lấy `địa chỉ đầu tiên` của mảng vector.
- `insert(i, value)`: Hàm `chèn phần tử mới` vào `vị trí i`. Có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
```ruby
array.push_back(2);
array.push_back(4);
array.insert(array.begin() + 1, 77);
```
- `assign()`: `gán giá trị mới` cho các phần tử vector bằng cách `thay thế các giá trị cũ`. 
</details>
</details>
