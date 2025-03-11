#include<iostream>
using namespace std;
int main()
{
    int ar[4],x;
    cout<<"enter naumber";
    for(int i=0;i<=4;i++)
    {
        cin>>ar[i];
    }
    cout<<"enter key for binary search"<<endl;
    cin>>x;
    for(int j=0;j<=4;j++)
    {
        if(ar[j]==x)
        {
        cout<<"key is find at the rank of "<<j;
        return 0;
        }

    }
    cout<<"key not found";


}