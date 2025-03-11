#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;
class number_shifting{
     int board[4][4];
     int temp[15];
     void set_unique_position(){
        int samp,count=0;
        srand(time(0));
        for(int i=0;i<15;i++){
            samp=(rand()%15)+1;
            if(check_dublicate(samp))
               temp[i]=samp;
            else
               i--;
        }
        //assigning the actual array
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
               board[i][j]=temp[count++];
            }
        }
          board[3][3]=0;
    }
    private:
    bool check_dublicate(int samp){
        for(int i=0;i<15;i++){
            if(temp[i]==samp)
               return false;
        }
        return true;
    }
    void display_board(){
        cout<<"---------------------------------";
        for(int i=0;i<4;i++){
            cout<<endl;
            for(int j=0;j<4;j++){
                if(board[i][j]==0)
                cout<<"   \t|";
                else
                cout<<"   "<<board[i][j]<<"\t|";
            }
        }
        cout<<"\n---------------------------------\n\n";
    }
    int swap_up_key(){
        int i,j,swap;
         for(i=0;i<4;i++){
            for(j=0;j<4;j++){
               if(board[i][j]==0)
               break;
            }
            if(board[i][j]==0)
            break;
        }
        if(i==0)
        return 0;
        else{
            swap=board[i-1][j];
            board[i-1][j]=board[i][j];
            board[i][j]=swap;
        }
        return 1;
    }
    int swap_down_key(){
        int i,j,swap;
         for(i=0;i<4;i++){
            for(j=0;j<4;j++){
               if(board[i][j]==0)
               break;
            }
            if(board[i][j]==0)
            break;
        }
        if(i==3&&j==0||i==3&&j==1||i==3&&j==2||i==3&&j==3)
        return 0;
        else{
            swap=board[i+1][j];
            board[i+1][j]=board[i][j];
            board[i][j]=swap;
        }
        return 1;
    }
    int swap_left_key(){
        int i,j,swap;
         for(i=0;i<4;i++){
            for(j=0;j<4;j++){
               if(board[i][j]==0)
               break;
            }
            if(board[i][j]==0)
            break;
        }
        if(j==0&&i==0||j==0&&i==1||j==0&&i==2||j==0&&i==3)
        return 0;
        else{
            swap=board[i][j-1];
            board[i][j-1]=board[i][j];
            board[i][j]=swap;
        }
        return 1;
    }
    int swap_right_key(){
        int i,j,swap;
         for(i=0;i<4;i++){
            for(j=0;j<4;j++){
               if(board[i][j]==0)
               break;
            }
            if(board[i][j]==0)
            break;
        }
        if(j==3)
        return 0;
        else{
            swap=board[i][j+1];
            board[i][j+1]=board[i][j];
            board[i][j]=swap;
        }
        return 1;
    }
    int check_win_condition(){
        int test_value=1,i,j;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(board[i][j]==test_value)
                  test_value++;
            }
        } 
        if(board[i][j]==0&&test_value==16)
        return 1;
        else return 0;
    }
    public:
    void run_game(){
        int move=1000;
        char str[10],enter,choice;
        set_unique_position();
        cout<<"Enter Your Name: ";
        cin>>str;
        cout<<"Welcome  "<<str<<"\n\n";
        display_board();
        while(1){
            system("cls");
            printf("\nHello %s,         remaning moves %d,     Press E or e for exit\n\n" ,str,move);
            display_board();
            if(move==0){
               cout<<"You Lose Game !!!!.......";
                break;
            }
            if(check_win_condition())
                break;
            
            choice=getch();
            switch(choice)
            {
            case 69:
                break;
            case 101:
                break;
            case 72:
                if(swap_up_key())
                move--;
                break;
            case 80:
                if(swap_down_key())
                move--;
                break;
            case 75:
                 if(swap_left_key())
                 move--;
                 break;
            case 77:
                if(swap_right_key())
                move--;
                break;
            default:
               cout<<"\nInvalid Move !!!!.......   ";
                break;
            }
        }if(move!=0){
        system("cls");
        display_board();
        cout<<"\n\nCongratulation You Win The Game  !!!...."<<endl;
        cin>>enter;
      }
    }
};
int main(){
    number_shifting obj;
    obj.run_game();
          return 0;
}