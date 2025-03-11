#include<iostream>
class sample {
    public:
    int x1,x2;
     int multi ()
      { 
        return x1*x2;
       }
      int add ()
      { 
        return x1+x2; 
        }

};
int main ()
{
    sample a1,a2;
    a1.x1=12;
    a1.x2=14;
    std:: cout<<"the addition: "<<a1.add()<<std::endl;
    std::cout<<"the multiplication: "<<a1.multi();
     return 0;

}