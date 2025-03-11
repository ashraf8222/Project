#include<iostream>
class complex {
    public:
    int real;
    int img;
    complex add (complex c)
    {
        complex var1;
        var1.real=real+c.real;
        var1.img=img+c.img;
        return var1;
    }


};
int main ()
{
    complex c1,c2,c3;
    c1.real=10;
    c2.real=5;
    c1.img=3;
    c2.img=8;
    c3=c1.add(c2);
    std::cout<<"enter"<<c3.real<<" "<<c3.img;
}