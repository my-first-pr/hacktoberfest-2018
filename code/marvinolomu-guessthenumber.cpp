#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>




int main()
{
	short versuche = 0;
	short zufallszahl = 0;
	short eingabe = 0;
	bool neustart = false;
	char zustand = 'l'; // l = laufen, y = neustarten, n = schließen

	srand((unsigned)time(NULL));

	zufallszahl = (rand() % 15 + 1);

	printf("erraten sie die Zahl 1 - 15 \n");

	do
	{
		if (neustart == true)
		{
			fflush(stdin);
			printf("\nWollen Sie das Spiel nochmal spielen?(ja/nein)\n");
			printf("\n(ja/nein) ");
			char eingabeChar = '0';

			
			eingabeChar = (char) _getch();
			if (eingabeChar == 'l')
			{
				eingabeChar = '0';
			}

			zustand = eingabeChar;
			if (zustand == 'N' || zustand == 'n')
			{
				printf("%c\n", zustand);
				break;
			}
			else if (zustand == 'J' || zustand == 'j')
			{
				versuche = 0;
				neustart = 0;
				zufallszahl = (rand() % 15 + 1);
				eingabe = 0;
				neustart = false;
				
				printf("%c\n", zustand);
				zustand = 'l';
				printf("neues Spiel.\n\n");

			}
			else if (zustand == 'l' || zustand == 'L')
			{
				neustart = false;
			}
			else
			{
				zustand = '0';
				neustart = true;
			}
		}

		if (zustand != '0')
		{


			printf("eingabe:");
			scanf_s("%i", &eingabe);
			versuche++;

			if (eingabe == zufallszahl)
			{
				printf("Richtige Zahl:%i\n", zufallszahl);
				printf("eingegebene Zahl:%i\n", eingabe);
				printf("Sie haben Gewonnen!\n", eingabe);
				printf("Anzahl der Versuche:%i\n", versuche);

				zustand = '0';
				neustart = true;
			}
			else {
				if (versuche > 2)
				{
					printf("\n\nVersuche:%i \n", versuche);
					printf("Sie haben Verloren.\n\n");
					printf("gesuchte Zahl:%i\n", zufallszahl);
					printf("eingegebene Zahl:%i\n\n\n", eingabe);

					zustand = '0';
					neustart = true;
				}
				else {
					if (eingabe > zufallszahl)
					{
						printf("Zahl:%d ist zu gross.\n", eingabe);
					}
					else
					{
						printf("Zahl:%d ist zu klein.\n", eingabe);
					}
				}
			}
			if (zustand == 'l' ) {
				printf("Anzahl der Versuche:%i\n", versuche);
			}
		}
	} while (true);
	printf("\n");
	system("pause");

	return 0;
}

/*
erraten sie die zufaellige Zahl von 1 - 15!
Geben Sie eine Zahl ein:1
Zahl:1 ist zu klein.
Anzahl der Versuche:1
Geben Sie eine Zahl ein:2
Zahl:2 ist zu klein.
Anzahl der Versuche:2
Geben Sie eine Zahl ein:8
Richtige Zahl:8
eingegebene Zahl:8
Sie haben Gewonnen!
Anzahl der Versuche:3

Wollen Sie das Spiel nochmal spielen? (ja/nein)

(ja/nein) j
neues Spiel.

Geben Sie eine Zahl ein:8
Zahl:8 ist zu gross.
Anzahl der Versuche:1
Geben Sie eine Zahl ein:5
Zahl:5 ist zu gross.
Anzahl der Versuche:2
Geben Sie eine Zahl ein:4


Versuche:3
Sie haben Verloren. 

gesuchte Zahl:2
eingegebene Zahl:4



Wollen Sie das Spiel nochmal spielen? (ja/nein)

(ja/nein) n

Drücken Sie eine beliebige Taste . . .
*/