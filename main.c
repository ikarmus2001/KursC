//#include "zestawy.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
    int wartosc;
    struct wezel* nastepny;
    //struct wezel *poprzedni;  //w przypadku listy dwukierunkowej
} Wezel;

/**********************************************************/
void wypisz(Wezel* pierwszy) {
    Wezel* biezacy = pierwszy;

    if (!biezacy) {
        printf("Pusta lista\n");
    }

    while (biezacy != NULL) {
        printf("%d\n", biezacy->wartosc);
        biezacy = biezacy->nastepny;
    }
    printf("\n");
}
/**********************************************************/

//wstaw element na koniec listy
void push_back(Wezel** pierwszy, int liczba) 
{
    Wezel* element;  // konstruujemy nowy węzeł
    Wezel* iterator = *pierwszy;

    if ((element = (Wezel*)malloc(sizeof(Wezel))) == NULL) 
    {
        fprintf(stderr, "Za mało pamięci!\n");
        exit(ZA_MALO_PAMIECI);
    }
    element->wartosc = liczba;
    element->nastepny = NULL;

    if (iterator == NULL) //gdy pusta lista
    {
        *pierwszy = element;
        return;
    }

    while (iterator->nastepny != NULL) {
        iterator = iterator->nastepny;
    }

    iterator->nastepny = element;
}

Wezel* get_elem(Wezel **node, int element)
{
    Wezel* tmp = *node;
    if (tmp == NULL)
    {
        printf("Pusta lista\n");
        return NULL;
    }
    for (int i = 0; i < element; i++)
    {
        if (tmp->nastepny != NULL)
            tmp = tmp->nastepny;
        else
        {
            printf("Lista za krotka\n");
            return NULL;
        }
    }
    if (tmp->nastepny != NULL)
        printf("Na pozycji %d znajduje sie wartosc %d \n", element, tmp->wartosc);
    else
        printf("Na pozycji ostatniej znajduje sie wartosc %d \n", tmp->wartosc);
    return tmp;
}

int main() {
    int dlugosc, pozycja;
    int x = 0;
    Wezel* pierwszy = NULL;

    //wczytaj wartosci i zbuduj liste
    scanf("%d", &dlugosc);
    for (int i = 0; i < dlugosc; i++) 
    {
        scanf("%d", &x);
        push_back(&pierwszy, x);
    }

    //wypisz liste
    Wezel* biezacy = pierwszy;
    if (!biezacy) {
        printf("Pusta lista");
    }
    else
    {
        printf("Lista:\t%d", biezacy->wartosc);
        biezacy = biezacy->nastepny;
        while (biezacy != NULL) {
            printf("\t%d", biezacy->wartosc);
            biezacy = biezacy->nastepny;
        }
    }
    printf("\n");

    //przetestuj funkcję get_elem dla pozycji 3-ciej
    get_elem(&pierwszy, 3);

    //przetestuj funkcję get_elem dla pozycji 0-wej
    get_elem(&pierwszy, 0);

    //przetestuj funkcję get_elem dla pozycji ostatniej
    get_elem(&pierwszy, dlugosc - 1);

    //przetestuj funkcję get_elem dla pozycji spoza listy
    get_elem(&pierwszy, dlugosc);

    //przetestuj funkcję get_elem dla pozycji drugiej (gdy lista jest pusta)
    pierwszy = NULL;
    get_elem(&pierwszy, 2);

    return 0;
}  
