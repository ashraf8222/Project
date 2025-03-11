#include <iostream>
//#include<string>
int main()
{
  int month=0,n,i;
  int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
  const char* b[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
  //char* b[]={"jan","fab","mar","apr","may","june","july","aug","sept","oct","nov","december"};
  std::cout<<"enter nummber";
  std::cin>>n;
  if(n<=365)
    { for( i=0;n>a[i];i++)
    n-=a[i]; 
    std::cout<<"Month:"<<b[i]<<"\nDay:"<<n;
    }
    else 
    std::cout<<"invalid input";
    return 0;
}