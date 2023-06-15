#include <iostream>
#include <string>

using namespace std;

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

int main()
{
    Person ps(20);  // object

    ps.output();
    return 0;
}
