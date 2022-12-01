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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
    int wartosc;
    struct wezel* nastepny;
    //struct wezel *poprzedni;  //w przypadku listy dwukierunkowej
} Wezel;
Wezel* pierwszy = NULL;


/**********************************************************/
void wypisz(/*Wezel* pierwszy*/) {
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
void push_back(/*Wezel** pierwszy, */int liczba) 
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


#pragma region dokonczyc8_0


/**********************************************************/
// Funkcja usuwa pierwszy element z jednokierunkowej listy

int pop_front(/*Wezel **pierwszy, */int *result)
{
   if (!pierwszy)
       return -1;
   
   &result = &pierwszy->wartosc;
   pierwszy = pierwszy->nastepny;
   free(pierwszy);
   return 0;
}

/**********************************************************/

int main() 
{
   int T;
   char linia[20];
   int x, y;
   


   scanf("%d", &T);
   for (int i = 0; i < T; i++) 
   {
       scanf("%s", linia);
       if (strstr(linia, "push_back")) 
       {
           scanf("%d", &x);
           printf("test %d: %s %d\n", i, linia, x);
           push_back(&pierwszy, x);
           wypisz(pierwszy);
       }
       else {
           printf("test %d: %s\n", i, linia);
           if (pop_front(pierwszy, y) == 0) 
           {
               printf("Zwrocono wartosc %d\n", y);
           }
           wypisz(pierwszy);
       }
   }
   return 0;
}

 
#pragma endregion

// Wezel* get_elem(Wezel **node, int element)
// {
//     Wezel *tmp = node;
//     if (tmp == NULL)
//     {
//         printf("Pusta lista");
//         return NULL;
//     }
//     for (int i = 0; i < element; i++)
//     {
//         if (tmp->nastepny != NULL)   // <------------
//             *tmp = *tmp->nastepny;
//         else
//         {
//             printf("Lista za krotka");
//             return NULL;
//         }
//     }
        
//     printf("Na pozycji %d znajduje sie wartosc %d \t", element, tmp->wartosc);
//     return tmp;
// }

// int main() {
//     int dlugosc, pozycja;
//     int x = 0;
//     Wezel* element;
//     Wezel* pierwszy = NULL;

//     //wczytaj wartosci i zbuduj liste
//     scanf("%d", &dlugosc);
//     for (int i = 0; i < dlugosc; i++) 
//     {
//         scanf("%d", &x);
//         push_back(&pierwszy, x);
//     }

//     //wypisz liste
//     Wezel* biezacy = pierwszy;
//     if (!biezacy) {
//         printf("Pusta lista\n");
//     }
//     while (biezacy != NULL) {
//         printf("%d\t", biezacy->wartosc);
//         biezacy = biezacy->nastepny;
//     }
//     printf("\n");

//     //przetestuj funkcję get_elem dla pozycji 3-ciej
//     get_elem(&pierwszy, 3);

//     //przetestuj funkcję get_elem dla pozycji 0-wej
//     get_elem(&pierwszy, 0);

//     //przetestuj funkcję get_elem dla pozycji ostatniej
//     get_elem(&pierwszy, dlugosc);

//     //przetestuj funkcję get_elem dla pozycji spoza listy
//     get_elem(&pierwszy, dlugosc + 1);

//     //przetestuj funkcję get_elem dla pozycji drugiej (gdy lista jest pusta)
//     pierwszy = NULL;
//     get_elem(pierwszy, dlugosc);

//     return 0;
// }