#include<iostream>
class complex{
    public:
    int real;
    int img;
    complex operator+ (complex k)
    {
        complex demo;
        demo.real=real+k.real;
        demo.img=img+k.img;
        return demo;
    }
};

      int main()
{
    complex a,b,c;
    std::cout<<"enter 1st real : "<<std::endl;
    std::cin>>a.real;
    std::cout<<"enter 1st imag. : ";
    std::cin>>a.img;
    std::cout<<"enter 2st real : "<<std::endl;
    std::cin>>b.real;
    std::cout<<"enter 2st imag. : ";
    std::cin>>b.img;

    c=a+b;//operator overloading == a.operator+(b);

    std::cout<<"real: "<<c.real<<std::endl;
    std::cout<<"img: "<<c.img;
    return 0;
}