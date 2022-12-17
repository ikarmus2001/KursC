//#include "zestawy.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#define ROZMIAR 30
#define ZA_MALO_PAMIECI 0

typedef struct wezel {
  char* tytul;
  char* autor;
  double cena;
  int ilosc;
  struct wezel* nastepny;
} ksiazka;

// Funkcja rozdziela zawartość linii względem separatora i przekazuje wartości do pozostałych zmiennych
void my_split(char* linia, char* tytul, char* autor, char* ilosc, char* cena, char separator) {

	memset(tytul, 0, sizeof(tytul));
	memset(autor, 0, sizeof(autor));
	memset(ilosc, 0, sizeof(ilosc));
	memset(cena, 0, sizeof(cena));

	int property_i = 0;
	int miejsce = 0;
	for (int i = 0; property_i < 4; i++) {
		if (linia[i] != separator) {
			switch (property_i) {
				case 0:
					tytul[miejsce] =  linia[i];
					break;
				case 1:
					autor[miejsce] = linia[i];
					break;
				case 2:
					ilosc[miejsce] = linia[i];
					break;
				case 3:
					cena[miejsce] = linia[i];
					break;
			}
			miejsce++;
		}
		else {
			switch (property_i) {
				case 0:
					tytul[miejsce] =  '\0';
					break;
				case 1:
					autor[miejsce] = '\0';
					break;
				case 2:
					ilosc[miejsce] = '\0';
					break;
				case 3:
					cena[miejsce] = '\0';
					break;
				}
			property_i++;
			miejsce = 0;
		}
	}
}

void push_back(ksiazka* nowy, ksiazka** pierwszy) {
	
	ksiazka* iterator = *pierwszy;

	if (iterator == NULL) //gdy pusta lista
	{
		*pierwszy = nowy;
		return;
	}

	while (iterator->nastepny != NULL) {
		iterator = iterator->nastepny;
	}

	iterator->nastepny = nowy;
}

void wyswietlKsiazke(int pozycja, ksiazka* pierwszy)
{
	ksiazka* biezacy = pierwszy;
	// if (!biezacy) {
	//     printf("W magazynie nie ma ksiazki o podanej pozycji\n");
	// 	return;
	// }
	for (int i = 0; i < pozycja; i++) {
		if (biezacy != NULL)
			biezacy = biezacy->nastepny;
	}
	printf("Ksiazka nr %d to: %s %s %d %f", 
		pozycja, biezacy->tytul, biezacy->autor, biezacy->ilosc, biezacy->cena);
}

bool wypelnijMagazyn(const char* nazwaPliku, ksiazka** pierwszy){

    FILE *fp = fopen (nazwaPliku, "r");
    if (fp == NULL) {
       printf("Brak pliku z danymi\n");
       return 0;
    }
    const int max_n = 500;
		char linia[max_n], *result;
		char tytul[200];
		char autor[100];
		char ilosc[10];
		char cena[20];
		char *frag;
		
	while(!feof(fp)){

       ksiazka *element;
       if ((element = (ksiazka*)malloc(sizeof(ksiazka))) == NULL ) {
          fprintf(stderr, "Za mało pamięci!\n");
          exit(ZA_MALO_PAMIECI);
       }
       result = fgets (linia, max_n, fp);
       my_split(linia, tytul, autor, ilosc, cena, ';');
       element->tytul = (char*) malloc((strlen(tytul) + 1) * sizeof(char));
       strcpy(element->tytul, tytul);

       element->autor = (char*) malloc((strlen(autor) + 1) * sizeof(char));
       strcpy(element->autor, autor);

       element->ilosc = atoi(ilosc);
       element->cena = atof(cena);

       //push_back(element, &(*pierwszy));
       push_back(element, pierwszy);
       }
    fclose(fp);
    return 1;
}

int main(){
  int T;
  ksiazka *pierwszy = NULL;
  scanf("%d", &T);
  for(int i = 0; i < T; i++){
    char NazwaPliku[200];
    int pozycja = 0;
    scanf("%s %d", NazwaPliku, &pozycja);
    bool sukces = wypelnijMagazyn(NazwaPliku, &pierwszy);
    if(sukces)
      wyswietlKsiazke(pozycja, pierwszy);
  }
return 0;
}