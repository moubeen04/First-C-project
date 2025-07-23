//Tic-Tac-Toe Game

#include <iostream>
#include<iomanip>
using namespace std;

//Prototyping
void gameboarddisplay(char board[3][3]);
void inputmoveX(char board[3][3],int row,int column,char move);
void inputmoveO(char board[3][3],int row,int column,char move);
void inputRowColumn(int row,int column);
bool checkwin(char board[3][3]);

int main()
{
	char board[3][3]={
					{' ',' ',' '},
					{' ',' ',' '},
					{' ',' ',' '}		
					};
	char move='X';
	system("color 0B");
	bool gameover=false;
	
	cout<<"*****************  \"WELCOME TO TIC-TAC-TOE!\" ***************** "<<endl;
	int row,column; 
	cout<<"******************************************************************"<<endl;
	gameboarddisplay(board);
	cout<<"******************************************************************"<<endl;
	while(!gameover)
	{
		if(!gameover){
		//For X win:
		inputmoveX(board,row,column,move);
		if(checkwin(board)){
			cout<<"Congratulations! Player "<<move<<" won the game.:)"<<endl;
			gameover=true;
			break;
		}
		else{
			move=(move=='X')?'O':'X';
			
		}
		
		//For O win:
		inputmoveO(board,row,column,move);
		move='O';
		if(checkwin(board)){
			cout<<"Congratulations! Player "<<move<<" won the game.:)"<<endl;
			gameover=true;
			break;
		}
		else{
			move=(move=='O')?'X':'O';
			
		}
	}
	}
	return 0;
}

//For input move X
void inputmoveX(char board[3][3],int row,int column,char move)
{
		cout<<"******************************************************************"<<endl;
		cout<<"Player X enter your move (row and column).Enter row no (0,1,2) space(" ") column no(0,1,2) = ";
		cin>>row>>column;
		cout<<"******************************************************************"<<endl;
		if((row>=0&&row<3)&&(column>=0&&column<3)){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)
			{
				if(row==i && column==j)
				{
					board[row][column]='X';
				}	
			}
		}
	}
	else {
		cout<<"Invalid Input."<<endl;
	}
		gameboarddisplay(board);
}

//For input move O
void inputmoveO(char board[3][3],int row,int column,char move){
		cout<<"******************************************************************"<<endl;
		cout<<"Player X enter your move (row and column).Enter row no (0,1,2) space(" ") column no(0,1,2) = ";
		cin>>row>>column;
		cout<<"******************************************************************"<<endl;
		if((row>=0&&row<3)&&(column>=0&&column<3)){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)
			{
				if(row==i && column==j)
				{
					board[row][column]='O';
				}	
			}
		}
	}
	else {
		cout<<"Invalid Input."<<endl;
	}
		gameboarddisplay(board);
	}

//Gameboard Display
void gameboarddisplay(char board[3][3]){
	for(int i=0;i<3;i++){
		cout<<"----------"<<endl;
		for(int j=0;j<3;j++){
			cout<<"|"<<board[i][j]<<setprecision(3)<<" ";
		}
		cout<<"|";
		cout<<endl;
	}
	cout<<"----------"<<endl;
}

//The condition to check the win ratio
bool checkwin(char board[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]==('O'||'X') && board[i][1] == board[i][2]==('O'||'X')&&board[i][2]!=' ' ) ||
            (board[0][i] == board[1][i]==('O'||'X') && board[1][i] == board[2][i]==('O'||'X')&&board[2][i]!=' ' )){
            return true;
        }
    }

     if ((board[0][0] == board[1][1]==('O'||'X') && board[1][1] == board[2][2]==('O'||'X')&&board[2][2]!=' ' ) ||
        (board[0][2] == board[1][1]==('O'||'X') && board[1][1] == board[2][0]==('O'||'X')&&board[2][2]!=' ' )) {
        return true;
    }
    return false;
}
