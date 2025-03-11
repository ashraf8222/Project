#include"assi1.c"
void shor(struct array *p){
    int i,j,k,temp=0;
   if(p->top==-1)
    printf("stack empty");
    else
    i=p->top;
    for(j=0;j<i;j++)
     { for(k=0;k<p->cap;k++)
       {   
          if(p->arr[k]>p->arr[k+1])
          { temp=p->arr[k];
          p->arr[k]=p->arr[k+1];
          p->arr[k+1]=temp; }
       }
     }
}
void great(struct array *p)
{ 
    int i,j,k=0;
   if(p->top==-1)
    printf("stack empty");
    else
    for(int j=0;j<p->cap;j++)
    {
        for (int l=j+1;l<p->cap;l++){
            if (p->arr[j]<p->arr[l]){
                k=l;
            }
        }
    }
    printf("max: %d",p->arr[k]);
}
void small(struct array *p)
{
    int i,j,k=0;
   if(p->top==-1)
    printf("stack empty");
    else
    for(int j=0;j<p->cap;j++)
    {
        for (int l=j+1;l<p->cap;l++){
            if (p->arr[j]>p->arr[l]||p->arr[k]>p->arr[j]){
                k=l;
            }
        }
    }
    printf("minimum: %d",p->arr[k]);
}
void search(struct array *p,int item)
{
    int i,j,k;
   if(p->top==-1)
    printf("stack empty");
    else
    i=p->top;
    for(int j=0;j<p->top;j++)
    {
        if(p->arr[j]==item)
         printf("index: %d\n",j);
    }
}
void sum(struct array *p)
{
    int i,j,k=0;
   if(p->top==-1)
    printf("stack empty");
    else
    i=p->top;
    for(int j=0;j<p->top;j++)
    {
       k=k+p->arr[j];
    }
    printf("sum: %d",k);
}
void average(struct array *p)
{
    int i,j,k=0;
    float l;
   if(p->top==-1)
    printf("stack empty");
    else
    i=p->top;
    for(int j=0;j<p->top;j++)
    {
       k=k+p->arr[j];
    }
      l=k/j-1;
    printf("average: %d",l);
}
/*void great2(struct array *p)
{
   int i,j,k;
   if(p->top==-1)
    printf("stack empty");
    else
    i=p->top;
    for(int j=0;j<p->top;j++)
    {
        if(p->arr[j]>p->arr[j+1])
            { j=k; }
        printf("max: %d",p->arr[k]);
    }
}*/
void duplicate(struct array *p)
{   
    int i,j,k,h;
    if(p->top==-1)
    printf("stack empty");
    else
    j=p->cap;
    for(i=0;i<p->cap;i++)
     {
        for(k=i+1;k<p->cap;k++)
        {
            if(p->arr[k]==p->arr[i])
            {
               p->top--;
               for(h=p->top; p->top>k ;h--)
                 p->arr[h]=p->arr[h-1];
            }
        }
     }
   
}

