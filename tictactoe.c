#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3];



void resetboard(){
    int i,j;
    
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    
}

void viewboard(){
    int i,j,c=1;
    printf("\ntic tac toe\n\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {   
            if (board[i][j]!=' ')
            {
                printf(" %c",board[i][j]);
            }
            else{
                printf(" %d",c);
            }
            if (j<2){
                printf(" | ");
            }
            c++; 
        }
        printf("\n");
        if (i<2)
        {
        printf("--- ---- ---");
        }
        printf("\n");
    }
    
}

int freeslote(){
    int fs=9;//freeslotes
    int i,j;
    
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (board[i][j]!=' ')
            {
                fs--;
            }
        }
        
    }

    return fs;
}

void playermove(){
    int ch;
    printf("enter the choise 1 - 9 :");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
            if(board[0][0]!=' '){
            printf("invalid ");
            playermove();
            }
            board[0][0]='X'; 
            break;
    case 2:
            if(board[0][1]!=' '){
            printf("invalid ");
            playermove();
            }
            board[0][1]='X'; break;
    case 3:if(board[0][2]!=' '){
            printf("invalid ");
            playermove();
            }
            board[0][2]='X'; break;
    case 4:if(board[1][0]!=' '){
            printf("invalid ");
            playermove();
            }
            board[1][0]='X'; break;
    case 5:if(board[1][1]!=' '){
            printf("invalid ");
            playermove();
            }
            board[1][1]='X'; break;
    case 6:if(board[1][2]!=' '){
            printf("invalid ");
            playermove();
            }
            board[1][2]='X'; break;
    case 7:if(board[2][0]!=' '){
            printf("invalid ");
            playermove();
            }
            board[2][0]='X'; break;
    case 8:if(board[2][1]!=' '){
            printf("invalid ");
            playermove();
            }
            board[2][1]='X'; break;
    case 9:if(board[2][2]!=' '){
            printf("invalid ");
            playermove();
            }
            board[2][2]='X'; break;
    default:printf("enter the correct choise");playermove();
        break;
    }
    viewboard();
    
}


void computermove(){
    srand(time(0));

      srand(time(0));
   int x;
   int y;
   if(freeslote() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');
      
      board[x][y] = 'O';
      viewboard();
   }
   else
   {
      printf("no moves remain");
   }
}

char checkwinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][2];
        }
    }

    return 't';
}

void play(){
    while (freeslote() > 0)
    {
        playermove();
        if ('X'== checkwinner())
        {
            printf("\nplayer winner\n");
            exit(0);
        }
        computermove();
        if ('O'== checkwinner())
        {
            printf("\ncomputer winner\n");
            exit(0);
        }

        if (freeslote() == 0 && checkwinner() == 't')
        {
            printf("\ntie game\n");
            exit(0);
        }
    }
    
}





int main(){
    resetboard();
    viewboard();
    play();
}