#include<iostream>
class rectangle 
{   public:
    int length;
    int breath;
    int area(){
         return length*breath;
        }
    int pera (){
             return 2*(length+breath);
        }
};
    int main()
    {
        rectangle r1,r2;
        r1.length=12;
        r1.breath=24;
        std:: cout<<r1.area()<<std :: endl;
        std:: cout<<r1.pera()<<std:: endl;
        std::cout<<"enter rectangle length and breath for area and pera ";
        std::cin>>r2.length>>r2.breath;
        std::cout<<"area: "<<r2.area()<<std::endl;
        std::cout<<"pera: "<<r2.pera();
        return 0;

    }
