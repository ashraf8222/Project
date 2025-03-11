#include<iostream>
class rectangle {
    public:
    int length;
    int breath;
    int area ()
    {
        return length*breath;
    }
    int pera ()
    {
        return 2*(length+breath);
    }

};
 int main()
 {   
    rectangle r1;
    rectangle *ptr;
    ptr=&r1;
    ptr->length=10;
    ptr->breath=20;
    std::cout<<"area: "<<ptr->area()<<std::endl;
    std::cout<<"pera: "<<ptr->pera();
    return 0;
 }
