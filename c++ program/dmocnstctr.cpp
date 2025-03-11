#include<iostream>
class car{
    public:
    car()
    {std::cout<<"hello constructor ";} 
     //explicit constructor once user declear cons. compiler will not make any cons.

};
    int main()
    { 
        car c1;
    }