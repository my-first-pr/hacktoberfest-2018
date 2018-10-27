#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <math.h>

// Würfel von 0 bis 6
/*void gotoxy(short x, short y)													// ausgabe dieser funktion ist die neue Mausposition.
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(hCon, pos);
}*/


int main()
{
	int zufallszahl = 0;
	int zaehler = 0;

	printf("Wuerfeln bis die Zahl 6 kommt.\n");

	srand((unsigned)time(NULL));

	do
	{
		Sleep(500);
		zufallszahl = (rand() % 6 + 1);
		printf("gewuerfelt : %i\n",zufallszahl);
		zaehler++;	
		if (zufallszahl == 1)
		{
			printf("+---------+\n");
			printf("|         |\n");
			printf("|    O    |\n");
			printf("|         |\n");
			printf("+---------+\n");
		}
		else if (zufallszahl == 2 )
		{
			printf("+---------+\n");
			printf("|  O      |\n");
			printf("|         |\n");
			printf("|      O  |\n");
			printf("+---------+\n");
		}
		else if (zufallszahl == 3)
		{
			printf("+---------+\n");
			printf("|  O      |\n");
			printf("|    O    |\n");
			printf("|      O  |\n");
			printf("+---------+\n");
		}
		else if (zufallszahl == 4)
		{
			printf("+---------+\n");
			printf("|  O   O  |\n");
			printf("|         |\n");
			printf("|  O   O  |\n");
			printf("+---------+\n");
		}
		else if (zufallszahl == 5)
		{
			printf("+---------+\n");
			printf("|  O   O  |\n");
			printf("|    O    |\n");
			printf("|  O   O  |\n");
			printf("+---------+\n");
		}
		else if (zufallszahl == 6)
		{
			printf("+---------+\n");
			printf("|  O   O  |\n");
			printf("|  O   O  |\n");
			printf("|  O   O  |\n");
			printf("+---------+\n");
		}
		//gotoxy(1, 2);
	} while (zufallszahl != 6);

	//gotoxy(1, 8);
	printf("Anzahl der Wuerfe : %i\n",zaehler);
	system("pause");

	return 0;
}

/*
Wuerfeln bis die Zahl 6 kommt.
gewuerfelt : 5
+---------+
|  O   O  |
|    O    |
|  O   O  |
+---------+
gewuerfelt : 5
+---------+
|  O   O  |
|    O    |
|  O   O  |
+---------+
gewuerfelt : 4
+---------+
|  O   O  |
|         |
|  O   O  |
+---------+
gewuerfelt : 1
+---------+
|         |
|    O    |
|         |
+---------+
gewuerfelt : 2
+---------+
|  O      |
|         |
|      O  |
+---------+
gewuerfelt : 4
+---------+
|  O   O  |
|         |
|  O   O  |
+---------+
gewuerfelt : 2
+---------+
|  O      |
|         |
|      O  |
+---------+
gewuerfelt : 3
+---------+
|  O      |
|    O    |
|      O  |
+---------+
gewuerfelt : 2
+---------+
|  O      |
|         |
|      O  |
+---------+
gewuerfelt : 4
+---------+
|  O   O  |
|         |
|  O   O  |
+---------+
gewuerfelt : 5
+---------+
|  O   O  |
|    O    |
|  O   O  |
+---------+
gewuerfelt : 1
+---------+
|         |
|    O    |
|         |
+---------+
gewuerfelt : 3
+---------+
|  O      |
|    O    |
|      O  |
+---------+
gewuerfelt : 4
+---------+
|  O   O  |
|         |
|  O   O  |
+---------+
gewuerfelt : 3
+---------+
|  O      |
|    O    |
|      O  |
+---------+
gewuerfelt : 3
+---------+
|  O      |
|    O    |
|      O  |
+---------+
gewuerfelt : 4
+---------+
|  O   O  |
|         |
|  O   O  |
+---------+
gewuerfelt : 1
+---------+
|         |
|    O    |
|         |
+---------+
gewuerfelt : 6
+---------+
|  O   O  |
|  O   O  |
|  O   O  |
+---------+
Anzahl der Wuerfe : 19
Drücken Sie eine beliebige Taste . . .
*/
