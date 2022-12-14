#pragma region Zadanie 7_0
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 50

// Dana jest struktura książka
struct ksiazka {
	char autor[255];
	char tytul[255];
	unsigned ilosc;
	float cena;
};

bool wypelnijMagazyn(const char* nazwaPliku, struct ksiazka* magazyn) {
	FILE* fp;
	char* result;


	fp = fopen(nazwaPliku, "r");
	if (fp == NULL) {
		printf("Nie można otworzyć pliku\n");
		return false;
	}

	char buffer[700];
	for (int j = 0; j < 30; j++) {
		char tytul_str[255];
		char autor_str[255];
		char float_str[15];
		char* napis;
		int indeks = 0;
		int liczba = 0;
		float cena;

		int property_i = 0;
		napis = tytul_str;

		fgets(buffer, 700, fp);
		for (size_t i = 0; property_i < 4; i++) {
			if (buffer[i] != ';') {
				if (property_i != 2) {
					napis[indeks] = buffer[i];
					indeks++;
					continue;
				}
				else {
					liczba = liczba * 10 + (buffer[i] - '0');
					continue;
				}
			}
			else {
				if (property_i != 2)
					napis[indeks] = '\0';
				napis[254] = '\0';

				switch (property_i) {
				case 0:
					napis = autor_str;
					break;
				case 1:
					break;
				case 2:
					napis = float_str;
					break;
				case 3:
					cena = (float)atof(napis);
					break;
				}
				indeks = 0;
				property_i++;
			}
		}

		struct ksiazka k;
		strcpy(k.autor, autor_str);
		strcpy(k.tytul, tytul_str);
		k.ilosc = liczba;
		k.cena = cena;
		magazyn[j] = k;
	}
	fclose(fp);
	return true;
}

void wyswietlKsiazke(int pozycja, struct ksiazka* magazyn)
{
	struct ksiazka* k = &magazyn[pozycja];
	printf("Ksiazka nr %d to: %s %s %d %f", pozycja, k->tytul, k->autor, k->ilosc, k->cena);
}

int zadanie7_0(void)
{
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

#pragma endregion

// Wspomniany na zajęciach fscanf z poodbnego zadania
// fscanf(fp, "%[^\ ]s;%s;%d;%lf", &k->tytul, &k->autor, &k->ilosc, &k->cena);