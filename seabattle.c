#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct GAMER{
	char name[10];
	int sheep[4][2];
	int turn;
};

void draw_field(char field[10][10]);
void draw_line(int n, char symbol);
void draw_alphabet(void);
 
char * set_field_ships(void);
void spawn_ship(char field[10][10], int deck); 
void move_ship(char field[10][10], char mode, char direct, int ship)

int main(int argc, char * argv[]){
	
	set_field_ships();
	
	return 0;
}


// ---------------------------------------------------------------------------

void move_ship(char field[10][10], char mode, char direct, int ship, short * x, short * y){
	/*
		if mode is b then a ship will moving down
		if mode is t then a ship will moving top
		if mode is r then a ship will moving right in horizantal
		if mode is l then a ship will moving left in horizantal
	*/
	
	int i;
	
	if(mode == 'b')
	{	
		if(direct == 'v')
		{
			for(i = 0; i <= ship; i++)
			{
				field[*x+i][*y] = ' ';
				
			}
		}
		
	}
}

void spawn_ship(char field[10][10], int deck){
	
	int i;
	for(i = 0; i <= deck; i++)
	{
		field[i][0] = '#';	
	}
	
}

char * set_field_ships(void){
	
	// getch() - it's function let us to make nonstop input.
	
	char field[10][10] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	
						};
	
	int ships[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1}
	int ship = 0
	
	short int left_x = 1, left_y = 1;
	// v - vertical mod; h - horizantall mod;
	short int mode = 'v';
	
	char choice = 'v';
	
	
	while(choice != 'e')
	{
		choice = getch();
		
		switch(choice)
		{
			case 's':
				move_ship(field, 'b', mode, ships[ship], &left_x, &left_y);
				break;
			case 'w':
				move_ship(field, 't', mode, ships[ship], &left_x, &left_y);
				break;
			case 'd':
				move_ship(field, 'r', mode, ships[ship], &left_x, &left_y);
				break;
			case 'a':
				move_ship(field, 'l',mode), ships[ship], &left_x, &left_y);
				break;
			case 'k':
				ship++;
				spawn_ship(field, ships[ship]);
				break;
		}
		
		draw_field(field);
			
	}
	
	
	
	
}

// ---------------------------------------------------------------------------

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
	
	printf("   |");
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
		draw_line(33, '_');
		printf("%2d |", i+1);
		for(j = 0; j <= 9; j++)
		{
			printf("%c |", field[i][j]);
			
		}
		
		putchar('\n');
		
	}
	
	return;
}