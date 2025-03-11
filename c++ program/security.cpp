#include <iostream>
class security {
        int var1,var2;
        public:
    void get1 (int i)
    {
        i=var1;
    }
    void get2 (int j)
    {
        j=var2;
    }
    int samp ()
    {
        if(var1%2==0)
        return 2;
        else 
        return 1;
    }
    int samp2 ()
    {
        if(var2%2==0)
        return 2;
        else 
        return 1;
    }
    int cheak1 ()
    {
        return var1;
    }
  int cheak2 ()
  {
    return var2;
  }

};
    int main ()
    {
      security a,b;
      a.get1(10);
      a.get2(5);
      std::cout<<"the firts number is: "<<a.samp()<<std::endl;
      std::cout<<"second number is: "<<a.samp2()<<std::endl;
      std::cout<< "number 1: "<<a.cheak1()<<std::endl;
      std::cout<< "number 2: "<<a.cheak2()<<std::endl;


    }