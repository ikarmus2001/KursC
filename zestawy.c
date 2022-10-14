#include "zestawy.h"

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

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
int zestaw2_3()
{
	setlocale(LC_ALL, "");
	int zakres_dolny=1, zakres_gorny=100, zgadywana_liczba, ilosc_prob, powtorz=1;
	char odp;
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
		case 'N':
			while(powtorz)
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