//#include "zestawy.h"
/*zestaw1_0(); return 1;*/
/*zestaw1_1(); return 1;*/

/*return zestaw2_0();*/
/*return zestaw2_1();*/
/*return zestaw2_2();*/
//return zestaw2_3();

/*return zestaw4_0();*/
/*return zestaw4_1();*/
/*return zestaw4_2();*/

//return zestaw5_0();

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define ROZMIAR 5
unsigned tablica[ROZMIAR][ROZMIAR];

//3 - 5
//4 - 7
//5 - 9
//6 - 11

void wyswietl(void)
{
	for (int i = 0; i < ROZMIAR; i++)
	{
		for (int j = 0; j < ROZMIAR - 1; j++) printf("%d\t", tablica[i][j]);
		printf("%d\n", tablica[i][ROZMIAR - 1]);
	}
	printf("\n\n");
}

/*Funkcja wypelnia tablice po spirali*/
void wypelnij() 
{
	int wielkosc = ROZMIAR;
	unsigned int x = 0, y = 0, c = 0;
	int operacja[4] = { 1, 0, -1, 0 };
	int operacja_x, operacja_y;
	for (int obrot = 0; obrot < (ROZMIAR * 2) - 1; obrot++)
	{
		//if (obrot % 2 == 1)
		//{
		//	wielkosc = wielkosc - 1;
		//	/*if (x + operacja_x > wielkosc) x--;
		//	else if (y + operacja_y > wielkosc)  y--;*/
		//}

		operacja_x = operacja[(obrot + 3) % 4];  // zaczynamy od ostatniego 0
		operacja_y = operacja[obrot % 4];  // zaczynamy od pocz¹tku
		
		while (x + operacja_x <= wielkosc && x + operacja_x >= 0 && (y + operacja_y) <= wielkosc && y + operacja_y >= 0)
		{
			tablica[x][y] = ++c;
			x = x + operacja_x;
			y = y + operacja_y;
			
			wyswietl();
		}
	}
}



int main(void) {
	wypelnij();
	wyswietl();
	return 0;
}

