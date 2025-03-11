#include<stdio.h>
#include<stdlib.h>
struct dynarray{
    int capacity;
    int lastindex;
     int *ptr;
};
struct dynarray* createarrayd(int c)
{
  struct dynarray *ptr;
  ptr=(struct dynarray*)malloc(sizeof(struct dynarray));
  ptr->capacity=c;
  ptr->lastindex=-1;
  ptr->ptr=(int*)malloc(sizeof(int)*c);
  return ptr;
}
void append (struct dynarray *p,int item)
{
  if(p->lastindex==-1)
   printf("array empty");
   else 
  p->lastindex++;
  p->ptr[p->lastindex]=item;
}
void insert(struct dynarray *p,int index,int item)
{
    int i;
    if(p->lastindex==-1)
    printf("array is empty");
    else
   for( i=p->lastindex;i>index;i--)
      p->ptr[i+1]=p->ptr[i];
      p->ptr[index]=item;
      p->lastindex++;
}
void getvalue(struct dynarray *p,int index)
{
    if(p->lastindex==-1)
       printf("array empty");
    else
    printf("\n%d",p->ptr[index]);
}
void editvalue(struct dynarray *p,int index,int item)
{
    if(p->lastindex==-1)
    printf("array is empty");
    else
    p->ptr[index]=item;
}
void count(struct dynarray *p)
{   
    if(p->lastindex==-1)
    printf("null");
    else
    printf("%d",p->lastindex);
}
void empty(struct dynarray *p)
{
    if(p->lastindex==-1)
    printf("empty");
    else
    printf("Not empty");
}
void full(struct dynarray *p)
{
    if(p->lastindex==p->capacity+1)
    printf("full");
    else
    printf("Not full");
}
void delete(struct dynarray *p,int index)
{
    int i;
    if(p->lastindex==-1)
      printf("empty");
    else 
    for(i=index;i>p->lastindex;i++)
       p->ptr[i]=p->ptr[i+1];
    p->lastindex--;
}
void release(struct dynarray *p)
{
    free(p->ptr);
    free(p);
}
void doubblearray(struct dynarray *p)
{
    if(p->lastindex!=p->capacity+1)
    printf("array is not full");
    else
    p->lastindex=p->lastindex*2;
    p->ptr[p->lastindex];
}
void halfarray(struct dynarray *p)
{
    int i;
    i=p->lastindex/2;
   if(i!=p->capacity+1)
     printf("Not required");
   else
    p->lastindex=p->lastindex/2;
}



