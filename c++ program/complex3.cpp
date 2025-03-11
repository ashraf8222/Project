#include<iostream>
class complex
{
   private:
   int real;
   int img;
   public:
   complex (int i,int j)
   {
      i=real;
      j=img;
   } 
   complex operator+ (complex u)
   {
      complex samp;
      samp.real=real+u.real;
      samp.img=img+u.img;
      return samp;
   }
   void display()
   {
      std::cout<<"real: "<<real;
      std::cout<<"img: "<<img;
   }
};
    int main ()
  {
    complex a(12,44),b(12,34),c;
    c=a+b;
   c.display();
   return 0;
  }