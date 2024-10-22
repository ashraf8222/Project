#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char a[3][3];
int c[9];
void display_board(){
    for(int i=0;i<3;i++){
        printf("\n");
        for(int j=0;j<3;j++)
       printf("| %c  ",a[i][j]);
        printf("\n-------------\n");
    }
}
int check_full_matrix(){
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]=='\0')
              return 0;}
     }
return 1;
}
int check_win_condition(char player){
    int i=0,j;
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==player || a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[0][2]==player)
           return 1;

        while(i!=3){
            j=0;
            if(a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2]&&a[i][j]==player)
                return 1;
            else if(a[j][i]==a[j+1][i]&&a[j+1][i]==a[j+2][i]&&a[j][i]==player)
                return 1;
            i++;
        }
    return 0;
}
void set_data(int num,char player){
       if(num==1) a[0][0]=player;
       else if(num==2) a[0][1]=player;
       else if(num==3) a[0][2]=player;
       else if(num==4) a[1][0]=player;
       else if(num==5) a[1][1]=player;
       else if(num==6) a[1][2]=player;
       else if(num==7) a[2][0]=player;
       else if(num==8) a[2][1]=player;
       else if(num==9) a[2][2]=player;
}
int check_cheating(int i){
    if(c[i]==i)
    return 0;
     c[i]=i;
    return 1;
}
int run_game(){
     char player1='X',player2='O',temp;
       temp=player1;
     int samp,i=12;
    do{
          system("cls");
           display_board();
         printf("Enter Your Choice %c: ,100 for exit" ,temp);
         scanf("%d",&samp);
         if(samp==100)
         return 0;
         if(samp<10&&samp>0&&check_cheating(samp))
            set_data(samp,temp);
         else{
         printf("\nInvalid input try again:\n");
         i--;
         }

      if(check_win_condition(temp)){
       system("cls");
        display_board();
       printf("%c Wins\n",temp);
        getch();
        return 0;}


      if(check_full_matrix()){
        system("cls");
        display_board();
         printf("\nMatch Draw:\n");
         getch();
          return 0;
      }

    if(i%2==0)
       temp=player2;
    else temp=player1;

       i++;
    } while(1);
}
int main(){
    char s;
    printf("Welcome to Tic-Tac-Toe Game\n");
    printf("Select following inputs to make a move\n\n");
    printf("1 | 2 | 3 \n");
    printf("----------\n");
    printf("4 | 5 | 6 \n");
    printf("----------\n");
    printf("7 | 8 | 9 \n");
    printf("\nPress enter to start the game: \n");
    scanf("%c",&s);
    //system("clear");
    run_game();
    return 0;
}
