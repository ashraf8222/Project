#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int arr[4][4];
int b[15];
void Unique_postion(){
    int x,samp;
    printf("\n");
    srand(time(0));
    for(int j=0;j<15;j++){

    do{
        x=(rand()%15)+1;
          samp=0;

    for(int i=0;i<15;i++){
        if(b[i]==x){
           samp=1; break;} 
        }
    } while(samp);     


        b[j]=x;
    }
}
void create_matrix(){
    int samp=0,i,j;
    Unique_postion();
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            arr[i][j]=b[samp];
            samp++;
        }
    }
    arr[i][j]=0;
}
void display_matrix(){
    printf("--------------------------------");
    for(int i=0;i<4;i++){
        printf("\n");
        for(int j=0;j<4;j++){
            if(arr[i][j]==0)
                printf("|      |");
            else
            printf("| %3d  |",arr[i][j]);
        }
    }
    printf("\n--------------------------------\n");
}
int shift_up_key(){
    int i,j,samp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]==0)
            break;
        }
        if(arr[i][j]==0)
        break;
    }

    if(i==0&&j==0||i==0&&j==1||i==0&&j==2||i==0&&j==3)
     return 0;
    else{ 
     samp=arr[i][j];
     arr[i][j]=arr[i-1][j];
     arr[i-1][j]=samp;
    }

    return 1;
}
int shift_down_key(){
     int i,j,samp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]==0)
            break;
        }
        if(arr[i][j]==0)
        break;
    }

    if(arr[3][0]==0 || arr[3][1]==0 || arr[3][2]==0 || arr[3][3]==0)
      return 0;
    else{ 
     samp=arr[i][j];
     arr[i][j]=arr[i+1][j];
     arr[i+1][j]=samp;
    }

    return 1;
}
int shift_right_key(){
    int i,j,samp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]==0)
            break;
        }
        if(arr[i][j]==0)
        break;
    }

    if(i==0&&j==3||i==1&&j==3||i==2&&j==3||i==3&&j==3)
     return 0;
    else{ 
     samp=arr[i][j];
     arr[i][j]=arr[i][j+1];
     arr[i][j+1]=samp;
    }

    return 1;
}
int shift_left_key(){
    int i,j,samp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]==0)
            break;
        }
        if(arr[i][j]==0)
        break;
    }

    if(i==0&&j==0)
      return 0;
    if(arr[1][0]==0)
      return 0;
    if(arr[2][0]==0)
      return 0;
    if(arr[3][0]==0)
      return 0;
    
     samp=arr[i][j];
     arr[i][j]=arr[i][j-1];
     arr[i][j-1]=samp;
      return 1;
}
int check_win_condition(){
    int samp=1,i,j;
          for( i=0;i<4;i++){
            for( j=0;j<4;j++){
                 if(arr[i][j]==samp)
                  samp++;
            }
          }
    if(samp==16)
      return 0;
    else 
    return 1;
}
int run_game(){
    char str[10],i,key;
    int move=1000;
    printf("Enter Your Name:  ");
    scanf("%s",&str);
    create_matrix();
    printf("\nWelcome %s,",str);
    printf("Press Enter to start the game:");
    scanf("%c",&i);
    system("cls");

    do{
     system("cls");
    printf("\nHello %s,         remaning moves %d,     Press E or e for exit\n\n" ,str,move);
    display_matrix();
  
    if(move==0){ printf("\n YOU LOSE!!,\n"); getch(); return 0; }

    key=getch();
    switch (key)
    {
    case 69:
        return 0;
    case 101:
         return 0;
    case 72:
        if(shift_up_key())
          move--;
         break;
    case 80:
        if(shift_down_key())
           move--;
          break;
    case 75:
         if(shift_left_key())
           move--;
          break;
    case 77:
         if(shift_right_key())
           move--;
         break;

    default:
        printf("\n\nEnter a valid Arrow key:\n");
    }

    } while(check_win_condition());
    system("cls");
    display_matrix();
    printf("\n Congratulations YOU WON!!\n");
    getch();
    return 0;
}
int main(){
    char ch;
    printf("                      RULE FOR THIS GAME\n\n");
    printf("1.you can make only 1 step at a time by arrow key\n");
    printf("Move Up   :  by Up arrow key\n");
    printf("Move Down :  by Down arrow key\n");
    printf("Move Left :  by Left arrow key\n");
    printf("Move Right:  by Right arrow key\n\n");
    printf("2.Your can move number at empty position only\n");
    printf("3.For each valid move : Your total number move will decreased by 1\n");
    printf("Wining situation : Arrange number in such order like given below\n\n");
    printf("                  WINNING SITUATION:\n");
    printf("-----------------\n");
    printf("| 1 | 2 | 3 | 4 |\n");
    printf("| 5 | 6 | 7 | 8 |\n");
    printf("| 9 |10 |11 |12 |\n");
    printf("|13 |14 |15 |   |\n");
    printf("-----------------\n");
    printf("\nYou can exit the game at any time in game by pressing E or e,\n");
    printf("When your number of move is  0 then you lose the game::::\n");
    printf("     \nPress Enter key:::::  ok,"); 
    scanf("%c",&ch);
    system("cls");
    run_game();
}