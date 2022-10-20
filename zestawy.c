#include "zestawy.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void zestaw1_0()
{
	printf("%s", "Hello World");
}

void zestaw1_1()
{
	int ilosc_liczb, n;
	scanf_s("%d", &ilosc_liczb);
	for (int i = 0; i < ilosc_liczb; i++)
	{
		scanf_s("%d", &n);
		printf("%d\t%d\t%d\n", n, n * n, n * n * n);
	}
}

int zestaw2_0()
{
	int ilosc_operacji, l1, l2, wynik = 0;
	char znak_operacji;
	char err[13] = "Bledne dane!";
	scanf("%d", &ilosc_operacji);
	for (int i = 0; i < ilosc_operacji; i++)
	{
		scanf("%d%c%d", &l1, &znak_operacji, &l2);
		switch (znak_operacji)
		{
		case '+':
			wynik = l1 + l2;
			break;
		case '-':
			wynik = l1 - l2;
			break;
		case '*':
			wynik = l1 * l2;
			break;
		default:
			if (l2 != 0 && znak_operacji == '/')
			{
				wynik = l1 / l2;
				break;
			}
			printf("%s", err);
			return 1;

		}
		printf("%d%c%d = %d\n", l1, znak_operacji, l2, wynik);
	}
	return 1;
}

int zestaw2_1()
{
	int ilosc_testow, tmp, max = 0, min = 0;
	scanf("%d", &ilosc_testow);
	for (int i = 0; i < ilosc_testow; i++)
	{
		scanf("%d", &tmp);
		if (tmp < 0) {
			printf("Pusty ciag danych\n");
			return 1;
		}

		min = tmp;
		max = tmp;
		while (1)
		{
			scanf("%d", &tmp);
			if (tmp < 0) break;
			if (tmp > max) max = tmp;
			if (tmp < min) min = tmp;
		}
		printf("Najwieksza wczytana liczba to %d\n", max);
		printf("Najmniejsza wczytana liczba to %d\n", min);
	}
	return 1;
}

int zestaw2_2()
{
	int ilosc_linii, licznik = 0, znaki = 0;
	char aktualny, litera;
	char msg[31] = "Czestotliwosc wystepowania to ";
	scanf("%d%*c", &ilosc_linii);
	for (int i = 0; i < ilosc_linii; i++)
	{
		znaki = 0;
		licznik = 0;

		scanf("%c\n", &litera);
		printf("Zliczany znak to: %c\n", litera);
		while ((aktualny = getchar()) != '\n')
		{
			if (litera == aktualny) licznik++;
			znaki++;
		}
		if (znaki == 0)
			printf("Tekst byl pusty.\n");
		else
			printf("%s%d %%\n", msg, (licznik * 100) / znaki);
	}
	return 0;
}

int zestaw2_3()
{
	setlocale(LC_ALL, "");
	int zakres_dolny = 1, zakres_gorny = 100, zgadywana_liczba, ilosc_prob, powtorz = 1;
	char odp;
	/*#define RAND_MAX = zakres_gorny;*/
	printf("Zaraz zgadnê liczbê, któr¹ sobie pomyœlisz [1, 100].\n\n");

	zgadywana_liczba = rand() % (zakres_gorny + 1 - zakres_dolny) + zakres_dolny;
	while (1)
	{
		powtorz = 1;
		printf("Czy Twoja liczba to %d? [T/N]\n", zgadywana_liczba);
		scanf("%c", &odp);
		switch (odp)
		{
		case 'T':
			printf("Uda³o siê!");
			return 0;
			break;  // na wszelki wypadek, return koñczy program
		case 'N':
			while (powtorz)
			{
				powtorz = 0;
				printf("Twoja liczba jest mniejsza [M] czy wiêksza [W] od %d?\n", zgadywana_liczba);
				scanf("%c", &odp);
				switch (odp)
				{
				case 'M':
				{
					zakres_gorny = zgadywana_liczba;
					zgadywana_liczba = rand() % (zakres_gorny + 1 - zakres_dolny) + zakres_dolny;
					break;
				}
				case 'W':
				{
					zakres_dolny = zgadywana_liczba;
					zgadywana_liczba = rand() % (zakres_gorny + 1 - zakres_dolny) + zakres_dolny;
					break;
				}
				default:
					powtorz = 1;
					printf("Poda³eœ nieprzewidzian¹ odpowiedŸ\n");
					break;
				}
			}
			break;
		default:
			printf("Poda³eœ nieprzewidzian¹ odpowiedŸ\n");
			break;
		}
	}
	return 1;
}

int NWD(int l1, int l2)
{
	int tmp;
	while (l2 != 0)
	{
		tmp = l2;
		l2 = l1 % l2;
		l1 = tmp;
	}

	return l1;
}

int zestaw4_0()
{
	int nwd, nww, l1, l2, ilosc_linii;

	scanf("%d%*c", &ilosc_linii);
	for (int i = 0; i < ilosc_linii; i++)
	{
		scanf("%d %d%*c", &l1, &l2);
		nwd = NWD(l1, l2);
		nww = l1 * l2 / (nwd);
		printf("nwd(%d, %d) = %d\n", l1, l2, nwd);
		printf("nww(%d, %d) = %d\n", l1, l2, nww);
	}
	return 0;
}

// iloœæ elementów w arrayu (bez jakis szczególnych zabezpieczeñ co do typu)
#define length(x)  (sizeof(x) / sizeof((x)[0]))
// via https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
// równie dobrze mog³em podaæ na sta³e 8, ale mo¿liwe ¿e bêdzie potrzeba rozbudowy funkcji

int funkcja4_1(int liczba)
{

	// (x-4)^2 = x^2 - 8x + 16
	int wspolczynniki_wielomianu[8] = { 3, 0, 0, 0, 0, 1, -9, 16 };
	int result = wspolczynniki_wielomianu[0];
	int size_t = length(wspolczynniki_wielomianu);
	for (int w = 1; w < size_t; w++)
	{
		result = result * liczba + wspolczynniki_wielomianu[w];
	}
	return result;
}

int zestaw4_1()
{
	int ilosc_linii, w_funkcja, l1, l2;
	scanf("%d%*c", &ilosc_linii);
	for (int i = 0; i < ilosc_linii; i++)
	{
		scanf("%d %d%*c", &l1, &l2);
		if (l1 > l2)
		{
			int tmp = l1;
			l1 = l2;
			l2 = tmp;
		}

		for (int j = l1; j <= l2; j++)
		{
			w_funkcja = funkcja4_1(j);
			printf("f(%d) = %d \n", j, w_funkcja);
		}
	}
	return 0;
}

int funkcja4_2(int liczba)
{
	int tmp;
	while (1)
	{
		tmp = liczba >> 1;
		if (tmp << 1 == liczba)
		{
			liczba = tmp;
			continue;
		}
		break;
	}
	return liczba;
}

int zestaw4_2()
{
	int ilosc_linii, liczba;
	scanf("%d%*c", &ilosc_linii);
	for (int i = 0; i < ilosc_linii; i++)
	{
		scanf("%d%*c", &liczba);
		printf("%d\n", funkcja4_2(liczba));
	}
	return 0;
}