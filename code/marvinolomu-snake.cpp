#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

// a simple snake game
// 4 is a body
// 3 is the head
// 2 is an apple
// 1 is a block
// 0 is nothing

// works under Windows
// compiled with MSC compiler

int level_matrix[20][20];
int lastposx[20];
int lastposy[20];
int delta_time = 0;
int game_tick = 0;
int delta_time_tick = delta_time + 10; // magic number
bool block_input = 0;
bool apple_spawned = 0;
int playerx = 10;
int playery = 5; // first array is y second is x
int body = 0;
char input = 'n';
bool apple_on_player = true;

void gotoxy(short x, short y)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(hCon, pos);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void render_level()
{
	char wall = '#';
	char point = 'o';
	char player = 'X';
	char bodypart = 'y';

	gotoxy(1, 7);
	for (int i = 0; i < 20; i++) // height
	{
		for (int j = 0; j < 20; j++) //width
		{
			//printf("%d", level_matrix[i][j]);
			if (level_matrix[i][j] == 1)
			{
				printf("%c", wall);
			}
			if (level_matrix[i][j] == 0)
			{
				printf(" ");
			}
			if (level_matrix[i][j] == 3)
			{
				printf("%c",player);
			}
			if (level_matrix[i][j] == 4)
			{
				printf("%c", bodypart);
			}
			if (level_matrix[i][j] == 2)
			{
				printf("%c", point);
			}
		}
		printf("\n");
	}
}

void input_handler()
{

	if (_kbhit())
	{
		input = (char)_getch();
	}

	switch (input)
	{
	case 'w': case 'W':
	{
		gotoxy(1, 5);
		printf("key:up     ");
		break;
	}
	case 's': case 'S':
	{
		gotoxy(1, 5);
		printf("key:down   ");
		break;
	}
	case 'a': case 'A':
	{
		gotoxy(1, 5);
		printf("key:left   ");
		break;
	}
	case 'd': case 'D':
	{
		gotoxy(1, 5);
		printf("key:right  ");
		break;
	}

	}
}

void spawn_player()
{
	level_matrix[playery][playerx] = 3;
}

void nullify_mid()
{
	for (int i = 1; i < 19; i++) //rewrite this part just use 2 loops
	{
		level_matrix[1][i] = 0;
		level_matrix[i][1] = 0;
		level_matrix[2][i] = 0;
		level_matrix[i][2] = 0;
		level_matrix[3][i] = 0;
		level_matrix[i][3] = 0;
		level_matrix[4][i] = 0;
		level_matrix[i][4] = 0;
		level_matrix[5][i] = 0;
		level_matrix[i][5] = 0;
		level_matrix[6][i] = 0;
		level_matrix[i][6] = 0;
		level_matrix[7][i] = 0;
		level_matrix[i][7] = 0;
		level_matrix[8][i] = 0;
		level_matrix[i][8] = 0;

		level_matrix[9][i] = 0;
		level_matrix[i][9] = 0;
		level_matrix[10][i] = 0;
		level_matrix[i][10] = 0;
		level_matrix[11][i] = 0;
		level_matrix[i][11] = 0;
		level_matrix[12][i] = 0;
		level_matrix[i][12] = 0;
		level_matrix[13][i] = 0;
		level_matrix[i][13] = 0;
		level_matrix[14][i] = 0;
		level_matrix[i][14] = 0;
		level_matrix[15][i] = 0;
		level_matrix[i][15] = 0;
		level_matrix[16][i] = 0;
		level_matrix[i][16] = 0;
		level_matrix[17][i] = 0;
		level_matrix[i][17] = 0;
		level_matrix[18][i] = 0;
		level_matrix[i][18] = 0;
	}
}

void create_walls()
{
	for (int i = 0; i < 20; i++)
	{
		level_matrix[0][i] = 1;
		level_matrix[i][0] = 1;
		level_matrix[19][i] = 1;
		level_matrix[i][19] = 1;
	}
}

void add_body()
{
	body++;

	lastposx[body] = lastposx[0];
	lastposy[body] = lastposy[0];

	level_matrix[lastposy[body]][lastposx[body]] = 4;
}

void check_lose()
{

}

void spawn_apple()
{
	int x, y;
	while (apple_on_player != false)
	{
		srand((unsigned)time(NULL));
		x = (rand() % 18 + 1);
		y = (rand() % 18 + 1);
		if (level_matrix[y][x] == 0)
		{
			apple_on_player = false;
			apple_spawned = true;
			level_matrix[y][x] = 2;
		}
	}
}

int main()
{
	bool game_window = 1;

	hidecursor();

	nullify_mid();
	create_walls();
	spawn_player();

	while(game_window == 1)
	{
		if (delta_time == delta_time_tick)
		{
			block_input = 1;
			game_tick++;
			delta_time = 0;
			switch (input)
			{
			case 'w': case 'W':
			{
				if (level_matrix[playery][playerx - 1] == 4 || level_matrix[playery][playerx + 1] == 4 || level_matrix[playery + 1][playerx] == 4 || level_matrix[playery - 1][playerx] == 4)
				{

				}
				else if (level_matrix[playery][playerx - 1] == 1 || level_matrix[playery][playerx + 1] == 1 || level_matrix[playery + 1][playerx] == 1 || level_matrix[playery - 1][playerx] == 1)
				{
					return 0;
				}
				else if (level_matrix[playery][playerx - 1] == 2)
				{
					level_matrix[playery][playerx - 1] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery - 1][playerx] == 2)
				{
					level_matrix[playery--][playerx] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery + 1][playerx] == 2)
				{
					level_matrix[playery + 1][playerx] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery][playerx + 1] == 2)
				{
					level_matrix[playery][playerx + 1] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else
				{
					level_matrix[playery][playerx] = 0;
				}
				lastposx[0] = playerx;
				lastposy[0] = playery;
				if (playery >= 0)
				{
					playery--;
					level_matrix[playery][playerx] = 3;
				}
				//gotoxy(1, 5);
				//printf("key:up     ");
				break;
			}
			case 's': case 'S':
			{
				if (level_matrix[playery][playerx-1] == 4 || level_matrix[playery][playerx+1] == 4 || level_matrix[playery+1][playerx] == 4 || level_matrix[playery-1][playerx] == 4)
				{

				}
				else if (level_matrix[playery][playerx-1] == 1 || level_matrix[playery][playerx+1] == 1 || level_matrix[playery+1][playerx] == 1 || level_matrix[playery-1][playerx] == 1)
				{
					return 0;
				}
				else if (level_matrix[playery][playerx-1] == 2)
				{
					level_matrix[playery][playerx-1] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery-1][playerx] == 2)
				{
					level_matrix[playery-1][playerx] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery+1][playerx] == 2)
				{
					level_matrix[playery+1][playerx] = 0;
					add_body();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery][playerx+1] == 2)
				{
					level_matrix[playery][playerx+1] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else
				{
					level_matrix[playery][playerx] = 0;
				}
				lastposx[0] = playerx;
				lastposy[0] = playery;
				playery++;
				level_matrix[playery][playerx] = 3;
				//gotoxy(1, 5);
				//printf("key:down   ");
				break;
			}
			case 'a': case 'A':
			{
				if (level_matrix[playery][playerx - 1] == 4 || level_matrix[playery][playerx + 1] == 4 || level_matrix[playery + 1][playerx] == 4 || level_matrix[playery - 1][playerx] == 4)
				{

				}
				else if (level_matrix[playery][playerx - 1] == 1 || level_matrix[playery][playerx + 1] == 1 || level_matrix[playery + 1][playerx] == 1 || level_matrix[playery - 1][playerx] == 1)
				{
					return 0;
				}
				else if (level_matrix[playery][playerx - 1] == 2)
				{
					level_matrix[playery][playerx - 1] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery - 1][playerx] == 2)
				{
					level_matrix[playery-1][playerx] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery + 1][playerx] == 2)
				{
					level_matrix[playery + 1][playerx] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery][playerx + 1] == 2)
				{
					level_matrix[playery][playerx + 1] = 0;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else
				{
					level_matrix[playery][playerx] = 0;
				}
				lastposx[0] = playerx;
				lastposy[0] = playery;
				playerx--;
				level_matrix[playery][playerx] = 3;
				//gotoxy(1, 5);
				//printf("key:left   ");
				break;
			}
			case 'd': case 'D':
			{
				if (level_matrix[playery][playerx - 1] == 4 || level_matrix[playery][playerx + 1] == 4 || level_matrix[playery + 1][playerx] == 4 || level_matrix[playery - 1][playerx] == 4)
				{

				}
				else if (level_matrix[playery][playerx - 1] == 1 || level_matrix[playery][playerx + 1] == 1 || level_matrix[playery + 1][playerx] == 1 || level_matrix[playery - 1][playerx] == 1)
				{
					return 0;
				}
				else if (level_matrix[playery][playerx - 1] == 2)
				{
					level_matrix[playery][playerx - 1] = 3;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery - 1][playerx] == 2)
				{
					level_matrix[playery-1][playerx] = 3;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery + 1][playerx] == 2)
				{
					level_matrix[playery + 1][playerx] = 3;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else if (level_matrix[playery][playerx + 1] == 2)
				{
					level_matrix[playery][playerx + 1] = 3;
					add_body();
					spawn_apple();
					if (apple_spawned != 0)
					{
						apple_spawned = 0;
					}
				}
				else
				{
					level_matrix[playery][playerx] = 0;
				}
				lastposx[0] = playerx;
				lastposy[0] = playery;
				playerx++;
				level_matrix[playery][playerx] = 3;
				//gotoxy(1, 5);
				//printf("key:right  ");
				break;
			}
			}
		}
		if (block_input == 0)
		{
			input_handler();
		}
		gotoxy(1, 1);
		printf("Snake -(Hello world 'C' project) game time: %d", game_tick); // it's not finished :(
		gotoxy(1, 2);
		printf("press w, s, a, d to move.\n \n");
		delta_time++;
		render_level();
		if (apple_spawned == 0)
		{
			spawn_apple();
		}
		block_input = 0;
	}
}