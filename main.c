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

//int main()
//{
//	zestaw4_2();
//
//	return 0;
//}

void zamien(double *first, double *second) 
{
    double tmp = *first;
    *first = *second;
    *second = tmp;
}

int main(void) 
{

    int T;
    double j = 0.00, k = 0.00;
    

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s%s", &j, &k);
        double* jptr = &j, * kptr = &k;
        printf("j ma wartosc %f i jest przechowywany pod adresem %p\n", j, &j);//%p pointer address
        printf("k ma wartosc %f i jest przechowywany pod adresem %p\n", k, &k);

        zamien(&j, &k);

        printf("j ma wartosc %f i jest przechowywany pod adresem %p\n", *jptr, &jptr);//%p pointer address
        printf("k ma wartosc %f i jest przechowywany pod adresem %p\n", *kptr, &kptr);
    }
    return 0;
}


//ptr = &k;
    //printf("\n");
//printf("ptr ma wartosc %p i jest przechowywany po adresem %p\n", ptr, &ptr);
    //printf("Wartosc, na ktora wskazyje ptr to  %d\n", *ptr);
    //printf("Rozmiar int  %ld bajtow\n", sizeof(int));
    //printf("\n");
    //printf("Zobacz roznice: ptr: %p,  ptr + 1: %p\n", ptr, ptr + 1);
    //printf("ptr: %d,  ptr + 1: %d\n", *ptr, *(ptr + 1));



//6.1

//void my_split(const char source*, char* first, char* second, const char delim)
//{
//
//}

/*int main(void) {
    int max_n = 200;
    char zrodlo[max_n];
    char strA[max_n];
    char strB[max_n];
    int T;
    scanf("%d%*c", &T);
    for (int i = 0; i < T; i++) {
        fgets(zrodlo, max_n, stdin);
        my_split(zrodlo, strA, strB, ';');
        printf("Pierwszy: %s\n", strA);
        printf("Drugi: %s\n", strB);
    }

}*/
