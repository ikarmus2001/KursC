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

int main()
{
	zestaw4_2();

	return 0;
}

