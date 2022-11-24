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

// w Visual Studio (22) kompilator krzyczy
// o 'niebezpiecznych' funkcjach (printf_s i scanf_s)
#define _CRT_SECURE_NO_WARNINGS
//#define ROZMIAR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Dana jest struktura książka
struct ksiazka {
	char autor[255];
	char tytul[255];
	unsigned ilosc;
	float cena;
};

bool wypelnijMagazyn(const char* nazwaPliku, struct ksiazka* magazyn)
{
	FILE* fp;
	char* result;
	char napis[ROZMIAR];
	struct ksiazka* k;

	fp = fopen(nazwaPliku, "r");
	if (fp == NULL)
	{
		printf("Nie można otworzyć pliku\n");
		return false;
	}
	for (int i = 0; i < ROZMIAR; i++)
	{
		k = (struct ksiazka*)malloc(sizeof(struct ksiazka));
		result = fgets(napis, 100, fp);
		fscanf(fp, "%[^\ ]s;%s;%d;%lf", &k->tytul, &k->autor, &k->ilosc, &k->cena);
		magazyn[i] = *k;
		free(k);
	}
	fclose(fp);
	return true;
}

void wyswietlKsiazke(int pozycja, struct ksiazka* magazyn)
{

}

int main(void) {

	// dana jest tablica magazyn przechowująca obiekty struktury książka
	struct ksiazka magazyn[ROZMIAR];
	int T;
	int pozycja;
	char NazwaPliku[200];

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s %d", NazwaPliku, &pozycja);
		bool sukces = wypelnijMagazyn(NazwaPliku, magazyn);
		if (sukces)
			wyswietlKsiazke(pozycja, magazyn);
	}
}
