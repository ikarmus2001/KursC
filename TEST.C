#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 30

struct ksiazka{
  char autor[32];
  char tytul[63];
  unsigned ilosc;
  float cena;
};

//typedef struct {
//char autor[32];
//char tytul[63];
//unsigned ilosc;
//float cena;
//}ksiazka;

int main(void){
   struct ksiazka magazyn[ROZMIAR];//tablica o nazwie magazyn przechowujaca "obiekty" struktury ksiazka
   //ksiazka magazyn[ROZMIAR];
   magazyn[0].cena = 0;
   strcpy(magazyn[0].autor, "autor0");

   magazyn[1].cena = 1;
   strcpy(magazyn[1].autor, "autor1");

   magazyn[2].cena = 2;
   strcpy(magazyn[2].autor, "autor2");

   printf("%f, %s\n", magazyn[0].cena, magazyn[0].autor);  // 0.000000, autor0
   printf("%f, %s\n", magazyn[1].cena, magazyn[1].autor);  // 1.000000, autor1
   printf("%f, %s\n", magazyn[2].cena, magazyn[2].autor);  // 2.000000, autor2
   
   printf("Wskaznikowo\n");
   
   struct ksiazka *p = magazyn;
   //ksiazka *p = magazyn;
   
   printf("%f, %s\n", p[0].cena, p[0].autor);  // 0.000000, autor0
   //albo:
   printf("%f, %s\n", p->cena, p->autor);  // 0.000000, autor0
   p++;
   printf("%f, %s\n", p->cena, p->autor);  // 1.000000, autor1
   printf("%f, %s\n", (p + 1)->cena, (p + 1)->autor);  // 2.000000, autor2
   return 0;
}