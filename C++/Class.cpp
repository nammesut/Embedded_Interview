#include <iostream>
#include <string>

using namespace std;

class coso
{
    public:
      virtual void show()
      {
                cout<<"\n  Hien thi lop co so:";
      }
      void display()
      {
              cout<<"\n  Trung bay lop co so:" ;
      }
};
 
class kethua:public coso
{
   public:
      void display()
      {
              cout<<"\n  Trung bay lop ke thua:";
      }
      void show()
      {
              cout<<"\n  Hien thi lop ke thua:";
      }
};

int main()
{
    coso cs;
    cs.display();
    cs.show();

    kethua kt;
    kt.display();
    kt.show();

    return 0;
}
