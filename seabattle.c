#include <stdio.h>
#include <stdlib.h>

struct GAMER{
	char name[10];
	int sheep[4][2];
	int turn;
};

void draw_field(char field[10][10]);
void draw_line(int n, char symbol);
void draw_alphabet(void);
 

int main(int argc, char * argv[]){
	
	char field[10][10] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
						  {' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
						  {' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},	
						};
	
	draw_field(field);
	
	return 0;
}

void draw_line(int n, char symbol){
	int i;
	
//	putchar('\n');
	for(i = 0; i <= n; i++)
		printf("%c", symbol);
	
	putchar('\n');
	
	return;
}

void draw_alphabet(void){
	
	int i;
	
	printf("   ");
	for(i = 0; i <= 9; i++)
	{
		printf("%c |", 65+i);	
	}
	putchar('\n');
	
	return;
}

void draw_field(char field[10][10]){
	
	int i, j;
	
	draw_alphabet();
	for(i = 0; i <= 9; i++)
	{
		draw_line(31, '_');
		printf("%d |", i+1);
		for(j = 0; j <= 9; j++)
		{
			printf("%c |", field[i][j]);
			
		}
		
		putchar('\n');
		
	}
	
	return;
}