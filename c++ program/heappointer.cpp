#include<iostream>
class sample {
    public:
        int var;
        int sel;
        int demo ()
        {
            return var+sel;
        }
        int demo2 ()
        {
            return var-sel;
        }
};
    int main ()
    {
        sample *ptr=new sample; //heap memory without declear class variable
        ptr->var=30;
        ptr->sel=10;
       std::cout <<"the additon: "<<ptr->demo()<<std::endl;
      std::cout <<"the substraction: "<<ptr->demo2()<<std::endl;

    }