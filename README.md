# Embedded Interview T5
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

Kết quả:

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

Kết quả:

10000000 >> 3 = 00010000 //~(11101111)
PORTA = 11101111 & 00010000 = 00000000
```
## Size of Struct
Ví dụ: Tính kích thước của Struct
```
Chương trình:

struct structData
{
    int a;
    char b;
    
    
}
```
