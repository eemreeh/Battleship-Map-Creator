#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define bsize 10
#define shipsize 4
#define sea '.'            //206
#define sea2 ' '            //205
#define ship 'X'         	//254

int check(int size, int a, int b, int z);
void placeship(int );

int board[bsize][bsize];

void main(){
	int i, j, k;		
	for(i=0;i<bsize;i++)
		for(j=0;j<bsize;j++)
			board[i][j] = sea;
			
	for(i=0;i<shipsize;i++){
		for(j=0;j<shipsize-i;j++)
			placeship(i+1);
	}	
	for(i=0;i<bsize;i++){
		for(j=0;j<bsize;j++){
			printf("%c%c",board[i][j],sea2);
		}
		puts("");
	}
	
	system("pause");
}

int check(int size, int a, int b, int z){   // a = x    b = y
		int i, flag = 1;
		switch(z){
			case 2:
				for(i = 0;i<size+2;i++){
					if(board[a-1][b-1+i] == ship || board[a][b-1+i] == ship || board[a+1][b-1+i] == ship )
						flag = 0;
				}
				break;
			case 1:
				for(i = 0;i<size+2;i++){
					if(board[a+1-i][b-1] == ship || board[a+1-i][b] == ship || board[a+1-i][b+1] == ship )
						flag = 0;
				}
				break;
			case 0:
				for(i = 0;i<size+2;i++){
					if(board[a-1][b+1-i] == ship || board[a][b+1-i] == ship || board[a+1][b+1-i] == ship )
						flag = 0;
				}
				break;
			case 3:
				for(i = 0;i<size+2;i++){
					if(board[a-1+i][b-1] == ship || board[a-1+i][b] == ship || board[a-1+i][b+1] == ship )
						flag = 0;
				}
				break;
			default:
				break;
		}
		return flag;
	}

void placeship(int sizeship){      //0 = up 1 = left 2 = down 3 = right
	int x, y, z, i;
	srand(time(NULL));
	EMRE:
	x = rand() % bsize;
	y = rand() % bsize;
	z = rand() % 4;
	if((z == 0 && y<sizeship)||(z == 1 && x<sizeship)||(z == 2 && y>(bsize - sizeship))||(z == 3 && x>(bsize - sizeship)))
		goto EMRE;	
	if(check(sizeship, x, y, z)){
		for(i = 0;i<sizeship;i++){
			switch(z){
				case 0:
					board[x][y-i] = ship;
					break;
				case 1:
					board[x-i][y] = ship;
					break;
				case 2:
					board[x][y+i] = ship;
					break;
				case 3:
					board[x+i][y] = ship;
					break;
				default:
					break;
			}
		}
	}else
		goto EMRE;
}
