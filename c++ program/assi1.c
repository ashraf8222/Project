#include<stdio.h>
#include<stdlib.h>
struct array {
  int cap;
  int top;
  int *arr;
};
struct array* createarray(int c)
{
    struct array *ptr;
    ptr=(struct array*)malloc(sizeof(struct array));
   ptr->cap=c;
   ptr->top=-1;
   ptr->arr=(int*)malloc(sizeof(int)*ptr->cap);
   return ptr;
   }
   void append (struct array* p,int item)
   {
      if(p->top==p->cap++)
        printf("array is full\n");
        else
        {
            p->top++;
         p->arr[p->top]=item;
        }
   }
   void insert (struct array* p,int item,int index)
   {
     int i;
     if(index<0||index>p->cap+1)
       printf("invalid input\n");
       else
       p->top++;
       for( i=p->top;i>index;i--)
         p->arr[p->top+1]=p->arr[p->top];
         p->arr[i]=item;
   }
   int getvalue(struct array* p,int index)
   {
     if(index<0||index>p->cap+1)
       printf("invalid input\n");
    else
    printf("%d",p->arr[index]);
   }
   void editvalue(struct array*p , int item,int index)
   {
     if(index<0||index>p->cap+1)
       printf("invalid input\n");
       else
       p->arr[index]=item;
   }
   void count(struct array *p)
   {
     printf("%d",p->top+1);
   }
   void empty(struct array*p)
   {
      if(p->top=-1)
        printf("array is empty\n");
        else
        printf("not empty\n");
   }
   void full(struct array*p)
   {
      if(p->top=p->cap++)
      printf("array is full\n");
      else
      printf("array is not full\n");
   }
  void delete(struct array*p,int index)
  {
    int i;
    if(index<0||index>p->cap+1)
       printf("invalid input\n");
    else
     { for(i=p->top;i<=p->cap;i++)
      { p->arr[i--]=p->arr[i]; }
      p->top--; 
      }
  }
  void fee(struct array *p)
  {
    free(p->arr);
    free(p);
  }
  int main ()

  {
    int choice,x,y,z,v,p,u,i;
    struct array *ptr;
    ptr=createarray(4);
    while(1){
     printf("\n1.append value\n2.insert value\n3.get value\n4.edit value\n5.count element\n6.cheak empty\n7.cheak full\n8.delete value\n9.free\n");
     scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                 printf("enter number for append\n");
                 scanf("%d",&x);
                 append(ptr,x);
                 break;
                 case 2:
                 printf("enter number index: or item:\n");
                 scanf("%d\n%d",&z,&y);
                 insert(ptr,y,z);
                 break;
                 case 3:
                 printf("enter index:\n");
                 scanf("%d",&v);
                 getvalue(ptr,v);
                 break;
                 case 4:
                 printf("enter number index: or item:\n");
                 scanf("%d\n%d",&u,&p);
                 insert(ptr,p,u);
                  break;
                case 5:
                count(ptr);
                break;
                case 6:
                empty(ptr);
                break;
                case 7:
                full(ptr);
                break;
                case 8:
                printf("enter inex:");
                scanf("%d",&u);
                delete(ptr,u);
                break;
                case 9:
                free(ptr);
                break;
                return 0;
                default:
               printf("enter valid input");
               break;
                }
     }
  }