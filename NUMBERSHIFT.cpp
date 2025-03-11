#include<iostream>      //for input or output function
#include<string>        //for string data type
#include<stdlib.h>      //srand() or rand() function
#include<conio.h>       //window's function 
#include<time.h>        //gives current time of system
using namespace std;
//data type for game board 
struct board{
     int board_space[4][4];
     int sample_arr[15];
};
//class for NumberShifting game
class numbershift{
    //private for abstraction or security
    private:
      string name;
      int moves;   
      board *ptr;   // pointer for game borad 
      void random_number_generator()  // assigns value to sample array
      {
          int temp;  
          srand(time(0));   // set the random number for rand() funtion 
          for(int i=0;i<15;i++)
          {
              temp=(rand()%15)+1;   // return random number from (1-15)
              if(unique_value(temp,i))
                 ptr->sample_arr[i]=temp;  
              else
                 i--;
          }

      }
      bool unique_value(int temp,int index)  // check unique number
      { 
            for(int i=0;i<index;i++)
            {
                if(ptr->sample_arr[i]==temp)
                    return false;
            }
            return true;
      }
      int* search_black_index()  // returns index of 16 number from board
      {
          int *index=new int[2];
          for(int i=0;i<4;i++)
          {
              for(int j=0;j<4;j++)
              {
                  if(ptr->board_space[i][j]==16)
                  {
                      index[0]=i;
                      index[1]=j;
                      return index;
                  }
              }
          }
          return NULL;
      }
      void display_board() //display board to screen 
      {
           cout<<"Hello "<<name<<"\t\t PRESS esc KEY FOR EXIT        \tREMAINING MOVES : "<<moves;
           cout<<" \n\n-------------------------------\n";
           for(int i=0;i<4;i++)
           {
               for(int j=0;j<4;j++){
                   if(ptr->board_space[i][j]!=16)
                      cout<<"|   "<<ptr->board_space[i][j]<<"\t";
                   else
                      cout<<"|    "<<"\t";
                }
                cout<<"|"<<endl;
           }
           cout<<" -------------------------------\n";
       }
       bool check_win_condition() // return true if game is solved
       {
           int temp=1;
           for(int i=0;i<4;i++)
           {
               for(int j=0;j<4;j++)
               {
                   if(ptr->board_space[i][j]!=temp)
                         return false;
                   else
                         temp++;
               }
           }
           return true;
       }
       /*
         checking for arrow keys 
         and swap the data to blank space
       */
        bool arrow_up_key() 
        {
            if(ptr->board_space[0][0]==16||ptr->board_space[0][1]==16||ptr->board_space[0][2]==16||ptr->board_space[0][3]==16)
                return false;
            else
            {
               int *index=search_black_index();
               int i=index[0];
               int j=index[1];
               ptr->board_space[i][j]=ptr->board_space[i-1][j];
               ptr->board_space[i-1][j]=16;
            }
            return true;
        }
        bool arrow_down_key()
        {
            if(ptr->board_space[3][0]==16||ptr->board_space[3][1]==16||ptr->board_space[3][2]==16||ptr->board_space[3][3]==16)
                return false;
            else
            {
               int *index=search_black_index();
               int i=index[0];
               int j=index[1];
               ptr->board_space[i][j]=ptr->board_space[i+1][j];
               ptr->board_space[i+1][j]=16;
            }
            return true;
        }
        bool arrow_left_key()
        {
            if(ptr->board_space[0][0]==16||ptr->board_space[1][0]==16||ptr->board_space[2][0]==16||ptr->board_space[3][0]==16)
                return false;
            else
            {
               int *index=search_black_index();
               int i=index[0];
               int j=index[1];
               ptr->board_space[i][j]=ptr->board_space[i][j-1];
               ptr->board_space[i][j-1]=16;
            }
            return true;
        }
        bool arrow_right_key()
        {
            if(ptr->board_space[0][3]==16||ptr->board_space[1][3]==16||ptr->board_space[2][3]==16||ptr->board_space[3][3]==16)
                return false;
            else
            {
               int *index=search_black_index();
               int i=index[0];
               int j=index[1];
               ptr->board_space[i][j]=ptr->board_space[i][j+1];
               ptr->board_space[i][j+1]=16;
            }
            return true;
        }
        bool unsolved_position_occurs() //check's condition for unsolved random number is generated
        {
            if(ptr->board_space[0][0]==1&&ptr->board_space[0][1]==2&&ptr->board_space[0][2]==3&&ptr->board_space[0][3]==4)
            {
                if(ptr->board_space[1][0]==5&&ptr->board_space[1][1]==6&&ptr->board_space[1][2]==7&&ptr->board_space[1][3]==8)
               {

                if(ptr->board_space[2][0]==9&&ptr->board_space[2][1]==10&&ptr->board_space[3][0]==13&&ptr->board_space[3][1]==14)
               {
                if(ptr->board_space[2][2]==15&&ptr->board_space[2][3]==12){
                            cout<<"\nUNSOLVED POSITION DETECTED:--->>> enter to start";
                               _getch();
                            ptr->board_space[2][3]=15;
                            ptr->board_space[2][2]=12;
                            return true;
                    }
                        else
                           return false;
                }
            else
               return false;
               }
               else
                 return false;
            }
            else
                return false;
        }
    // funtion's for non-member function for given object
    public:
       numbershift()
       {
          ptr=NULL;
          moves=-1;
       }
       ~numbershift()
       {
           delete ptr;
           moves=-1;
       }
       void create_board(int move_number) // assigns random order number to borad pointer
       {
          ptr=new board;
          moves=move_number;
          int temp=0; 
          //assign random num to sample array
          random_number_generator(); 
          //copying data from sample array to board
          for(int i=0;i<4;i++)
          {
              for(int j=0;j<4;j++){
                 ptr->board_space[i][j]=ptr->sample_arr[temp];
                 temp++;
              }
          }
          ptr->board_space[3][3]=16;
       }
        void run_game() //control the flow of game
        {
            int choice;
            game_rules();
            system("CLS");
            cout<<"Please Enter Your Name ";
            getline(cin,name);
            system("CLS");
            while(true)  
            {
                display_board();
                choice=_getch();  //return assci value for input 
                if(check_win_condition())
                {
                    cout<<"\n\t\"Congratulation "<<name<<" YOU WIN !!!......  \""<<endl;
                     _getch();
                    break;
                }
                else if(moves==0)
                {
                    cout<<"\n\t\"OHH OUT OF MOVES .... <<TRY AGAIN>>"<<endl;
                     _getch();
                    break;
                }
                else if(choice==27)
                {
                    break;
                }
                /*
                  special character returns twice assci value once 
                  for common assci for special key
                  and second for actual key
                */
                else if(choice==224) //input for first key
                {
                    choice=_getch(); //input for second key
                    switch (choice)
                    {
                       case 72:
                          if(arrow_up_key())
                            moves--;
                          break;
                       case 80:
                           if(arrow_down_key())
                             moves--;
                          break;
                       case 75:
                           if(arrow_left_key())
                             moves--;
                           break;
                       case 77:
                           if(arrow_right_key())
                            moves--;
                           break;
                       default :
                           cout<<"\n\n\n\n\n\n\tPLEASE ENTER VALID KEY!!!!..... press enter"<<endl;
                           _getch();
                    }
                }
                unsolved_position_occurs();
                system("CLS"); //for clear the current terminal
            }

        }
        void game_rules() //gives games rules to end user's
        {
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
            printf("\n               Happy Gaming , Good Luck.\n");
            printf("     \nPress Enter key:::::  OK,");
            scanf("%c",&ch);

        }
};

int main(){
    numbershift obj; 
    obj.create_board(1000);
    obj.run_game();
}
