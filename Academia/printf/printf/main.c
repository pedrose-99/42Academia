#include "ft_printf.h"
#include <limits.h>
#include "ft_print_char.c"
#include "ft_print_hexa.c"
#include "ft_print_hexap.c"
#include "almacendatos.c"
#include "ft_print_str.c"
#include "ft_print_unsig.c"
#include "ft_printf.c"
#include "ft_printf_int.c"
#include "ft_printf_utils.c"
#include "funciones_extra.c"

int		main(void)
{
//	printf("%i\n",ft_printf("this %s is empty\n", ""));
	static char *s_hidden = "hi low\0don't print me lol\0";
//	printf("%i\n",printf("this %s is empty\n", ""));
	//	printf("%i\n",ft_printf("%*d\n", -10, 4));

//	printf("%i\n",printf("%15.*d\n", 10, 4));
//	printf("%i\n",ft_printf("%15.*d\n", 10, 4));



	//printf("%i\n",ft_printf("%09s", "hola"));
//	ft_printf("%d", 2);
//	ft_printf("%.s", "hello");
//	printf("%i\n",printf("%.0s", "hello"));
//	printf("%i\n",printf("%5%);
		//printf("%i\n",printf("%09s", "hola"));

    printf("%0.0i%0.0s%0.0x%0.0c%0.0d\n", 5, " Hola ", (short int)-1, ' ', INT_MIN);
    ft_printf("%0.0i%0.0s%0.0x%0.0c%0.0d\n", 5, " Hola ", (short int)-1, ' ', INT_MIN);
//
}
/*	------------------	FT_PRINT_CHAR.C--------------------------------

	ft_printf("%-0*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha (ignora el 0)
	ft_printf("%0*cFIN\n", 4, 'x');		// añade (width - 1(char)) 0s a la izq
	ft_printf("%-*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha
	ft_printf("%-cFIN\n", 'x');			// no influye el - sin otro flag
	ft_printf("%4c\n", 'x');				// añade * espacios a la izq - 1(char)
	ft_printf("%10c\n", 'x');
	printf("hasta aqui\n");
	printf("%-0*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha (ignora el 0)
	printf("%0*cFIN\n", 4, 'x');		// añade (width - 1(char)) 0s a la izq
	printf("%-*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha
	printf("%-cFIN\n", 'x');			// no influye el - sin otro flag
	printf("%4c\n", 'x');				// añade * espacios a la izq - 1(char)
	printf("%10c\n", 'x');	
*/

/*
------------------	FT_PRINT_HEXAAAAA.C--------------------------------
	ft_printf("%-0*.3xFIN\n", 4, 42);
	ft_printf("%0*.1XFIN\n", 4, 42);
	ft_printf("%-*.3xFIN\n", 4, 42);
	ft_printf("%*XFIN\n", 4, 42);
	ft_printf("%04.1XFIN\n", 42);
		printf("hasta aqui\n");

	printf("%-0*.3xFIN\n", 4, 42);
	printf("%0*.1XFIN\n", 4, 42);
	printf("%-*.3xFIN\n", 4, 42);
	printf("%*XFIN\n", 4, 42);
	printf("%04.1XFIN\n", 42);

	*/

/*
------------------	FT_PRINT_HEXAAAAAPPPPPPPP.C--------------------------------

char *ptr; 
	ptr = ft_strdup("prueba puntero");

	ft_printf("%-pFIN\n", ptr);
	ft_printf("%0pFIN\n", ptr);
	ft_printf("%-0pFIN\n", ptr);
	ft_printf("%*pFIN\n", 20, ptr); // si
	ft_printf("%-*pFIN\n", 20, ptr); // si
	ft_printf("%0*pFIN\n", 20, ptr);
	ft_printf("%-0*pFIN\n", 20, ptr);
	ft_printf("%.3pFIN\n", ptr);
	ft_printf("%-.3pFIN\n", ptr);
	ft_printf("%0.3pFIN\n", ptr);
	ft_printf("%-0.3pFIN\n", ptr);
	// hasta aquí funciona incluso con undefined behavior
	ft_printf("%.17pFIN\n", ptr);
	ft_printf("%-.17pFIN\n", ptr);
	ft_printf("%0.17pFIN\n", ptr);
	ft_printf("%-0.17pFIN\n", ptr);
	ft_printf("%*.12pFIN\n", 20, ptr);
	ft_printf("%-*.3pFIN\n", 20, ptr);
	ft_printf("%0*.3pFIN\n", 20, ptr);
	ft_printf("%-0*.3pFIN\n", 20, ptr);
	// ARREGLAR ESTA PARTE (aunque no haría falta porque es undefined behavior)
	ft_printf("%*.17pFIN\n", 20, ptr);
	ft_printf("%-*.17pFIN\n", 20, ptr);
	ft_printf("%0*.17pFIN\n", 20, ptr);
	ft_printf("%-0*.17pFIN\n", 20, ptr);
		printf("hasta aqui\n");

	printf("hasta aqui \n");
	printf("%-pFIN\n", ptr);
	printf("%0pFIN\n", ptr);
	printf("%-0pFIN\n", ptr);
	printf("%*pFIN\n", 20, ptr); // si
	printf("%-*pFIN\n", 20, ptr); // si
	printf("%0*pFIN\n", 20, ptr);
	printf("%-0*pFIN\n", 20, ptr);
	printf("%.3pFIN\n", ptr);
	printf("%-.3pFIN\n", ptr);
	printf("%0.3pFIN\n", ptr);
	printf("%-0.3pFIN\n", ptr);
	// hasta aquí funciona incluso con undefined behavior
	printf("%.17pFIN\n", ptr);
	printf("%-.17pFIN\n", ptr);
	printf("%0.17pFIN\n", ptr);
	printf("%-0.17pFIN\n", ptr);
	ft_printf("%*.12pFIN\n", 20, ptr);
	ft_printf("%-*.3pFIN\n", 20, ptr);
	ft_printf("%0*.3pFIN\n", 20, ptr);
	ft_printf("%-0*.3pFIN\n", 20, ptr);
	// ARREGLAR ESTA PARTE (aunque no haría falta porque es undefined behavior)
	ft_printf("%*.17pFIN\n", 20, ptr);
	ft_printf("%-*.17pFIN\n", 20, ptr);
	ft_printf("%0*.17pFIN\n", 20, ptr);
	ft_printf("%-0*.17pFIN\n", 20, ptr);
	*/


/*
------------------------------PRINT_STR.C--------------------------------------------
	ft_printf("%0*.7sFIN\n", 10, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la izq en forma de 0s
	ft_printf("%-0*.2sFIN\n", 4, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la dcha en forma de espacios
	ft_printf("%-*sFIN\n", 6, "hola");		// añade (width - len(char *)) a la dcha
	ft_printf("%-*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a dcha
	ft_printf("%*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a izq
	ft_printf("%*sFIN\n", 6, "hola");			// añade (width - len(char *)) espacios a la izq
	ft_printf("%-.2sFIN\n", "hola");
	ft_printf("%0.2sFIN\n", "hola");
		// Estos ejemplos de flags no influyen en la cadena
	ft_printf("X%-sFIN\n", "hola");
	ft_printf("X%0sFIN\n", "hola");
	ft_printf("X%-0sFIN\n", "hola"); // no mirar el printf no funcions con -0
	ft_printf("X%0.7sFIN\n", "hola");
	ft_printf("X%-.7sFIN\n", "hola");
	printf("hasta aqui\n");
	printf("%0*.7sFIN\n", 10, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la izq en forma de 0s
	printf("%-0*.2sFIN\n", 4, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la dcha en forma de espacios
	printf("%-*sFIN\n", 6, "hola");		// añade (width - len(char *)) a la dcha
	printf("%-*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a dcha
	printf("%*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a izq
	printf("%*sFIN\n", 6, "hola");			// añade (width - len(char *)) espacios a la izq
	printf("%-.2sFIN\n", "hola");
	printf("%0.2sFIN\n", "hola");
		// Estos ejemplos de flags no influyen en la cadena
	printf("X%-sFIN\n", "hola");
	printf("X%0sFIN\n", "hola");
	printf("X%-0sFIN\n", "hola"); // no mirar el printf no funcions con -0
	printf("X%0.7sFIN\n", "hola");
	printf("X%-.7sFIN\n", "hola");
	*/


/*
-------------------------------------PRINT_UNSIGNED.C--------------------------
int		main(void)
{
	//printf("%0-6.3dg\n", 22);
	//print_spozero(22, 6, 6);
	//ft_printf("%0-6.3d", 22);
	ft_printf("%0-*.3uFIN\n", 4, 42);		// El orden en presentar los flags 0 y - es indiferente
	ft_printf("%0*.3uFIN\n", 4, -42);
	ft_printf("%-4.3uFIN\n", 42);
	ft_printf("%*uFIN\n", 4, 42);
	ft_printf("%04.1uFIN\n", 42);
	printf("hasta aqui\n");

	printf("%0-*.3uFIN\n", 4, 42);		// El orden en presentar los flags 0 y - es indiferente
	printf("%0*.3uFIN\n", 4, -42);
	printf("%-4.3uFIN\n", 42);
	printf("%*uFIN\n", 4, 42);
	printf("%04.1uFIN\n", 42);
}*/


/*
---------------------------------FT_PRINTF_INT.c--------------------------------
		print_string(f);
	else if (f->spec == 'u')
		print_unsigned_int(f);
	else if (f->spec == 'x')
		print_hexa_minus(f);
	else if (f->spec == 'X')
		print_hexa_mayus(f);
	else if (f->spec == '%')
		print_porcentaje(f); //tener en cuenta las mismas cosas que la c(o eso cree raul)
}
int		main(void)
{
	//printf("%0-6.3dg\n", 22);
	//print_spozero(22, 6, 6);
	//ft_printf("%0-6.3d", 22);
	ft_printf("%-0*.3dFIN\n", 4, 42);
	ft_printf("%0*.1dFIN\n", 4, -42);
	ft_printf("%-2.3dFIN\n", 42);
	ft_printf("%*dFIN\n", 4, -42);
	ft_printf("%-04.1dFIN\n", 42);
	ft_printf("%-*.5dFIN\n", 7, -42);
	ft_printf("%*.5dFIN\n", 7, -42);
	ft_printf("%*.7dFIN\n", 5, 42);
	ft_printf("%0*dFIN\n", 4, -42);
	ft_printf("%-dFIN\n", 42);
	ft_printf("%-0dFIN\n", 42);
	ft_printf("%0dFIN\n", 42);
	ft_printf("%*dFIN\n", 1, 42); 
	ft_printf("%0*dFIN\n", 1, 42);
	ft_printf("%.1dFIN\n", 42);
	ft_printf("%-.1dFIN\n", 42);
	ft_printf("%-*.2dFIN\n", 2, 42);
		printf("hasta aqui\n");

	printf("%-0*.3dFIN\n", 4, 42);									
	printf("%0*.1dFIN\n", 4, -42);		
	printf("%-2.3dFIN\n", 42);			
	printf("%*dFIN\n", 4, -42);		
	printf("%-04.1dFIN\n", 42);			
	printf("%-*.5dFIN\n", 7, -42);
	printf("%*.5dFIN\n", 7, -42);
	printf("%*.7dFIN\n", 5, 42);
	printf("%0*dFIN\n", 4, -42);
	printf("%-dFIN\n", 42);
	printf("%-0dFIN\n", 42);
	printf("%0dFIN\n", 42);
	printf("%*dFIN\n", 1, 42); 
	printf("%0*dFIN\n", 1, 42);
	printf("%.1dFIN\n", 42);
	printf("%-.1dFIN\n", 42);
	printf("%-*.2dFIN\n", 2, 42);*/