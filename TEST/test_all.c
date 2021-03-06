/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:50:46 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/27 13:09:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INTMAX 2147483647
#define INTMIN -2147483648
#define UMAX 4294967295

#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "src/ft_printf.h"
#include <wchar.h>

void print_binaire(unsigned wc) //
{
	int i;
	printf("%d en binaire :\t", wc);
	for (i = 31; i >= 0; i--)
	{
		printf("%d", (wc >> i ) & 1);
		if (i % 4 == 0)
			printf(" ");
	}
	printf("\n"); 
}

/*
** le - 1 car tous les ft_printf ont un \n en plus
*/

void	print_error(int origin, int progra)
{
	if (origin != progra - 1)
		printf("\t\t\tERROR =  originale = %d et progra = %d !!!!!!!!!!!!!!! ERROR !!!!!!!!!!!!!! ERROR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n", origin, progra - 1);

}

int main()
{	int a = 0;
	int b = 0;	
	setlocale(LC_ALL,"");
/*printf("\n\n\n\t\t\t..-*  INT  *-..\n");
	printf("\t\t*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*\n");

	int origin = 0;
	int progra = 0;

	// PREMIERS TESTS :

	printf(" |%ld|\n", INTMIN);    		 // Warning %ld mais ok
	ft_printf("f|%ld|\n\n", INTMIN);

	printf(" |%d|\n", INTMAX);
	ft_printf("f|%d|\n\n", INTMAX);

	printf( " |%.0d|\n", 0 );
	ft_printf( "f|%.0d|\n\n", 0 );
	origin = printf(" |%.d|\n", 18888);
	progra = ft_printf("f|%.d|\n\n", 18888);
	print_error(origin, progra);

	origin = printf(" |\v\'He\allo\" %% \tword\\ \vhell \rYeah  \n");
	progra = ft_printf("f|\v\'He\allo\" %% \tword\\ \vhell \rYeah  \n\n");
	print_error(origin, progra);

	origin = printf(" |%15d|\n", 01);
	progra = ft_printf("f|%15d|\n\n", 01);
	print_error(origin, progra);

	origin = printf(" |%0d|\n", 1);
	progra = ft_printf("f|%0d|\n\n", 1);
	print_error(origin, progra);

	origin = printf(" |%05d|\n",2);
	progra = ft_printf("f|%05d|\n\n",2);
	print_error(origin, progra);

	origin = printf(" |%050d|\n",3);
	progra = ft_printf("f|%050d|\n\n",3);
	print_error(origin, progra);

	origin = printf(" |%0-50d|\n",4);		// warning 0 flag ignored with '-'
	progra = ft_printf("f|%0-50d|\n\n",4);
	print_error(origin, progra);

	origin = printf(" |%0-d|\n",4);			// warning 0 flag ignored with '-'
	progra = ft_printf("f|%0-d|\n\n",4);
	print_error(origin, progra);

	origin = printf(" |%0-d|\n",-4);		// warning 0 flag ignored with '-'
	progra = ft_printf("f|%0-d|\n\n",-4);
	print_error(origin, progra);

	origin = printf(" |%50d|\n",5);
	progra = ft_printf("f|%50d|\n\n",5);
	print_error(origin, progra);

	origin = printf(" |%0*d|\n",8, 6);
	progra = ft_printf("f|%0*d|\n\n",8, 6);
	print_error(origin, progra);

	origin = printf(" |%0-*d|\n",8, 7);		// warning 0 flag ignored with '-'
	progra = ft_printf("f|%0-*d|\n\n",8, 7);
	print_error(origin, progra);

	origin = printf(" |%0-*d|\n",-8, 8);	// warning 0 flag ignored with '-'
	progra = ft_printf("f|%0-*d|\n\n",-8, 8);
	print_error(origin, progra);

	origin = printf(" |%0*d|\n",8, 9);
	progra = ft_printf("f|%0*d|\n\n",8, 9);
	print_error(origin, progra);

	origin = printf(" |%0*d|\n",-8, 1);
	progra = ft_printf("f|%0*d|\n\n",-8, 1);
	print_error(origin, progra);

	origin = printf(" |%0*d|\n",8, 11111);
	progra = ft_printf("f|%0*d|\n\n",8, 11111);
	print_error(origin, progra);

	origin = printf(" |%0.*d|\n", 8, 12222);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.*d|\n\n", 8, 12222);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", 8, 13333);
	progra = ft_printf("f|%.*d|\n\n", 8, 13333);
	print_error(origin, progra);

	origin = printf(" |%0.*d|\n", 2, 14444);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.*d|\n\n", 2, 14444);
	print_error(origin, progra);

	origin = printf(" |%0.*d|\n", -15, 15555);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.*d|\n\n", -15, 15555);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", -15, 15555);
	progra = ft_printf("f|%.*d|\n\n", -15, 15555);
	print_error(origin, progra);

	origin = printf(" |%0.*d|\n", 15, 16666);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.*d|\n\n", 15, 16666);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", 15, 17777);
	progra = ft_printf("f|%.*d|\n\n", 15, 17777);
	print_error(origin, progra);

	origin = printf(" |%.d|\n", 18888);
	progra = ft_printf("f|%.d|\n\n", 18888);
	print_error(origin, progra);

	origin = printf(" |%040.d|\n", 1);			// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%040.d|\n\n", 1);
	print_error(origin, progra);

	origin = printf(" |%40.d|\n", 2);
	progra = ft_printf("f|%40.d|\n\n", 2);
	print_error(origin, progra);

	origin = printf(" |%-40.d|\n", 202);
	progra = ft_printf("f|%-40.d|\n\n", 202);
	print_error(origin, progra);

	origin = printf(" |%40.20d|\n", 3);
	progra = ft_printf("f|%40.20d|\n\n", 3);
	print_error(origin, progra);

	origin = printf(" |%40.2d|\n", 4);
	progra = ft_printf("f|%40.2d|\n\n", 4);
	print_error(origin, progra);

	origin = printf(" |%-40.20d|\n", 6);
	progra = ft_printf("f|%-40.20d|\n\n", 6);
	print_error(origin, progra);

	origin = printf(" |%20.20d| \n", 7);
	progra = ft_printf("f|%20.20d| \n\n", 7);
	print_error(origin, progra);

	origin = printf(" |%-20.20d| \n", 8);
	progra = ft_printf("f|%-20.20d| \n\n", 8);
	print_error(origin, progra);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.0d ]	précision 0:\n\n");

	origin = printf( " |%.0d|\n", 0 );
	progra = ft_printf( "f|%.0d|\n\n", 0 );
	print_error(origin, progra);

	origin = printf( " |%.*d|\n", 0, 0 );
	progra = ft_printf( "f|%.*d|\n\n", 0, 0 );
	print_error(origin, progra);

	origin = printf( " |%12.*d|\n", 0, 0 );
	progra = ft_printf( "f|%12.*d|\n\n", 0, 0 );
	print_error(origin, progra);

	origin = printf( " |%012.*d|\n", 0, 0 );	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf( "f|%012.*d|\n\n", 0, 0 );
	print_error(origin, progra);

	origin = printf( " |%.0d|\n", 1);
	progra = ft_printf( "f|%.0d|\n\n", 1);
	print_error(origin, progra);

	origin = printf( " |%.0d|\n", -15 );
	progra = ft_printf( "f|%.0d|\n\n", -15);
	print_error(origin, progra);

	origin = printf( " |%12.0d|\n", -15 );
	progra = ft_printf( "f|%12.0d|\n\n", -15);
	print_error(origin, progra);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]:\n\n");


	origin = printf( " |%1d|\n", 100);
	progra = ft_printf( "f|%1d|\n\n", 100);
	print_error(origin, progra);

	origin = printf( " |%01d|\n", 101);
	progra = ft_printf( "f|%01d|\n\n", 101);
	print_error(origin, progra);

	origin = printf( " |%3d|\n", 0);
	progra = ft_printf( "f|%3d|\n\n", 0);
	print_error(origin, progra);

	origin = printf( " |%3d|\n", -0);
	progra = ft_printf( "f|%3d|\n\n", -0);
	print_error(origin, progra);

	origin = printf( " |%5d|\n", 102);
	progra = ft_printf( "f|%5d|\n\n", 102);
	print_error(origin, progra);

	origin = printf( " |%05d|\n", -103);
	progra = ft_printf( "f|%05d|\n\n", -103);
	print_error(origin, progra);

	origin = printf( " |%30d|\n", 2147483647);
	progra = ft_printf( "f|%30d|\n\n", 2147483647);
	print_error(origin, progra);

	 printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * positif:\n\n");

	origin = printf( " |%*d|\n", 1, 100);
	progra = ft_printf( "f|%*d|\n\n", 1, 100);
	print_error(origin, progra);

	origin = printf( " |%0*d|\n", 1,101);
	progra = ft_printf( "f|%0*d|\n\n", 1, 101);
	print_error(origin, progra);

	origin = printf( " |%*d|\n", 3,0);
	progra = ft_printf( "f|%*d|\n\n", 3, 0);
	print_error(origin, progra);

	origin = printf( " |%*d|\n", 3,-0);
	progra = ft_printf( "f|%*d|\n\n", 3, -0);
	print_error(origin, progra);

	origin = printf( " |%*d|\n", 5, 102);
	progra = ft_printf( "f|%*d|\n\n", 5, 102);
	print_error(origin, progra);

	origin = printf( " |%0*d|\n", 5, -103);
	progra = ft_printf( "f|%0*d|\n\n", 5,-103);
	print_error(origin, progra);

	origin = printf( " |%*d|\n", 30, 2147483647);
	progra = ft_printf( "f|%*d|\n\n", 30, 2147483647);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%-xd ]	left :\n\n");

	origin = printf(" |%-1d|\n", 110);
	progra = ft_printf("f|%-1d|\n\n", 110);
	print_error(origin, progra);

	printf(" |%-0d|\n", 111);		// warning: '0' flag ignored with precision and ‘%d’
	ft_printf("f|%-0d|\n\n", 111);
	print_error(origin, progra);

	printf(" |%0-0d|\n", 112);		// warning: '0' flag ignored with precision and ‘%d’
	ft_printf("f|%0-0d|\n\n", 112);
	print_error(origin, progra);

	printf(" |%0-15d|\n", 113);		// warning: '0' flag ignored with precision and ‘%d’
	ft_printf("f|%0-15d|\n\n", 113);
	print_error(origin, progra);

	origin = printf(" |%-20d|\n", 114);
	progra = ft_printf("f|%-20d|\n\n", 114);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * negatif :\n\n");

	origin = printf(" |%*d|\n", -1, 115);
	progra = ft_printf("f|%*d|\n\n", -1, 115);
	print_error(origin, progra);

	origin = printf(" |%*d|\n", -22, 117);
	progra = ft_printf("f|%*d|\n\n", -22, 117);
	print_error(origin, progra);

	origin = printf(" |%-*d|\n", -22, 118);
	progra = ft_printf("f|%-*d|\n\n", -22, 118);
	print_error(origin, progra);

	origin = printf(" |%-*d|\n", 22, 1182);
	progra = ft_printf("f|%-*d|\n\n", 22, 1182);
	print_error(origin, progra);

	origin = printf(" |%-0*d|\n", 22, -1183);  	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%-0*d|\n\n", 22, -1183);
	print_error(origin, progra);

	origin = printf(" |%0-*d|\n", 22, 119);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0-*d|\n\n", 22, 119);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.xd ]	 :\n\n");

	origin = printf(" |%.0d|\n", 120);
	progra = ft_printf("f|%.0d|\n\n", 120);
	print_error(origin, progra);

	origin = printf(" |%.1d|\n", 121);
	progra = ft_printf("f|%.1d|\n\n", 121);
	print_error(origin, progra);

	origin = printf(" |%.15d|\n", 122);
	progra = ft_printf("f|%.15d|\n\n", 122);
	print_error(origin, progra);

	origin = printf(" |%.150d|\n", -123);
	progra = ft_printf("f|%.150d|\n\n", -123);
	print_error(origin, progra);

	origin = printf(" |%0.0d|\n", 124);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.0d|\n\n", 124);
	print_error(origin, progra);

	origin = printf(" |%0.12d|\n", -125);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.12d|\n\n", -125);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * positif :\n\n");

	origin = printf(" |%.*d|\n", 0, 130);
	progra = ft_printf("f|%.*d|\n\n", 0, 130);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", 1, 131);
	progra = ft_printf("f|%.*d|\n\n", 1, 131);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", 15, 132);
	progra = ft_printf("f|%.*d|\n\n", 15, 132);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", 150, -133);
	progra = ft_printf("f|%.*d|\n\n", 150, -133);
	print_error(origin, progra);

	origin = printf(" |%0.0d|\n", 134);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.0d|\n\n", 134);
	print_error(origin, progra);

	origin = printf(" |%0.12d|\n", -135);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.12d|\n\n", -135);
	print_error(origin, progra);


	origin = printf("*------------------------------------------------------*\n");
	origin = printf("*** **  *** 	CAS		[ %%.xd ]	avec x negatif : unknown conversion type character ‘-’ in format\n\n");

	//printf(" |%.-0d|\n", 140);
	//ft_printf("f|%.-0d|\n\n", 140);
	//print_error(origin, progra);

	//printf(" |%.-1d|\n", 141);
	//ft_printf("f|%.-1d|\n\n", 141);
	//print_error(origin, progra);

	//printf(" |%.-15d|\n", 142);
	//ft_printf("f|%.-15d|\n\n", 142);
	//print_error(origin, progra);

	//printf(" |%.-150d|\n", 143);
	//ft_printf("f|%.-150d|\n\n", 143);
	//print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * negatif : \n\n");

	origin = printf(" |%.*d|\n", -0, 150);
	progra = ft_printf("f|%.*d|\n\n", -0, 150);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", -1, -151);
	progra = ft_printf("f|%.*d|\n\n", -1, -151);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", -15, -152);
	progra = ft_printf("f|%.*d|\n\n", -15, -152);
	print_error(origin, progra);

	origin = printf(" |%.*d|\n", -150, 153);
	progra = ft_printf("f|%.*d|\n\n", -150, 153);
	print_error(origin, progra);

	origin = printf(" |%0.*d|\n", -150, 154);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.*d|\n\n", -150, 154);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.d ]	avec x positif :\n\n");

	origin = printf(" |%0.d|\n", 160);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.d|\n\n", 160);
	print_error(origin, progra);

	origin = printf(" |%1.d|\n", 161);
	progra = ft_printf("f|%1.d|\n\n", 161);
	print_error(origin, progra);

	origin = printf(" |%15.d|\n", 162);
	progra = ft_printf("f|%15.d|\n\n", 162);
	print_error(origin, progra);

	origin = printf(" |%150.d|\n", 163);
	progra = ft_printf("f|%150.d|\n\n", 163);
	print_error(origin, progra);

	origin = printf(" |%015.d|\n", 163);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%015.d|\n\n", 163);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * positif :\n\n");

	origin = printf(" |%*.d|\n", 0, 170);
	progra = ft_printf("f|%*.d|\n\n", 0, 170);
	print_error(origin, progra);

	origin = printf(" |%*.d|\n", 1, 171);
	progra = ft_printf("f|%*.d|\n\n", 1, 171);
	print_error(origin, progra);

	origin = printf(" |%*.d|\n", 15, 172);
	progra = ft_printf("f|%*.d|\n\n", 15, 172);
	print_error(origin, progra);

	origin = printf(" |%*.d|\n", 150, 173);
	progra = ft_printf("f|%*.d|\n\n", 150, 173);
	print_error(origin, progra);

	origin = printf(" |%0*.d|\n", 150, -174);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0*.d|\n\n", 150, -174);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%-x.d ]	:\n\n");

	origin = printf(" |%-0.d|\n", 175);			// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%-0.d|\n\n", 175);
	print_error(origin, progra);

	origin = printf(" |%-1.d|\n", 176);
	progra = ft_printf("f|%-1.d|\n\n", 176);
	print_error(origin, progra);

	origin = printf(" |%-15.d|\n", 177);
	progra = ft_printf("f|%-15.d|\n\n", 177);
	print_error(origin, progra);

	origin = printf(" |%-150.d|\n", -178);
	progra = ft_printf("f|%-150.d|\n\n", -178);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif : \n\n");

	origin = printf(" |%*.d|\n", -0, 180);
	progra = ft_printf("f|%*.d|\n\n", -0, 180);
	print_error(origin, progra);

	origin = printf(" |%*.d|\n", -1, 181);
	progra = ft_printf("f|%*.d|\n\n", -1, 181);
	print_error(origin, progra);

	origin = printf(" |%*.d|\n", -15, -182);
	progra = ft_printf("f|%*.d|\n\n", -15, -182);
	print_error(origin, progra);

	origin = printf(" |%*.d|\n", -150, 183);
	progra = ft_printf("f|%*.d|\n\n", -150, 183);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x et y positif : \n\n");

	origin = printf(" |%5.12d|\n", 200);
	progra = ft_printf("f|%5.12d|\n\n", 200);
	print_error(origin, progra);

	origin = printf(" |%12.5d|\n", 201);
	progra = ft_printf("f|%12.5d|\n\n", 201);
	print_error(origin, progra);

	origin = printf(" |%12.0d|\n", 202);
	progra = ft_printf("f|%12.0d|\n\n", 202);
	print_error(origin, progra);

	origin = printf(" |%0.12d|\n", 203);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.12d|\n\n", 203);
	print_error(origin, progra);

	origin = printf(" |%12.12d|\n", 204);
	progra = ft_printf("f|%12.12d|\n\n", 204);
	print_error(origin, progra);

	origin = printf(" |%0.0d|\n", 205);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.0d|\n\n", 205);
	print_error(origin, progra);

	origin = printf("*------------------------------------------------------*\n");
	origin = printf("*** **  *** 	CAS		[ %%*.*d ]	avec x et * positif : \n\n");

	origin = printf(" |%5.*d|\n", 12, 205);
	progra = ft_printf("f|%5.*d|\n\n", 12, 205);
	print_error(origin, progra);

	origin = printf(" |%12.*d|\n", 5, 206);
	progra = ft_printf("f|%12.*d|\n\n", 5, 206);
	print_error(origin, progra);

	origin = printf(" |%12.*d|\n", 0, 207);
	progra = ft_printf("f|%12.*d|\n\n", 0, 207);
	print_error(origin, progra);

	origin = printf(" |%0.*d|\n", 12, 208);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0.*d|\n\n", 12, 208);
	print_error(origin, progra);

	origin = printf(" |%12.*d|\n", 12, 209);
	progra = ft_printf("f|%12.*d|\n\n", 12, 209);
	print_error(origin, progra);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec *1 et *2 positif : \n\n");

	origin = printf(" |%*.*d|\n", 5, 12, 210);
	progra = ft_printf("f|%*.*d|\n\n",5, 12, 210);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 12, 5, 211);
	progra = ft_printf("f|%*.*d|\n\n",12, 5, 211);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 12, 0, 212);
	progra = ft_printf("f|%*.*d|\n\n", 12, 0, 212);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 0, 12, 213);
	progra = ft_printf("f|%*.*d|\n\n", 0, 12, 213);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 12, 12, 214);
	progra = ft_printf("f|%*.*d|\n\n", 12, 12, 214);
	print_error(origin, progra);

	origin = printf(" |%0*.*d|\n", 12, 5, 215);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0*.*d|\n\n",12, 5, 215);
	print_error(origin, progra);

	origin = printf(" |%0*.*d|\n", 12, 5, 216);	// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%0*.*d|\n\n",12, 5, 216);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec *1 et y positif : \n\n");

	origin = printf(" |%*.12d|\n", 5, 215);
	progra = ft_printf("f|%*.12d|\n\n",5, 215);
	print_error(origin, progra);

	origin = printf(" |%*.5d|\n", 12, -216);
	progra = ft_printf("f|%*.5d|\n\n",12, -216);
	print_error(origin, progra);

	origin = printf(" |%*.0d|\n", 12, 217);
	progra = ft_printf("f|%*.0d|\n\n", 12, 217);
	print_error(origin, progra);

	origin = printf(" |%*.12d|\n", 0, 218);
	progra = ft_printf("f|%*.12d|\n\n", 0, 218);
	print_error(origin, progra);

	origin = printf(" |%*.12d|\n", 12, 219);
	progra = ft_printf("f|%*.12d|\n\n", 12, 219);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%-x.yd ]	avec y positif : \n\n");

	origin = printf(" |%-5.12d|\n", 220);
	progra = ft_printf("f|%-5.12d|\n\n", 220);
	print_error(origin, progra);

	origin = printf(" |%-12.5d|\n", 221);
	progra = ft_printf("f|%-12.5d|\n\n", 221);
	print_error(origin, progra);

	origin = printf(" |%-12.0d|\n", 222);
	progra = ft_printf("f|%-12.0d|\n\n", 222);
	print_error(origin, progra);

	origin = printf(" |%-12.12d|\n", 223);
	progra = ft_printf("f|%-12.12d|\n\n", 223);
	print_error(origin, progra);

	origin = printf(" |%-0.12d|\n", 224);		// warning: '0' flag ignored with precision and ‘%d’
	progra = ft_printf("f|%-0.12d|\n\n", 224);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec * negatif et y positif : \n\n");

	origin = printf(" |%*.12d|\n", -5, 230);
	progra = ft_printf("f|%*.12d|\n\n", -5, 230);
	print_error(origin, progra);

	origin = printf(" |%-*.12d|\n", -5, 231);
	progra = ft_printf("f|%-*.12d|\n\n", -5, 231);
	print_error(origin, progra);

	origin = printf(" |%-*.12d|\n", 5, 232);
	progra = ft_printf("f|%-*.12d|\n\n", 5, 232);
	print_error(origin, progra);

	origin = printf(" |%*.12d|\n", 5, 2322);
	progra = ft_printf("f|%*.12d|\n\n", 5, 2322);
	print_error(origin, progra);

	origin = printf(" |%*.5d|\n", -12, 233);
	progra = ft_printf("f|%*.5d|\n\n", -12, 233);
	print_error(origin, progra);

	origin = printf(" |%-*.5d|\n", -12, 234);
	progra = ft_printf("f|%-*.5d|\n\n", -12, 234);
	print_error(origin, progra);

	origin = printf(" |%-*.5d|\n", 12, 235);
	progra = ft_printf("f|%-*.5d|\n\n", 12, 235);
	print_error(origin, progra);

	origin = printf(" |%*.0d|\n", -12, 236);
	progra = ft_printf("f|%*.0d|\n\n", -12, 236);
	print_error(origin, progra);

	origin = printf(" |%-*.0d|\n", 12, 237);
	progra = ft_printf("f|%-*.0d|\n\n", 12, 237);
	print_error(origin, progra);

	origin = printf(" |%-*.0d|\n", -12, 238);
	progra = ft_printf("f|%-*.0d|\n\n", -12, 238);
	print_error(origin, progra);

	origin = printf(" |%*.12d|\n", -0, 239);
	progra = ft_printf("f|%*.12d|\n\n",-0, 239);
	print_error(origin, progra);

	origin = printf(" |%-*.12d|\n", -0, 2392);
	progra = ft_printf("f|%-*.12d|\n\n",-0, 2392);
	print_error(origin, progra);

	origin = printf(" |%-*.12d|\n", -12, 2393);
	progra = ft_printf("f|%-*.12d|\n\n",-12, 2393);
	print_error(origin, progra);

	origin = printf(" |%*.12d|\n", -12, 2394);
	progra = ft_printf("f|%*.12d|\n\n",-12, 2394);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x positif et * negatif : \n\n");

	origin = printf(" |%5.*d|\n", -12, 240);
	progra = ft_printf("f|%5.*d|\n\n", -12, 240);
	print_error(origin, progra);

	origin = printf(" |%-12.*d|\n", 5, 2423);
	progra = ft_printf("f|%-12.*d|\n\n", 5, 2423);
	print_error(origin, progra);

	origin = printf(" |%12.*d|\n", -5, 243);
	progra = ft_printf("f|%12.*d|\n\n", -5, 243);
	print_error(origin, progra);

	origin = printf(" |%-5.*d|\n", -12, 2433);
	progra = ft_printf("f|%-5.*d|\n\n", -12, 2433);
	print_error(origin, progra);

	origin = printf(" |%12.*d|\n", -12, 246);
	progra = ft_printf("f|%12.*d|\n\n", -12, 246);
	print_error(origin, progra);

	origin = printf(" |%12.*d|\n", -0, 2491);
	progra = ft_printf("f|%12.*d|\n\n", -0, 2491);
	print_error(origin, progra);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * positif et * negatif : \n\n");


	origin = printf(" |%*.*d|\n", 5, -12, 260);
	progra = ft_printf("f|%*.*d|\n\n",5,  -12, 260);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n",12,  -5, 263);
	progra = ft_printf("f|%*.*d|\n\n",12,  -5, 263);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 12, -12, 266);
	progra = ft_printf("f|%*.*d|\n\n", 12, -12, 266);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 12, -0, 269);
	progra = ft_printf("f|%*.*d|\n\n", 12, -0, 269);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 12, 5, 220);
	progra = ft_printf("f|%*.*d|\n\n", 12, 5, 220);
	print_error(origin, progra);

	origin = printf(" |%-0.12d|\n", 213);
	progra = ft_printf("f|%-0.12d|\n\n", 213);
	print_error(origin, progra);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * negatif et * positif : \n\n");

	origin = printf(" |%*.*d|\n", -5, 12, 280);
	progra = ft_printf("f|%*.*d|\n\n", -5, 12, 280);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -5, 12, 281);
	progra = ft_printf("f|%-*.*d|\n\n", -5, 12, 281);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 5, 12, 282);
	progra = ft_printf("f|%-*.*d|\n\n", 5, 12, 282);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 5, 12, 2822);
	progra = ft_printf("f|%*.*d|\n\n", 5, 12, 2822);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -12, 5, 283);
	progra = ft_printf("f|%*.*d|\n\n", -12, 5, 283);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -12, 5, 284);
	progra = ft_printf("f|%-*.*d|\n\n", -12, 5, 284);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 12, 5, -285);
	progra = ft_printf("f|%-*.*d|\n\n", 12, 5, -285);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -12, 0, 286);
	progra = ft_printf("f|%*.*d|\n\n", -12, 0, 286);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 12, 0, 287);
	progra = ft_printf("f|%-*.*d|\n\n", 12, 0, 287);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -12, 0, 288);
	progra = ft_printf("f|%-*.*d|\n\n", -12, 0, 288);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -0, 12, 289);
	progra = ft_printf("f|%*.*d|\n\n",-0, 12, 289);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -0, 12, 290);
	progra = ft_printf("f|%-*.*d|\n\n",-0, 12, 290);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -12, 12, 291);
	progra = ft_printf("f|%-*.*d|\n\n",-12, 12, 291);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -12, 12, -292);
	progra = ft_printf("f|%*.*d|\n\n",-12, 12, -292);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x negatif et * positif : \n\n");

	origin = printf(" |%-5.*d|\n", 12, 220);
	progra = ft_printf("f|%-5.*d|\n\n", 12, 220);
	print_error(origin, progra);

	origin = printf(" |%-12.*d|\n", 5, 221);
	progra = ft_printf("f|%-12.*d|\n\n", 5, 221);
	print_error(origin, progra);

	origin = printf(" |%-12.*d|\n", 0, 222);
	progra = ft_printf("f|%-12.*d|\n\n", 0, 222);
	print_error(origin, progra);

	origin = printf(" |%-12.*d|\n", 12, -223);
	progra = ft_printf("f|%-12.*d|\n\n", 12, -223);
	print_error(origin, progra);

	origin = printf(" |%-0.*d|\n", 12, 224);
	progra = ft_printf("f|%-0.*d|\n\n", 12, 224);
	print_error(origin, progra);

	printf("*-------------------------------A FAIRE -----------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif et * negatif : \n\n");

	origin = printf(" |%*.*d|\n", -5, -12, 300);
	progra = ft_printf("f|%*.*d|\n\n", -5, -12, 300);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -5, -12, 301);
	progra = ft_printf("f|%-*.*d|\n\n", -5, -12, 301);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 5, -12, 302);
	progra = ft_printf("f|%-*.*d|\n\n", 5, -12, 302);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 5, -12, 3064);
	progra = ft_printf("f|%*.*d|\n\n", 5, -12, 3064);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -5, 12, -3065);
	progra = ft_printf("f|%*.*d|\n\n", -5, 12, -3065);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -12, 5, 3066);
	progra = ft_printf("f|%*.*d|\n\n", -12, 5, 3066);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", 12, -5, 3067);
	progra = ft_printf("f|%*.*d|\n\n", 12, -5, 3067);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -12, -5, 310);
	progra = ft_printf("f|%*.*d|\n\n", -12, -5, 310);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -12, -5, 311);
	progra = ft_printf("f|%-*.*d|\n\n",  -12, -5, 311);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 12, -5, 312);
	progra = ft_printf("f|%-*.*d|\n\n", 12, -5, 312);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -12, -12, 320);
	progra = ft_printf("f|%*.*d|\n\n", -12, -12, 320);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -12, -12, 321);
	progra = ft_printf("f|%-*.*d|\n\n",  -12, -12, 321);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 12, -12, 322);
	progra = ft_printf("f|%-*.*d|\n\n", 12, -12, 322);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -12, -0, 330);
	progra = ft_printf("f|%*.*d|\n\n", -12, -0, 330);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -12, -0, 331);
	progra = ft_printf("f|%-*.*d|\n\n",  -12, -0, 331);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 12, -0, 332);
	progra = ft_printf("f|%-*.*d|\n\n", 12, -0, 332);
	print_error(origin, progra);

	origin = printf(" |%*.*d|\n", -0, -12, 340);
	progra = ft_printf("f|%*.*d|\n\n", -0, -12, 340);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", -0, -12, -341);
	progra = ft_printf("f|%-*.*d|\n\n",  -0, -12, -341);
	print_error(origin, progra);

	origin = printf(" |%-*.*d|\n", 0, -12, 342);
	progra = ft_printf("f|%-*.*d|\n\n", 0, -12, 342);
	print_error(origin, progra);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x et * negatif : \n\n");

	origin = printf(" |%-.*d|\n", -12, 400);
	progra = ft_printf("f|%-.*d|\n\n",  -12, 400);
	print_error(origin, progra);

	origin = printf(" |%-5.*d|\n", -12, 401);
	progra = ft_printf("f|%-5.*d|\n\n", -12, 401);
	print_error(origin, progra);

	origin = printf(" |%-12.*d|\n",  -5, 404);
	progra = ft_printf("f|%-12.*d|\n\n",  -5, 404);
	print_error(origin, progra);

	origin = printf(" |%-12.*d|\n", -12, 407);
	progra = ft_printf("f|%-12.*d|\n\n", -12, 407);
	print_error(origin, progra);

	origin = printf(" |%-12.*d|\n", -0, 410);
	progra = ft_printf("f|%-12.*d|\n\n", -0, 410);
	print_error(origin, progra);

	origin = printf(" |%-0.*d|\n", -12, 413);
	progra = ft_printf("f|%-0.*d|\n\n", -12, 413);
	print_error(origin, progra);




printf("\n\n\n\t\t\t..-* STRING *-..\n");
	printf("\t\t*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*\n");

	char *s;
	// chaine standard | pointeur NULL | chaine vide | chaine 1 char |

	s = NULL;
	s = "";
	s = "c";
	s = "chaine de caractere";


	// printf(" |%-*.12s|\n", -12, -0, s);			Warning interessant
	// ft_printf("f|%-*.12s|\n\n",  -12, -0, s);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x positif:  // 1\n\n");

	printf( " |%1s|\n", s);
	ft_printf( "f|%1s|\n\n", s);

	printf( " |%3s|\n", s);
	ft_printf( "f|%3s|\n\n", s);

	printf( " |%30s|\n", s);
	ft_printf( "f|%30s|\n\n", s);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * positif: // 2\n\n");

	printf( " |%*s|\n",1, s);
	ft_printf( "f|%*s|\n\n", 1, s);

	printf( " |%*s|\n", 3, s);
	ft_printf( "f|%*s|\n\n", 3, s);

	printf( " |%*s|\n", 30, s);
	ft_printf( "f|%*s|\n\n", 30, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x negatif : // 3\n\n");

	printf(" |%-1s|\n", s);
	ft_printf("f|%-1s|\n\n", s);

	printf(" |%-30s|\n", s);
	ft_printf("f|%-30s|\n\n", s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * negatif : / 4\n\n");

	printf(" |%*s|\n", -1, s);
	ft_printf("f|%*s|\n\n", -1, s);

	printf(" |%*s|\n", -30, s);
	ft_printf("f|%*s|\n\n", -30, s);

	printf(" |%-*s|\n", -30, s);
	ft_printf("f|%-*s|\n\n", -30, s);

	printf(" |%-*s|\n", 30, s);
	ft_printf("f|%-*s|\n\n", 30, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.xd ]	avec x positif : // 5\n\n");

	printf(" |%.0s|\n", s);
	ft_printf("f|%.0s|\n\n", s);

	printf(" |%.1s|\n", s);
	ft_printf("f|%.1s|\n\n", s);

	printf(" |%.15s|\n", s);
	ft_printf("f|%.15s|\n\n", s);

	printf(" |%.150s|\n", s);
	ft_printf("f|%.150s|\n\n", s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * positif : // 6\n\n");

	printf(" |%.*s|\n", 0, s);
	ft_printf("f|%.*s|\n\n", 0, s);

	printf(" |%.*s|\n", 1, s);
	ft_printf("f|%.*s|\n\n", 1, s);

	printf(" |%.*s|\n", 15, s);
	ft_printf("f|%.*s|\n\n", 15, s);

	printf(" |%.*s|\n", 150, s);
	ft_printf("f|%.*s|\n\n", 150, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.xd ]	avec x negatif : // 7 WARNING \n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * negatif : // 8\n\n");

	printf(" |%.*s|\n", -0, s);
	ft_printf("f|%.*s|\n\n", -0, s);

	printf(" |%.*s|\n", -1, s);
	ft_printf("f|%.*s|\n\n", -1, s);

	printf(" |%.*s|\n", -15, s);
	ft_printf("f|%.*s|\n\n", -15, s);

	printf(" |%.*s|\n", -150, s);
	ft_printf("f|%.*s|\n\n", -150, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.d ]	avec x positif : // 9\n\n");

	printf(" |%1.s|\n", s);
	ft_printf("f|%1.s|\n\n", s);

	printf(" |%15.s|\n", s);
	ft_printf("f|%15.s|\n\n", s);

	printf(" |%150.s|\n", s);
	ft_printf("f|%150.s|\n\n", s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * positif :	// 10\n\n");

	printf(" |%*.s|\n", 0, s);
	ft_printf("f|%*.s|\n\n", 0, s);

	printf(" |%*.s|\n", 1, s);
	ft_printf("f|%*.s|\n\n", 1, s);

	printf(" |%*.s|\n", 150, s);
	ft_printf("f|%*.s|\n\n", 150, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.d ]	avec x negatif :	// 11\n\n");

	printf(" |%-1.s|\n", s);
	ft_printf("f|%-1.s|\n\n", s);

	printf(" |%-150.s|\n", s);
	ft_printf("f|%-150.s|\n\n", s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif : 	// 12\n\n");

	printf(" |%*.s|\n", -0, s);
	ft_printf("f|%*.s|\n\n", -0, s);

	printf(" |%*.s|\n", -1, s);
	ft_printf("f|%*.s|\n\n", -1, s);

	printf(" |%*.s|\n", -150, s);
	ft_printf("f|%*.s|\n\n", -150, s);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x et y positif : 	// 13\n\n");

	printf(" |%5.12s|\n", s);
	ft_printf("f|%5.12s|\n\n", s);

	printf(" |%12.5s|\n", s);
	ft_printf("f|%12.5s|\n\n", s);

	printf(" |%12.0s|\n", s);
	ft_printf("f|%12.0s|\n\n", s);

	printf(" |%12.12s|\n", s);
	ft_printf("f|%12.12s|\n\n", s);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec x et * positif : 	// 14\n\n");

	printf(" |%35.*s|\n", 12, s);
	ft_printf("f|%35.*s|\n\n", 12, s);

	printf(" |%12.*s|\n", 5, s);
	ft_printf("f|%12.*s|\n\n", 5, s);

	printf(" |%12.*s|\n", 0, s);
	ft_printf("f|%12.*s|\n\n", 0, s);

	printf(" |%12.*s|\n", 12, s);
	ft_printf("f|%12.*s|\n\n", 12, s);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec *1 et *2 positif :  	// 15\n\n");

	printf(" |%*.*s|\n", 5, 12, s);
	ft_printf("f|%*.*s|\n\n",5, 12, s);

	printf(" |%*.*s|\n", 12, 5, s);
	ft_printf("f|%*.*s|\n\n",12, 5, s);

	printf(" |%*.*s|\n", 12, 0, s);
	ft_printf("f|%*.*s|\n\n", 12, 0, s);

	printf(" |%*.*s|\n", 0, 12, s);
	ft_printf("f|%*.*s|\n\n", 0, 12, s);

	printf(" |%*.*s|\n", 12, 12, s);
	ft_printf("f|%*.*s|\n\n", 12, 12, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec *1 et y positif : 	// 16\n\n");

	printf(" |%*.12s|\n", 5, s);
	ft_printf("f|%*.12s|\n\n",5, s);

	printf(" |%*.5s|\n", 12, s);
	ft_printf("f|%*.5s|\n\n",12, s);

	printf(" |%*.0s|\n", 12, s);
	ft_printf("f|%*.0s|\n\n", 12, s);

	printf(" |%*.12s|\n", 0, s);
	ft_printf("f|%*.12s|\n\n", 0, s);

	printf(" |%*.12s|\n", 12, s);
	ft_printf("f|%*.12s|\n\n", 12, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x negatif et y positif : 	// 17\n\n");

	printf(" |%-5.12s|\n", s);
	ft_printf("f|%-5.12s|\n\n", s);

	printf(" |%-12.5s|\n", s);
	ft_printf("f|%-12.5s|\n\n", s);

	printf(" |%-12.0s|\n", s);
	ft_printf("f|%-12.0s|\n\n", s);

	printf(" |%-12.12s|\n", s);
	ft_printf("f|%-12.12s|\n\n", s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec * negatif et y positif : 	// 18\n\n");

	printf(" |%*.12s|\n", -5, s);
	ft_printf("f|%*.12s|\n\n", -5, s);

	printf(" |%-*.12s|\n", -5, s);
	ft_printf("f|%-*.12s|\n\n", -5, s);

	printf(" |%-*.12s|\n", 5, s);
	ft_printf("f|%-*.12s|\n\n", 5, s);

	printf(" |%*.12s|\n", 5, s);
	ft_printf("f|%*.12s|\n\n", 5, s);

	printf(" |%*.5s|\n", -12, s);
	ft_printf("f|%*.5s|\n\n", -12, s);

	printf(" |%-*.5s|\n", -12, s);
	ft_printf("f|%-*.5s|\n\n", -12, s);

	printf(" |%-*.5s|\n", 12, s);
	ft_printf("f|%-*.5s|\n\n", 12, s);

	printf(" |%*.0s|\n", -12, s);
	ft_printf("f|%*.0s|\n\n", -12, s);

	printf(" |%-*.0s|\n", 12, s);
	ft_printf("f|%-*.0s|\n\n", 12, s);

	printf(" |%-*.0s|\n", -12, s);
	ft_printf("f|%-*.0s|\n\n", -12, s);

	printf(" |%*.12s|\n", -0, s);
	ft_printf("f|%*.12s|\n\n",-0, s);

	printf(" |%-*.12s|\n", -0, s);
	ft_printf("f|%-*.12s|\n\n",-0, s);

	printf(" |%-*.12s|\n", -12, s);
	ft_printf("f|%-*.12s|\n\n",-12, s);

	printf(" |%*.12s|\n", -12, s);
	ft_printf("f|%*.12s|\n\n",-12, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec * positif et y negatif : WARNING ok	// 19\n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x positif et * negatif :	// 20 \n\n");

	printf(" |%5.*s|\n", -12, s);
	ft_printf("f|%5.*s|\n\n", -12, s);

	printf(" |%-12.*s|\n", 5, s);
	ft_printf("f|%-12.*s|\n\n", 5, s);

	printf(" |%12.*s|\n", -5, s);
	ft_printf("f|%12.*s|\n\n", -5, s);

	printf(" |%-5.*s|\n", -12, s);
	ft_printf("f|%-5.*s|\n\n", -12, s);

	printf(" |%12.*s|\n", -12, s);
	ft_printf("f|%12.*s|\n\n", -12, s);

	printf(" |%12.*s|\n", -0, s);
	ft_printf("f|%12.*s|\n\n", -0, s);


	printf(" |%*.*s|\n", 12, 5, s);
	ft_printf("f|%*.*s|\n", 12, 5, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * positif et * negatif : 	// 21\n\n");

	printf(" |%*.*s|\n", 5, -12, s);
	ft_printf("f|%*.*s|\n\n",5,  -12, s);

	printf(" |%*.*s|\n", 12, -12, s);
	ft_printf("f|%*.*s|\n\n", 12, -12, s);

	printf(" |%*.*s|\n",12,  -5, s);
	ft_printf("f|%*.*s|\n\n",12,  -5, s);

	printf(" |%*.*s|\n", 12, -0, s);
	ft_printf("f|%*.*s|\n\n", 12, -0, s);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x positif et y negatif : WARNING ok // 22 \n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * negatif et * positif :  	// 23\n\n");

	printf(" |%*.*s|\n", -5, 12, s);
	ft_printf("f|%*.*s|\n\n", -5, 12, s);

	printf(" |%-*.*s|\n", -5, 12, s);
	ft_printf("f|%-*.*s|\n\n", -5, 12, s);

	printf(" |%-*.*s|\n", 5, 12, s);
	ft_printf("f|%-*.*s|\n\n", 5, 12, s);

	printf(" |%*.*s|\n", 5, 12, s);
	ft_printf("f|%*.*s|\n\n", 5, 12, s);

	printf(" |%*.*s|\n", -30, 5, s);
	ft_printf("f|%*.*s|\n\n", -30, 5, s);

	printf(" |%-*.*s|\n", -30, 5, s);
	ft_printf("f|%-*.*s|\n\n", -30, 5, s);

	printf(" |%-*.*s|\n", 30, 5, s);
	ft_printf("f|%-*.*s|\n\n", 30, 5, s);

	printf(" |%*.*s|\n", -30, 0, s);
	ft_printf("f|%*.*s|\n\n", -30, 0, s);

	printf(" |%-*.*s|\n", 30, 0, s);
	ft_printf("f|%-*.*s|\n\n", 30, 0, s);

	printf(" |%-*.*s|\n", -30, 0, s);
	ft_printf("f|%-*.*s|\n\n", -30, 0, s);

	printf(" |%*.*s|\n", -0, 12, s);
	ft_printf("f|%*.*s|\n\n",-0, 12, s);

	printf(" |%-*.*s|\n", -0, 12, s);
	ft_printf("f|%-*.*s|\n\n",-0, 12, s);

	printf(" |%-*.*s|\n", -12, 12, s);
	ft_printf("f|%-*.*s|\n\n",-12, 12, s);

	printf(" |%*.*s|\n", -12, 12, s);
	ft_printf("f|%*.*s|\n\n",-12, 12, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x negatif et * positif : 	// 24\n\n");

	printf(" |%-5.*s|\n", 12, s);
	ft_printf("f|%-5.*s|\n\n", 12, s);

	printf(" |%-30.*s|\n", 5, s);
	ft_printf("f|%-30.*s|\n\n", 5, s);

	printf(" |%-12.*s|\n", 0, s);
	ft_printf("f|%-12.*s|\n\n", 0, s);

	printf(" |%-12.*s|\n", 12, s);
	ft_printf("f|%-12.*s|\n\n", 12, s);

	printf("*-------------------------------A FAIRE -----------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif et * negatif : 	// 25\n\n");

	printf(" |%*.*s|\n", -5, -12, s);
	ft_printf("f|%*.*s|\n\n", -5, -12, s);

	printf(" |%-*.*s|\n", -5, -12, s);
	ft_printf("f|%-*.*s|\n\n", -5, -12, s);

	printf(" |%-*.*s|\n", 5, -12, s);
	ft_printf("f|%-*.*s|\n\n", 5, -12, s);

	printf(" |%*.*s|\n", 5, -12, s);
	ft_printf("f|%*.*s|\n\n", 5, -12, s);

	printf(" |%*.*s|\n", -5, 12, s);
	ft_printf("f|%*.*s|\n\n", -5, 12, s);

	printf(" |%*.*s|\n", -12, 5, s);
	ft_printf("f|%*.*s|\n\n", -12, 5, s);

	printf(" |%*.*s|\n", 12, -5, s);
	ft_printf("f|%*.*s|\n\n", 12, -5, s);

	printf(" |%*.*s|\n", -12, -5, s);
	ft_printf("f|%*.*s|\n\n", -12, -5, s);

	printf(" |%-*.*s|\n", -12, -5, s);
	ft_printf("f|%-*.*s|\n\n",  -12, -5, s);

	printf(" |%-*.*s|\n", 12, -5, s);
	ft_printf("f|%-*.*s|\n\n", 12, -5, s);

	printf(" |%*.*s|\n", -12, -12, s);
	ft_printf("f|%*.*s|\n\n", -12, -12, s);

	printf(" |%-*.*s|\n", -12, -12, s);
	ft_printf("f|%-*.*s|\n\n",  -12, -12, s);

	printf(" |%-*.*s|\n", 12, -12, s);
	ft_printf("f|%-*.*s|\n\n", 12, -12, s);

	printf(" |%*.*s|\n", -12, -0, s);
	ft_printf("f|%*.*s|\n\n", -12, -0, s);

	printf(" |%-*.*s|\n", 12, -0, s);
	ft_printf("f|%-*.*s|\n\n", 12, -0, s);

	printf(" |%*.*s|\n", -0, -12, s);
	ft_printf("f|%*.*s|\n\n", -0, -12, s);

	printf(" |%-*.*s|\n", -0, -12, s);
	ft_printf("f|%-*.*s|\n\n",  -0, -12, s);

	printf(" |%-*.*s|\n", 0, -12, s);
	ft_printf("f|%-*.*s|\n\n", 0, -12, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x et * negatif : 		// 26\n\n");

	printf(" |%-.*s|\n", -12, s);
	ft_printf("f|%-.*s|\n\n",  -12, s);

	printf(" |%-5.*s|\n", -12, s);
	ft_printf("f|%-5.*s|\n\n", -12, s);

	printf(" |%-12.*s|\n",  -5, s);
	ft_printf("f|%-12.*s|\n\n",  -5, s);

	printf(" |%-12.*s|\n", -12, s);
	ft_printf("f|%-12.*s|\n\n", -12, s);

	printf(" |%-12.*s|\n", -0, s);
	ft_printf("f|%-12.*s|\n\n", -0, s);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec * et y negatif : WARNING \n\n");


printf("\n\n\n\t\t\t..-* CHAR C *-..\n");
	setlocale(LC_ALL,"");

	int c1 = 0;

	while (c1 < 256)
	{
		if (c1 > 0)
			printf("%d	|%c|\n",c1, c1);
		for(int i = 0; i > 100; i++)
		;
		if (c1 > 0)
			ft_printf("	|%c|\n\n", c1);
		c1++;
	}

	// CHAR 0 | 'c' | 0 a 256 au dessus |
	char c;

	c = 0;
	c = 'c';


	//	printf("|%.0c|\n", c);
	//	ft_printf("|%.0c|\n", c);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x positif:  // 1\n\n");

	printf( " |%1c|\n", c);
	ft_printf( "f|%1c|\n\n", c);

	printf( " |%3c|\n", c);
	ft_printf( "f|%3c|\n\n", c);

	printf( " |%30c|\n", c);
	ft_printf( "f|%30c|\n\n", c);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * positif: // 2\n\n");

	printf( " |%*c|\n",1, c);
	ft_printf( "f|%*c|\n\n", 1, c);

	printf( " |%*c|\n", 3, c);
	ft_printf( "f|%*c|\n\n", 3, c);

	printf( " |%*c|\n", 30, c);
	ft_printf( "f|%*c|\n\n", 30, c);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x negatif : // 3\n\n");

	printf(" |%-1c|\n", c);
	ft_printf("f|%-1c|\n\n", c);

	printf(" |%-30c|\n", c);
	ft_printf("f|%-30c|\n\n", c);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * negatif : / 4\n\n");

	printf(" |%*c|\n", -1, c);
	ft_printf("f|%*c|\n\n", -1, c);

	printf(" |%*c|\n", -0, c);
	ft_printf("f|%*c|\n\n", -0, c);

	printf(" |%*c|\n", -30, c);
	ft_printf("f|%*c|\n\n", -30, c);

	printf(" |%-*c|\n", -30, c);
	ft_printf("f|%-*c|\n\n", -30, c);

	printf(" |%-*c|\n", 30, c);
	ft_printf("f|%-*c|\n\n", 30, c);

printf("\n\n\n\t\t\t..-* CHAR C  with %%lc *-..\n");


	// CHAR 0 | 'c' | 0 a 256 au dessus |
	//char c;

	//c = 0;
	//c = 'c';
	wchar_t wc = L'𢁅';



	//	printf("|%.0lc|\n", c);
	//	ft_printf("|%.0lc|\n", c);
	ft_strlen("");
	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x positif:  // 1\n\n");

	a = printf( "%lc", wc);
	b = ft_printf( "%lc\n", wc);
	print_error(a, b);

	a = printf( " ||\n");
	b = ft_printf( "f||\n\n");
	print_error(a, b);

	a = printf( " |%1lc|\n", wc);
	b = ft_printf( "f|%1lc|\n\n", wc);
	print_error(a, b);

	a = printf( " |%3lc|\n", wc);
	b = ft_printf( "f|%3lc|\n\n", wc);
	print_error(a, b);

	a = printf( " |%30lc|\n", wc);
	b = ft_printf( "f|%30lc|\n\n", wc);
	print_error(a, b);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * positif: // 2\n\n");

	a = printf( " |%*lc|\n",1, wc);
	b = ft_printf( "f|%*lc|\n\n", 1, wc);
	print_error(a, b);

	a = printf( " |%*lc|\n", 3, wc);
	b = ft_printf( "f|%*lc|\n\n", 3, wc);
	print_error(a, b);

	a = printf( " |%*lc|\n", 30, wc);
	b = ft_printf( "f|%*lc|\n\n", 30, wc);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x negatif : // 3\n\n");

	a = printf(" |%-1lc|\n", wc);
	b = ft_printf("f|%-1lc|\n\n", wc);
	print_error(a, b);

	a = printf(" |%-30lc|\n", wc);
	b = ft_printf("f|%-30lc|\n\n", wc);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * negatif : / 4\n\n");

	a = printf(" |%*lc|\n", -1, wc);
	b = ft_printf("f|%*lc|\n\n", -1, wc);
	print_error(a, b);

	a = printf(" |%*lc|\n", -0, wc);
	b = ft_printf("f|%*lc|\n\n", -0, wc);
	print_error(a, b);

	a = printf(" |%*lc|\n", -30, wc);
	b = ft_printf("f|%*lc|\n\n", -30, wc);
	print_error(a, b);

	a = printf(" |%-*lc|\n", -30, wc);
	b = ft_printf("f|%-*lc|\n\n", -30, wc);
	print_error(a, b);

	a = printf(" |%-*lc|\n", 30, wc);
	b = ft_printf("f|%-*lc|\n\n", 30, wc);
	print_error(a, b);

printf("\n\n\n\t\t\t..-* L STRING  unicode *-..\n");
	printf("\t\t*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*\n");

	wchar_t *ws;
	// chaine standard | pointeur NULL | chaine vide | chaine 1 char |

	//ws = NULL;
	ws = L"";
	ws = L"c";	
	//printf("c = %lu\n",  wcslen(ws));	
	//a = printf( "%ls\n", ws);
	//b = ft_printf( "%ls\n\n", ws);
	//print_error(a, b);

	ws = L"语";
	//ws = L"123456789";

	a = printf( "%ls\n", ws);
	b = ft_printf( "%ls\n\n", ws);
	print_error(a, b);

	a = printf( " |%2ls|\n", ws);
	b = ft_printf( " |%2ls|\n\n", ws);
	print_error(a, b);

	a = printf( " |%3ls|\n", ws);
	b = ft_printf( " |%3ls|\n\n", ws);
	print_error(a, b);

	a = printf( " |%4ls|\n", ws);
	b = ft_printf( " |%4ls|\n\n", ws);
	print_error(a, b);





	ws = L"语语";

	//a = printf( " |%5ls|\n", ws);
	//b = ft_printf( " |%5ls|\n\n", ws);
	//print_error(a, b);

	ws = L"ﷰ";
	ws = L"ﷰΔι𢁅Διﷰκαιοπολις chaine 语言处理";


	// a = printf(" |%-*.12ls|\n", -12, -0, ws);			Warning interessant
	// b = ft_printf("f|%-*.12ls|\n\n",  -12, -0, ws);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x positif:  // 1\n\n");


	a = printf( " |%1ls|\n", ws);
	b = ft_printf( "f|%1ls|\n\n", ws);
	print_error(a, b);

	a = printf( " |%3ls|\n", ws);
	b = ft_printf( "f|%3ls|\n\n", ws);
	print_error(a, b);

	a = printf( " |%30ls|\n", ws);
	b = ft_printf( "f|%30ls|\n\n", ws);
	print_error(a, b);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * positif: // 2\n\n");
	print_error(a, b);

	a = printf( " |%*ls|\n",1, ws);
	b = ft_printf( "f|%*ls|\n\n", 1, ws);
	print_error(a, b);

	a = printf( " |%*ls|\n", 3, ws);
	b = ft_printf( "f|%*ls|\n\n", 3, ws);
	print_error(a, b);

	a = printf( " |%*ls|\n", 30, ws);
	b = ft_printf( "f|%*ls|\n\n", 30, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x negatif : // 3\n\n");


	a = printf(" |%-1ls|\n", ws);
	b = ft_printf("f|%-1ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%-30ls|\n", ws);
	b = ft_printf("f|%-30ls|\n\n", ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * negatif : / 4\n\n");


	a = printf(" |%*ls|\n", -1, ws);
	b = ft_printf("f|%*ls|\n\n", -1, ws);
	print_error(a, b);

	a = printf(" |%*ls|\n", -30, ws);
	b = ft_printf("f|%*ls|\n\n", -30, ws);
	print_error(a, b);

	a = printf(" |%-*ls|\n", -30, ws);
	b = ft_printf("f|%-*ls|\n\n", -30, ws);
	print_error(a, b);

	a = printf(" |%-*ls|\n", 30, ws);
	b = ft_printf("f|%-*ls|\n\n", 30, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.xd ]	avec x positif : // 5\n\n");


	a = printf(" |%.0ls|\n", ws);
	b = ft_printf("f|%.0ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%.1ls|\n", ws);
	b = ft_printf("f|%.1ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%.15ls|\n", ws);
	b = ft_printf("f|%.15ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%.150ls|\n", ws);
	b = ft_printf("f|%.150ls|\n\n", ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * positif : // 6\n\n");

	a = printf(" |%.*ls|\n", 0, ws);
	b = ft_printf("f|%.*ls|\n\n", 0, ws);
	print_error(a, b);

	a = printf(" |%.*ls|\n", 1, ws);
	b = ft_printf("f|%.*ls|\n\n", 1, ws);
	print_error(a, b);

	a = printf(" |%.*ls|\n", 15, ws);
	b = ft_printf("f|%.*ls|\n\n", 15, ws);
	print_error(a, b);

	a = printf(" |%.*ls|\n", 150, ws);
	b = ft_printf("f|%.*ls|\n\n", 150, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.xd ]	avec x negatif : // 7 WARNING \n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * negatif : // 8\n\n");


	a = printf(" |%.*ls|\n", -0, ws);
	b = ft_printf("f|%.*ls|\n\n", -0, ws);
	print_error(a, b);

	a = printf(" |%.*ls|\n", -1, ws);
	b = ft_printf("f|%.*ls|\n\n", -1, ws);
	print_error(a, b);

	a = printf(" |%.*ls|\n", -15, ws);
	b = ft_printf("f|%.*ls|\n\n", -15, ws);
	print_error(a, b);

	a = printf(" |%.*ls|\n", -150, ws);
	b = ft_printf("f|%.*ls|\n\n", -150, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.d ]	avec x positif : // 9\n\n");

	a = printf(" |%1.ls|\n", ws);
	b = ft_printf("f|%1.ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%15.ls|\n", ws);
	b = ft_printf("f|%15.ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%150.ls|\n", ws);
	b = ft_printf("f|%150.ls|\n\n", ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * positif :	// 10\n\n");

	a = printf(" |%*.ls|\n", 0, ws);
	b = ft_printf("f|%*.ls|\n\n", 0, ws);
	print_error(a, b);

	a = printf(" |%*.ls|\n", 1, ws);
	b = ft_printf("f|%*.ls|\n\n", 1, ws);
	print_error(a, b);

	a = printf(" |%*.ls|\n", 150, ws);
	b = ft_printf("f|%*.ls|\n\n", 150, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.d ]	avec x negatif :	// 11\n\n");

	a = printf(" |%-1.ls|\n", ws);
	b = ft_printf("f|%-1.ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%-150.ls|\n", ws);
	b = ft_printf("f|%-150.ls|\n\n", ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif : 	// 12\n\n");

	a = printf(" |%*.ls|\n", -0, ws);
	b = ft_printf("f|%*.ls|\n\n", -0, ws);
	print_error(a, b);

	a = printf(" |%*.ls|\n", -1, ws);
	b = ft_printf("f|%*.ls|\n\n", -1, ws);
	print_error(a, b);

	a = printf(" |%*.ls|\n", -150, ws);
	b = ft_printf("f|%*.ls|\n\n", -150, ws);
	print_error(a, b);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x et y positif : 	// 13\n\n");

	a = printf(" |%5.12ls|\n", ws);
	b = ft_printf("f|%5.12ls|\n\n", ws);
	print_error(a, b);


	a = printf(" |%12ls|\n", ws);
	b = ft_printf("f|%12ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%.5ls|\n", ws);
	b = ft_printf("f|%.5ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%12.5ls|\n", ws);
	b = ft_printf("f|%12.5ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%4.4ls|\n", ws);
	b = ft_printf("f|%4.4ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%4.5ls|\n", ws);
	b = ft_printf("f|%4.5ls|\n\n", ws);
	print_error(a, b);
	
	a = printf(" |%5.4ls|\n", ws);
	b = ft_printf("f|%5.4ls|\n\n", ws);
	print_error(a, b);




	a = printf(" |%12.0ls|\n", ws);
	b = ft_printf("f|%12.0ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%12.12ls|\n", ws);
	b = ft_printf("f|%12.12ls|\n\n", ws);
	print_error(a, b);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec x et * positif : 	// 14\n\n");

	a = printf(" |%35.*ls|\n", 12, ws);
	b = ft_printf("f|%35.*ls|\n\n", 12, ws);
	print_error(a, b);

	a = printf(" |%12.*ls|\n", 5, ws);
	b = ft_printf("f|%12.*ls|\n\n", 5, ws);
	print_error(a, b);

	a = printf(" |%12.*ls|\n", 0, ws);
	b = ft_printf("f|%12.*ls|\n\n", 0, ws);
	print_error(a, b);

	a = printf(" |%12.*ls|\n", 12, ws);
	b = ft_printf("f|%12.*ls|\n\n", 12, ws);
	print_error(a, b);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec *1 et *2 positif :  	// 15\n\n");

	a = printf(" |%*.*ls|\n", 5, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n",5, 12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 12, 5, ws);
	b = ft_printf("f|%*.*ls|\n\n",12, 5, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 12, 0, ws);
	b = ft_printf("f|%*.*ls|\n\n", 12, 0, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 0, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n", 0, 12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 12, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n", 12, 12, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec *1 et y positif : 	// 16\n\n");

	a = printf(" |%*.12ls|\n", 5, ws);
	b = ft_printf("f|%*.12ls|\n\n",5, ws);
	print_error(a, b);

	a = printf(" |%*.5ls|\n", 12, ws);
	b = ft_printf("f|%*.5ls|\n\n",12, ws);
	print_error(a, b);

	a = printf(" |%*.0ls|\n", 12, ws);
	b = ft_printf("f|%*.0ls|\n\n", 12, ws);
	print_error(a, b);

	a = printf(" |%*.12ls|\n", 0, ws);
	b = ft_printf("f|%*.12ls|\n\n", 0, ws);
	print_error(a, b);

	a = printf(" |%*.12ls|\n", 12, ws);
	b = ft_printf("f|%*.12ls|\n\n", 12, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x negatif et y positif : 	// 17\n\n");

	a = printf(" |%-5.12ls|\n", ws);
	b = ft_printf("f|%-5.12ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%-12.5ls|\n", ws);
	b = ft_printf("f|%-12.5ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%-12.0ls|\n", ws);
	b = ft_printf("f|%-12.0ls|\n\n", ws);
	print_error(a, b);

	a = printf(" |%-12.12ls|\n", ws);
	b = ft_printf("f|%-12.12ls|\n\n", ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec * negatif et y positif : 	// 18\n\n");

	a = printf(" |%*.12ls|\n", -5, ws);
	b = ft_printf("f|%*.12ls|\n\n", -5, ws);
	print_error(a, b);

	a = printf(" |%-*.12ls|\n", -5, ws);
	b = ft_printf("f|%-*.12ls|\n\n", -5, ws);
	print_error(a, b);

	a = printf(" |%-*.12ls|\n", 5, ws);
	b = ft_printf("f|%-*.12ls|\n\n", 5, ws);
	print_error(a, b);

	a = printf(" |%*.12ls|\n", 5, ws);
	b = ft_printf("f|%*.12ls|\n\n", 5, ws);
	print_error(a, b);

	a = printf(" |%*.5ls|\n", -12, ws);
	b = ft_printf("f|%*.5ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%-*.5ls|\n", -12, ws);
	b = ft_printf("f|%-*.5ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%-*.5ls|\n", 12, ws);
	b = ft_printf("f|%-*.5ls|\n\n", 12, ws);
	print_error(a, b);

	a = printf(" |%*.0ls|\n", -12, ws);
	b = ft_printf("f|%*.0ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%-*.0ls|\n", 12, ws);
	b = ft_printf("f|%-*.0ls|\n\n", 12, ws);
	print_error(a, b);

	a = printf(" |%-*.0ls|\n", -12, ws);
	b = ft_printf("f|%-*.0ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%*.12ls|\n", -0, ws);
	b = ft_printf("f|%*.12ls|\n\n",-0, ws);
	print_error(a, b);

	a = printf(" |%-*.12ls|\n", -0, ws);
	b = ft_printf("f|%-*.12ls|\n\n",-0, ws);
	print_error(a, b);

	a = printf(" |%-*.12ls|\n", -12, ws);
	b = ft_printf("f|%-*.12ls|\n\n",-12, ws);
	print_error(a, b);

	a = printf(" |%*.12ls|\n", -12, ws);
	b = ft_printf("f|%*.12ls|\n\n",-12, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec * positif et y negatif : WARNING ok	// 19\n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x positif et * negatif :	// 20 \n\n");

	a = printf(" |%5.*ls|\n", -12, ws);
	b = ft_printf("f|%5.*ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%-12.*ls|\n", 5, ws);
	b = ft_printf("f|%-12.*ls|\n\n", 5, ws);
	print_error(a, b);

	a = printf(" |%12.*ls|\n", -5, ws);
	b = ft_printf("f|%12.*ls|\n\n", -5, ws);
	print_error(a, b);

	a = printf(" |%-5.*ls|\n", -12, ws);
	b = ft_printf("f|%-5.*ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%12.*ls|\n", -12, ws);
	b = ft_printf("f|%12.*ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%12.*ls|\n", -0, ws);
	b = ft_printf("f|%12.*ls|\n\n", -0, ws);

	print_error(a, b);

	a = printf(" |%*.*ls|\n", 12, 5, ws);
	b = ft_printf("f|%*.*ls|\n\n", 12, 5, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * positif et * negatif : 	// 21\n\n");

	a = printf(" |%*.*ls|\n", 5, -12, ws);
	b = ft_printf("f|%*.*ls|\n\n",5,  -12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 12, -12, ws);
	b = ft_printf("f|%*.*ls|\n\n", 12, -12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n",12,  -5, ws);
	b = ft_printf("f|%*.*ls|\n\n",12,  -5, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 12, -0, ws);
	b = ft_printf("f|%*.*ls|\n\n", 12, -0, ws);
	print_error(a, b);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * negatif et * positif :  	// 23\n\n");

	a = printf(" |%*.*ls|\n", -5, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n", -5, 12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -5, 12, ws);
	b = ft_printf("f|%-*.*ls|\n\n", -5, 12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 5, 12, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 5, 12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 5, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n", 5, 12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -30, 5, ws);
	b = ft_printf("f|%*.*ls|\n\n", -30, 5, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -30, 5, ws);
	b = ft_printf("f|%-*.*ls|\n\n", -30, 5, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 30, 5, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 30, 5, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -30, 0, ws);
	b = ft_printf("f|%*.*ls|\n\n", -30, 0, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 30, 0, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 30, 0, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -30, 0, ws);
	b = ft_printf("f|%-*.*ls|\n\n", -30, 0, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -0, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n",-0, 12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -0, 12, ws);
	b = ft_printf("f|%-*.*ls|\n\n",-0, 12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -12, 12, ws);
	b = ft_printf("f|%-*.*ls|\n\n",-12, 12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -12, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n",-12, 12, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x negatif et * positif : 	// 24\n\n");

	a = printf(" |%-5.*ls|\n", 12, ws);
	b = ft_printf("f|%-5.*ls|\n\n", 12, ws);
	print_error(a, b);

	a = printf(" |%-30.*ls|\n", 5, ws);
	b = ft_printf("f|%-30.*ls|\n\n", 5, ws);
	print_error(a, b);

	a = printf(" |%-12.*ls|\n", 0, ws);
	b = ft_printf("f|%-12.*ls|\n\n", 0, ws);
	print_error(a, b);

	a = printf(" |%-12.*ls|\n", 12, ws);
	b = ft_printf("f|%-12.*ls|\n\n", 12, ws);
	print_error(a, b);

		a = printf(" |%-12.*ls|\n", 30, ws);
	b = ft_printf("f|%-12.*ls|\n\n", 30, ws);
	print_error(a, b);

	printf("*-------------------------------A FAIRE -----------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif et * negatif : 	// 25\n\n");


	a = printf(" |%*.*ls|\n", -5, -12, ws);
	b = ft_printf("f|%*.*ls|\n\n", -5, -12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -5, -12, ws);
	b = ft_printf("f|%-*.*ls|\n\n", -5, -12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 5, -12, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 5, -12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 5, -12, ws);
	b = ft_printf("f|%*.*ls|\n\n", 5, -12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -5, 12, ws);
	b = ft_printf("f|%*.*ls|\n\n", -5, 12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -12, 5, ws);
	b = ft_printf("f|%*.*ls|\n\n", -12, 5, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", 12, -5, ws);
	b = ft_printf("f|%*.*ls|\n\n", 12, -5, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -12, -5, ws);
	b = ft_printf("f|%*.*ls|\n\n", -12, -5, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -12, -5, ws);
	b = ft_printf("f|%-*.*ls|\n\n",  -12, -5, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 12, -5, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 12, -5, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -12, -12, ws);
	b = ft_printf("f|%*.*ls|\n\n", -12, -12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -12, -12, ws);
	b = ft_printf("f|%-*.*ls|\n\n",  -12, -12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 12, -12, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 12, -12, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -12, -0, ws);
	b = ft_printf("f|%*.*ls|\n\n", -12, -0, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 12, -0, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 12, -0, ws);
	print_error(a, b);

	a = printf(" |%*.*ls|\n", -0, -12, ws);
	b = ft_printf("f|%*.*ls|\n\n", -0, -12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", -0, -12, ws);
	b = ft_printf("f|%-*.*ls|\n\n",  -0, -12, ws);
	print_error(a, b);

	a = printf(" |%-*.*ls|\n", 0, -12, ws);
	b = ft_printf("f|%-*.*ls|\n\n", 0, -12, ws);
	print_error(a, b);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x et * negatif : 		// 26\n\n");

	a = printf(" |%-.*ls|\n", -12, ws);
	b = ft_printf("f|%-.*ls|\n\n",  -12, ws);
	print_error(a, b);

	a = printf(" |%-5.*ls|\n", -12, ws);
	b = ft_printf("f|%-5.*ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%-12.*ls|\n",  -5, ws);
	b = ft_printf("f|%-12.*ls|\n\n",  -5, ws);
	print_error(a, b);

	a = printf(" |%-12.*ls|\n", -12, ws);
	b = ft_printf("f|%-12.*ls|\n\n", -12, ws);
	print_error(a, b);

	a = printf(" |%-12.*ls|\n", -0, ws);
	b = ft_printf("f|%-12.*ls|\n\n", -0, ws);
	print_error(a, b);


	ft_printf("%.p", NULL);




printf("\n\n\n\t\t\t..-* HEXADECIMAL *-..\n");

	int x;

	// Hexadecimal | standard neg | standard | INTMAX | INTMIN | 1 | 0 |

	//x = -150;
	//x = 150;
	//x = 179383791;
	//x = INTMAX;
	//x = INTMIN;
	//x = 1;
	x = 0;

	printf(" |%lx|\n", 140731234556040 );
	ft_printf("f|%lx|\n\n", 140731234556040 );
	printf(" |%x|\n", 140731);
	ft_printf("f|%x|\n\n", 140731);
	printf(" |%x|\n", 150);
	ft_printf("f|%x|\n\n", 150);
	printf(" |%x|\n", 17);
	ft_printf("f|%x|\n\n", 17);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x positif:  // 1\n\n");

	printf( " |%1x|\n", x);
	ft_printf( "f|%1x|\n\n", x);

	printf( " |%3x|\n", x);
	ft_printf( "f|%3x|\n\n", x);

	printf( " |%30x|\n", x);
	ft_printf( "f|%30x|\n\n", x);

	printf( " |%1X|\n", x);
	ft_printf( "f|%1X|\n\n", x);

	printf( " |%3X|\n", x);
	ft_printf( "f|%3X|\n\n", x);

	printf( " |%30X|\n", x);
	ft_printf( "f|%30X|\n\n", x);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * positif: // 2\n\n");

	printf( " |%*x|\n",1, x);
	ft_printf( "f|%*x|\n\n", 1, x);

	printf( " |%*x|\n", 3, x);
	ft_printf( "f|%*x|\n\n", 3, x);

	printf( " |%*x|\n", 30, x);
	ft_printf( "f|%*x|\n\n", 30, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x negatif : // 3\n\n");

	printf(" |%-1x|\n", x);
	ft_printf("f|%-1x|\n\n", x);

	printf(" |%-30x|\n", x);
	ft_printf("f|%-30x|\n\n", x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * negatif : / 4\n\n");

	printf(" |%*x|\n", -1, x);
	ft_printf("f|%*x|\n\n", -1, x);

	printf(" |%*x|\n", -30, x);
	ft_printf("f|%*x|\n\n", -30, x);

	printf(" |%-*x|\n", -30, x);
	ft_printf("f|%-*x|\n\n", -30, x);

	printf(" |%-*x|\n", 30, x);
	ft_printf("f|%-*x|\n\n", 30, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.xd ]	avec x positif : // 5\n\n");

	printf(" |%.0x|\n", x);
	ft_printf("f|%.0x|\n\n", x);

	printf(" |%.1x|\n", x);
	ft_printf("f|%.1x|\n\n", x);

	printf(" |%.15x|\n", x);
	ft_printf("f|%.15x|\n\n", x);

	printf(" |%.150x|\n", x);
	ft_printf("f|%.150x|\n\n", x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * positif : // 6\n\n");

	printf(" |%.*x|\n", 0, x);
	ft_printf("f|%.*x|\n\n", 0, x);

	printf(" |%.*x|\n", 1, x);
	ft_printf("f|%.*x|\n\n", 1, x);

	printf(" |%.*x|\n", 15, x);
	ft_printf("f|%.*x|\n\n", 15, x);

	printf(" |%.*x|\n", 150, x);
	ft_printf("f|%.*x|\n\n", 150, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.xd ]	avec x negatif : // 7 WARNING \n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%.*d ]	avec * negatif : // 8\n\n");

	printf(" |%.*x|\n", -0, x);
	ft_printf("f|%.*x|\n\n", -0, x);

	printf(" |%.*x|\n", -1, x);
	ft_printf("f|%.*x|\n\n", -1, x);

	printf(" |%.*x|\n", -15, x);
	ft_printf("f|%.*x|\n\n", -15, x);

	printf(" |%.*x|\n", -150, x);
	ft_printf("f|%.*x|\n\n", -150, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.d ]	avec x positif : // 9\n\n");

	printf(" |%1.x|\n", x);
	ft_printf("f|%1.x|\n\n", x);

	printf(" |%15.x|\n", x);
	ft_printf("f|%15.x|\n\n", x);

	printf(" |%150.x|\n", x);
	ft_printf("f|%150.x|\n\n", x);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * positif :	// 10\n\n");

	printf(" |%*.x|\n", 0, x);
	ft_printf("f|%*.x|\n\n", 0, x);

	printf(" |%*.x|\n", 1, x);
	ft_printf("f|%*.x|\n\n", 1, x);

	printf(" |%*.x|\n", 150, x);
	ft_printf("f|%*.x|\n\n", 150, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.d ]	avec x negatif :	// 11\n\n");

	printf(" |%-1.x|\n", x);
	ft_printf("f|%-1.x|\n\n", x);

	printf(" |%-150.x|\n", x);
	ft_printf("f|%-150.x|\n\n", x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif : 	// 12\n\n");

	printf(" |%*.x|\n", -0, x);
	ft_printf("f|%*.x|\n\n", -0, x);

	printf(" |%*.x|\n", -1, x);
	ft_printf("f|%*.x|\n\n", -1, x);

	printf(" |%*.x|\n", -150, x);
	ft_printf("f|%*.x|\n\n", -150, x);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x et y positif : 	// 13\n\n");

	printf(" |%5.12x|\n", x);
	ft_printf("f|%5.12x|\n\n", x);

	printf(" |%12.5x|\n", x);
	ft_printf("f|%12.5x|\n\n", x);

	printf(" |%12.0x|\n", x);
	ft_printf("f|%12.0x|\n\n", x);

	printf(" |%12.12x|\n", x);
	ft_printf("f|%12.12x|\n\n", x);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec x et * positif : 	// 14\n\n");

	printf(" |%35.*x|\n", 12, x);
	ft_printf("f|%35.*x|\n\n", 12, x);

	printf(" |%12.*x|\n", 5, x);
	ft_printf("f|%12.*x|\n\n", 5, x);

	printf(" |%12.*x|\n", 0, x);
	ft_printf("f|%12.*x|\n\n", 0, x);

	printf(" |%12.*x|\n", 12, x);
	ft_printf("f|%12.*x|\n\n", 12, x);


	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec *1 et *2 positif :  	// 15\n\n");

	printf(" |%*.*x|\n", 5, 12, x);
	ft_printf("f|%*.*x|\n\n",5, 12, x);

	printf(" |%*.*x|\n", 12, 5, x);
	ft_printf("f|%*.*x|\n\n",12, 5, x);

	printf(" |%*.*x|\n", 12, 0, x);
	ft_printf("f|%*.*x|\n\n", 12, 0, x);

	printf(" |%*.*x|\n", 0, 12, x);
	ft_printf("f|%*.*x|\n\n", 0, 12, x);

	printf(" |%*.*x|\n", 12, 12, x);
	ft_printf("f|%*.*x|\n\n", 12, 12, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec *1 et y positif : 	// 16\n\n");

	printf(" |%*.12x|\n", 5, x);
	ft_printf("f|%*.12x|\n\n",5, x);

	printf(" |%*.5x|\n", 12, x);
	ft_printf("f|%*.5x|\n\n",12, x);

	printf(" |%*.0x|\n", 12, x);
	ft_printf("f|%*.0x|\n\n", 12, x);

	printf(" |%*.12x|\n", 0, x);
	ft_printf("f|%*.12x|\n\n", 0, x);

	printf(" |%*.12x|\n", 12, x);
	ft_printf("f|%*.12x|\n\n", 12, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x negatif et y positif : 	// 17\n\n");

	printf(" |%-5.12x|\n", x);
	ft_printf("f|%-5.12x|\n\n", x);

	printf(" |%-12.5x|\n", x);
	ft_printf("f|%-12.5x|\n\n", x);

	printf(" |%-12.0x|\n", x);
	ft_printf("f|%-12.0x|\n\n", x);

	printf(" |%-12.12x|\n", x);
	ft_printf("f|%-12.12x|\n\n", x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec * negatif et y positif : 	// 18\n\n");

	printf(" |%*.12x|\n", -5, x);
	ft_printf("f|%*.12x|\n\n", -5, x);

	printf(" |%-*.12x|\n", -5, x);
	ft_printf("f|%-*.12x|\n\n", -5, x);

	printf(" |%-*.12x|\n", 5, x);
	ft_printf("f|%-*.12x|\n\n", 5, x);

	printf(" |%*.12x|\n", 5, x);
	ft_printf("f|%*.12x|\n\n", 5, x);

	printf(" |%*.5x|\n", -12, x);
	ft_printf("f|%*.5x|\n\n", -12, x);

	printf(" |%-*.5x|\n", -12, x);
	ft_printf("f|%-*.5x|\n\n", -12, x);

	printf(" |%-*.5x|\n", 12, x);
	ft_printf("f|%-*.5x|\n\n", 12, x);

	printf(" |%*.0x|\n", -12, x);
	ft_printf("f|%*.0x|\n\n", -12, x);

	printf(" |%-*.0x|\n", 12, x);
	ft_printf("f|%-*.0x|\n\n", 12, x);

	printf(" |%-*.0x|\n", -12, x);
	ft_printf("f|%-*.0x|\n\n", -12, x);

	printf(" |%*.12x|\n", -0, x);
	ft_printf("f|%*.12x|\n\n",-0, x);

	printf(" |%-*.12x|\n", -0, x);
	ft_printf("f|%-*.12x|\n\n",-0, x);

	printf(" |%-*.12x|\n", -12, x);
	ft_printf("f|%-*.12x|\n\n",-12, x);

	printf(" |%*.12x|\n", -12, x);
	ft_printf("f|%*.12x|\n\n",-12, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.yd ]	avec * positif et y negatif : WARNING ok	// 19\n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x positif et * negatif :	// 20 \n\n");

	printf(" |%5.*x|\n", -12, x);
	ft_printf("f|%5.*x|\n\n", -12, x);

	printf(" |%-12.*x|\n", 5, x);
	ft_printf("f|%-12.*x|\n\n", 5, x);

	printf(" |%12.*x|\n", -5, x);
	ft_printf("f|%12.*x|\n\n", -5, x);

	printf(" |%-5.*x|\n", -12, x);
	ft_printf("f|%-5.*x|\n\n", -12, x);

	printf(" |%12.*x|\n", -12, x);
	ft_printf("f|%12.*x|\n\n", -12, x);

	printf(" |%12.*x|\n", -0, x);
	ft_printf("f|%12.*x|\n\n", -0, x);

	printf(" |%*.*x|\n", 12, 5, x);
	ft_printf("f|%*.*x|\n", 12, 5, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * positif et * negatif : 	// 21\n\n");

	printf(" |%*.*x|\n", 5, -12, x);
	ft_printf("f|%*.*x|\n\n",5,  -12, x);

	printf(" |%*.*x|\n", 12, -12, x);
	ft_printf("f|%*.*x|\n\n", 12, -12, x);

	printf(" |%*.*x|\n",12,  -5, x);
	ft_printf("f|%*.*x|\n\n",12,  -5, x);

	printf(" |%*.*x|\n", 12, -0, x);
	ft_printf("f|%*.*x|\n\n", 12, -0, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.yd ]	avec x positif et y negatif : WARNING ok // 22 \n\n");

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.*d ]	avec * negatif et * positif :  	// 23\n\n");

	printf(" |%*.*x|\n", -5, 12, x);
	ft_printf("f|%*.*x|\n\n", -5, 12, x);

	printf(" |%-*.*x|\n", -5, 12, x);
	ft_printf("f|%-*.*x|\n\n", -5, 12, x);

	printf(" |%-*.*x|\n", 5, 12, x);
	ft_printf("f|%-*.*x|\n\n", 5, 12, x);

	printf(" |%*.*x|\n", 5, 12, x);
	ft_printf("f|%*.*x|\n\n", 5, 12, x);

	printf(" |%*.*x|\n", -30, 5, x);
	ft_printf("f|%*.*x|\n\n", -30, 5, x);

	printf(" |%-*.*x|\n", -30, 5, x);
	ft_printf("f|%-*.*x|\n\n", -30, 5, x);

	printf(" |%-*.*x|\n", 30, 5, x);
	ft_printf("f|%-*.*x|\n\n", 30, 5, x);

	printf(" |%*.*x|\n", -30, 0, x);
	ft_printf("f|%*.*x|\n\n", -30, 0, x);

	printf(" |%-*.*x|\n", 30, 0, x);
	ft_printf("f|%-*.*x|\n\n", 30, 0, x);

	printf(" |%-*.*x|\n", -30, 0, x);
	ft_printf("f|%-*.*x|\n\n", -30, 0, x);

	printf(" |%*.*x|\n", -0, 12, x);
	ft_printf("f|%*.*x|\n\n",-0, 12, x);

	printf(" |%-*.*x|\n", -0, 12, x);
	ft_printf("f|%-*.*x|\n\n",-0, 12, x);

	printf(" |%-*.*x|\n", -12, 12, x);
	ft_printf("f|%-*.*x|\n\n",-12, 12, x);

	printf(" |%*.*x|\n", -12, 12, x);
	ft_printf("f|%*.*x|\n\n",-12, 12, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x negatif et * positif : 	// 24\n\n");

	printf(" |%-5.*x|\n", 12, x);
	ft_printf("f|%-5.*x|\n\n", 12, x);

	printf(" |%-30.*x|\n", 5, x);
	ft_printf("f|%-30.*x|\n\n", 5, x);

	printf(" |%-12.*x|\n", 0, x);
	ft_printf("f|%-12.*x|\n\n", 0, x);

	printf(" |%-12.*x|\n", 12, x);
	ft_printf("f|%-12.*x|\n\n", 12, x);

	printf("*-------------------------------A FAIRE -----------------------*\n");
	printf("*** **  *** 	CAS		[ %%*.d ]	avec * negatif et * negatif : 	// 25\n\n");

	printf(" |%*.*x|\n", -5, -12, x);
	ft_printf("f|%*.*x|\n\n", -5, -12, x);

	printf(" |%-*.*x|\n", -5, -12, x);
	ft_printf("f|%-*.*x|\n\n", -5, -12, x);

	printf(" |%-*.*x|\n", 5, -12, x);
	ft_printf("f|%-*.*x|\n\n", 5, -12, x);

	printf(" |%*.*x|\n", 5, -12, x);
	ft_printf("f|%*.*x|\n\n", 5, -12, x);

	printf(" |%*.*x|\n", -5, 12, x);
	ft_printf("f|%*.*x|\n\n", -5, 12, x);

	printf(" |%*.*x|\n", -12, 5, x);
	ft_printf("f|%*.*x|\n\n", -12, 5, x);

	printf(" |%*.*x|\n", 12, -5, x);
	ft_printf("f|%*.*x|\n\n", 12, -5, x);

	printf(" |%*.*x|\n", -12, -5, x);
	ft_printf("f|%*.*x|\n\n", -12, -5, x);

	printf(" |%-*.*x|\n", -12, -5, x);
	ft_printf("f|%-*.*x|\n\n",  -12, -5, x);

	printf(" |%-*.*x|\n", 12, -5, x);
	ft_printf("f|%-*.*x|\n\n", 12, -5, x);

	printf(" |%*.*x|\n", -12, -12, x);
	ft_printf("f|%*.*x|\n\n", -12, -12, x);

	printf(" |%-*.*x|\n", -12, -12, x);
	ft_printf("f|%-*.*x|\n\n",  -12, -12, x);

	printf(" |%-*.*x|\n", 12, -12, x);
	ft_printf("f|%-*.*x|\n\n", 12, -12, x);

	printf(" |%*.*x|\n", -12, -0, x);
	ft_printf("f|%*.*x|\n\n", -12, -0, x);

	printf(" |%-*.*x|\n", 12, -0, x);
	ft_printf("f|%-*.*x|\n\n", 12, -0, x);

	printf(" |%*.*x|\n", -0, -12, x);
	ft_printf("f|%*.*x|\n\n", -0, -12, x);

	printf(" |%-*.*x|\n", -0, -12, x);
	ft_printf("f|%-*.*x|\n\n",  -0, -12, x);

	printf(" |%-*.*x|\n", 0, -12, x);
	ft_printf("f|%-*.*x|\n\n", 0, -12, x);

	printf(" |%-*.*x|\n", -12, -0, x);
	ft_printf("f|%-*.*x|\n\n",  -12, -0, x);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%x.*d ]	avec x et * negatif : 		// 26\n\n");

	printf(" |%-.*x|\n", -12, x);
	ft_printf("f|%-.*x|\n\n",  -12, x);

	printf(" |%-5.*x|\n", -12, x);
	ft_printf("f|%-5.*x|\n\n", -12, x);

	printf(" |%-12.*x|\n",  -5, x);
	ft_printf("f|%-12.*x|\n\n",  -5, x);

	printf(" |%-12.*x|\n", -12, x);
	ft_printf("f|%-12.*x|\n\n", -12, x);

	printf(" |%-12.*x|\n", -0, x);
	ft_printf("f|%-12.*x|\n\n", -0, x);



printf("\n\n\n\t\t\t..-* ADRESSE *-..\n");


	void *p;
	long int c_ptr;
	unsigned int c_ptr2 = 179383791;

	c_ptr = 10;
	//   pointeur valable | c_ptr | c-ptr2 hexadecimal | NULL |
	p = &c_ptr;
	p = c_ptr2;
	p = NULL;

	printf(" |%-30p|\n", p);
	ft_printf("f|%-30p|\n\n", p);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x positif:  // 1\n\n");

	printf( " |%1p|\n", p);
	ft_printf( "f|%1p|\n\n", p);

	printf( " |%18p|\n", p);
	ft_printf( "f|%18p|\n\n", p);

	printf( " |%30p|\n", p);
	ft_printf( "f|%30p|\n\n", p);
	
	//	printf( " |%030p|\n", p);
	//ft_printf( "f|%030p|\n\n", p);

	printf("\n\n*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * positif: // 2\n\n");

	printf( " |%*p|\n",1, p);
	ft_printf( "f|%*p|\n\n", 1, p);

	printf( " |%*p|\n", 18, p);
	ft_printf( "f|%*p|\n\n", 18, p);

	printf( " |%*p|\n", 30, p);
	ft_printf( "f|%*p|\n\n", 30, p);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%xd ]	avec x negatif : // 3\n\n");

	printf(" |%-1p|\n", p);
	ft_printf("f|%-1p|\n\n", p);

	printf(" |%-30p|\n", p);
	ft_printf("f|%-30p|\n\n", p);

	printf("*------------------------------------------------------*\n");
	printf("*** **  *** 	CAS		[ %%*d ]	avec * negatif : / 4\n\n");

	printf(" |%*p|\n", -1, p);
	ft_printf("f|%*p|\n\n", -1, p);

	printf(" |%*p|\n", -0, p);
	ft_printf("f|%*p|\n\n", -0, p);

	printf(" |%*p|\n", -30, p);
	ft_printf("f|%*p|\n\n", -30, p);

	printf(" |%-*p|\n", -30, p);
	ft_printf("f|%-*p|\n\n", -30, p);

	printf(" |%-*p|\n", 30, p);
	ft_printf("f|%-*p|\n\n", 30, p);

	printf("%d ",	printf(" |%-*p|\n", 30, p));
	ft_printf("%d", ft_printf("f|%-*p|\n", 30, p));

/*printf("\n\n\n\t\t\t..-* CUMUL *-..\n");


	int cumul_x = 179383791;
	char cumul_c = 'c';
	char *cumul_s = "this is cumul chaine";
	void *cumul_ad = &cumul_x;
	int result;
	int result2;

	result = printf("le int max = %d\nuint max = %u\nune adresse = %p\nun hexadecimal = %x et %X\nune chaine = %s\nun char = %c\n\n",
		INTMAX, UMAX, cumul_ad, cumul_x, cumul_x, cumul_s, cumul_c);

	result2 = ft_printf("le int max = %d\nuint max = %u\nune adresse = %p\nun hexadecimal = %x et %X\nune chaine = %s\nun char = %c\n\n",
		INTMAX, UMAX, cumul_ad, cumul_x, cumul_x, cumul_s, cumul_c);

	ft_printf("result 1 = %d\n result 2 = %d\n", result, result2);




	result = printf(" |%lhhlt|\n");
	result2 = ft_printf("f|%lhhlt|\n");
	ft_printf("result 1 = %d\nresult 2 = %d\n", result, result2);

	printf(" |%llu|\n", ULLONG_MAX);
	ft_printf("f|%llu|\n", (unsigned long long)~0);
	ft_printf("f|%llu|\n", ULLONG_MAX);

	printf("%u\n", (unsigned int)~0);
	ft_printf("%u\n", (unsigned int)~0);

	//printf("%d\n", (int)~(~(0) >> 1));
	//ft_printf("%d\n", (int)(-1 >> 1));

	printf("%lu\n", (unsigned long)~0);
	ft_printf("%lu\n", (unsigned long)~0);

	printf("%ld\n", (long)~0);
	ft_printf("%ld\n", (long)~0);

	//printf(" |%15.*% milieu %d|\n", 10, 25);
	//ft_printf("f|%15.*% milieu %d|\n",10, 25);


	printf(" |%lld|\n", cumul_ad);
	ft_printf("f|%lld|\n\n", cumul_ad);

	printf(" |%lld|\n", cumul_ad);
	ft_printf("f|%lld|\n\n", cumul_ad);

	printf(" |%llx|\n", cumul_ad);
	ft_printf("f|%llx|\n\n", cumul_ad);

	printf(" |%p|\n", cumul_ad);
	ft_printf("f|%p|\n\n", cumul_ad);

	printf(" |%p|\n", NULL);
	ft_printf("f|%p|\n\n", NULL);

	printf("\\%c\n", 98);
	ft_printf("\\%c\n", 98);

	printf("%\\c\n", 98);
	ft_printf("%\\c\n", 98);


		int nbr;

		printf("|%1.0d|\n", 0);
		ft_printf("|%1.0d|\n\n", 0);

	//	printf("|%08.3d|\n", -45);
	//	ft_printf("|%08.3d|\n\n", -45);

		printf("|%05d|\n", -45);
		ft_printf("|%05d|\n\n", -45);

		nbr = printf("|%-8c|\n", 'g');
		printf("%d\n", nbr);
		nbr = ft_printf("|%-8c|\n", 'g');
		printf("%d\n", nbr);

		nbr =  printf("%%");
		printf("\n");
		nbr = ft_printf("%%");
		printf("\n");
*/
/*
				printf(" |%x|\n", -42);
				ft_printf("f|%x|\n", -42);

				printf(" |%x|\n", 42);
				ft_printf("f|%x|\n", 42);

					printf(" |%x|\n", 0);
				ft_printf("f|%x|\n", 0);

				printf(" |%p|\n", NULL);
				ft_printf("f|%p|\n", NULL);

				printf(" |%.p|\n", NULL);
				ft_printf("f|%.p|\n", NULL);

				printf( "%.0d", 0 );
				ft_printf( "%.0d", 0 );

				printf( "%.d", 0 );
				ft_printf( "%.d", 0 );
				printf("\n");
*/
/*

	char	*ptr_vide = NULL;
	
	a = printf(" |%.5s|\n", ptr_vide);
	b = ft_printf("f|%.5s|\n", ptr_vide);
	
	a = printf(" |%.15s|\n", ptr_vide);
	b = ft_printf("f|%.15s|\n", ptr_vide);
	
	a = printf(" |%p|\n", 18);
	b = ft_printf("f|%p|\n", 18);
	

	
	printf(" |%lx|\n", 140731234556040 );
	ft_printf("f|%lx|\n\n", 140731234556040 );

	printf(" |%x|\n", 140731234556040 );
	ft_printf("f|%x|\n\n", 140731234556040 );

	printf(" |%hx|\n", 140731234556040 );
	ft_printf("f|%hx|\n\n", 140731234556040 );
*/
/*
	printf(" |%x|\n", -1 );
	ft_printf("f|%x|\n\n", -1);

	printf(" |%lx|\n", -1 );
	ft_printf("f|%lx|\n\n", -1);

	printf(" |%llx|\n", -1 );
	ft_printf("f|%llx|\n\n", -1);

	printf(" |%u|\n", -1 );
	ft_printf("f|%u|\n\n", -1);

	printf(" |%lu|\n", -1 );
	ft_printf("f|%lu|\n\n", -1);

	printf(" |%llu|\n", -1 );
	ft_printf("f|%llu|\n\n", -1);
*/

	//	printf(" |%llx|\n", 140731234556040 );
	//	ft_printf("f|%llx|\n\n", 140731234556040 );

/*	printf("%lllkkkk\n", 5);
	ft_printf("%lllkkkk\n", 5);

	printf("%hld\n", 140731234556040);
	ft_printf("%hld\n", 140731234556040);

	printf("1|%C|\n", L'𢁅');
	printf("2|%lc|\n", L'𢁅');
	ft_printf("2|%lc|\n\n", L'𢁅');
	printf("3|%c|\n", L'𢁅');
	ft_printf("3|%c|\n", L'𢁅');


	//	printf("4|%hc|\n", 100);  WARNING
	//	ft_printf("4|%hc|\n", 100);


	printf("ο Δικαιοπολις εν αγρω εστιν\n");
	ft_printf("ο Δικαιοπολις εν αγρω εστιν\n\n");

	printf("%%s = %s\n", "ο Δικαιοπολις εν αγρω εστιν\n");
	ft_printf("%%s = %s\n", "ο Δικαιοπολις εν αγρω εστιν\n\n");

	wc = L'𢁅';
	wc = L'ﷰ';
	int *str_unicode = L"ﷰ𢁅Διﷰκαιοπολις";
	wchar_t *str2_unicode = L"ﷰ𢁅Διﷰκαιοπολις";

	printf("c int = %c\n", wc);
	ft_printf("c int = %c\n", wc);

	printf("c wchar = %c\n", wc);	
	ft_printf("c wchar = %c\n\n", wc);

	printf("lc int =  |%lc|\n", wc);
	ft_printf("lc int = f|%lc|\n\n", wc);
	
	printf("lc int = %lc\n", wc);
	ft_printf("lc int = %lc\n\n", wc);

	printf("lc wtchar = %lc\n", wc);
	ft_printf("lc wtchar = %lc\n\n", wc);

	printf("s int * = %s\n", str_unicode);
	ft_printf("s int * = %s\n\n", str_unicode);

	printf("ls int * = %ls\n", str_unicode);
	ft_printf("ls int * = %ls\n\n", str_unicode);

	printf("s wchar * = %s\n", str2_unicode);
	ft_printf("s wchar * = %s\n\n", str2_unicode);

	printf("ls wchar * = %ls\n", str2_unicode);
	ft_printf("ls wchar * = %ls\n\n", str2_unicode);


	//		printf(" |%c\n", 98);
	//	ft_printf("f|%c\n", 98);

	printf(" |%d\n", printf(""));
  	printf("f|%d\n",ft_printf(""));
*/
/*
	int *e = NULL;

	a = printf("f|%p\n", e);
	b = ft_printf(" |%p\n\n", e);
	print_error(a, b);

	a = printf("f|%p\n", NULL);
	b = ft_printf(" |%p\n\n", NULL);
	print_error(a, b);


	a = printf("f|%p\n", (void *)0);
	b = ft_printf(" |%p\n\n", (void *)0);
	print_error(a, b);
	


	a = printf("|%5%|\n"); 
	b = ft_printf("|%5%|\n\n");
	print_error(a, b); 
	
	a = printf("|%-5%|\n"); 
	b = ft_printf("|%-5%|\n\n");
	print_error(a, b);

	a = printf("|%-05%|\n"); 
	b = ft_printf("|%-05%|\n\n");
	print_error(a, b);

	a = printf("|%05%|\n");
	b = ft_printf("|%05%|\n\n");
	print_error(a, b);

	a = printf("|%0.5%|\n");
	b = ft_printf("|%0.5%|\n\n");
	print_error(a, b);

	a = printf("|%025.10%|\n");
	b = ft_printf("|%025.10%|\n\n");
	print_error(a, b);

	a = printf("|%02.10%|\n");
	b = ft_printf("|%02.10%|\n\n");
	print_error(a, b);

		a = printf("|%05.%|\n");
	b = ft_printf("|%05.%|\n\n");
	print_error(a, b);

		a = printf("|%05.0%|\n");
	b = ft_printf("|%05.0%|\n\n");
	print_error(a, b);

/*	a = printf("%x\n", 42);
	b = ft_printf("%x\n\n", 42);
	print_error(a, b);

	a = printf(" |%2c|\n", 0);
	b = ft_printf("f|%2c|\n\n", 0);
	print_error(a, b);

	a = printf(" |%1c|\n", 0);
	b = ft_printf("f|%1c|\n\n", 0);
	print_error(a, b);

	a = printf(" |%4c|\n", 0);
	b = ft_printf("f|%4c|\n\n", 0);
	print_error(a, b);

	a = printf(" |%4c|\n", 'g');
	b = ft_printf("f|%4c|\n\n", 'g');
	print_error(a, b);

	a = printf(" |%2c|\n", 'g');
	b = ft_printf("f|%2c|\n\n", 'g');
	print_error(a, b);

	a = printf("%2c", 0);
	b = ft_printf("%2c\n", 0);
	print_error(a, b);


	//char *s_hidden = "hi low\0don't print me lol\0";

	//a = printf("|%09s|\n", s_hidden);
	//b = ft_printf("|%09s|\n\n", s_hidden);
	//print_error(a, b);

	a = printf("|%.p|\n", NULL);
	b = ft_printf("|%.p|\n\n", NULL);
	print_error(a, b);

	a = printf("|%.0p|\n", NULL);
	b = ft_printf("|%.0p|\n\n", NULL);
	print_error(a, b);

	a = printf("|%.1p|\n", NULL);
	b = ft_printf("|%.1p|\n\n", NULL);
	print_error(a, b);

	a = printf("|%.x|\n", 150);
	b = ft_printf("|%.x|\n\n", 150);
	print_error(a, b);

	a = printf("|%.d|\n", 15);
	b = ft_printf("|%.d|\n\n", 15);
	print_error(a, b);

	a = printf("|%.d|\n", 15);
	b = ft_printf("|%.d|\n\n", 15);
	print_error(a, b);

		a = printf("|%p|\n", 150);
		b = ft_printf("|%p|\n\n", 150);
	print_error(a, b);

	a = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	b = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	print_error(a, b);

	a = printf(" |%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c|\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	b = ft_printf("f|%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c|\n\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	print_error(a, b);
  

  	a = printf("|%034.49hhd\n", 1431044252);
	b = ft_printf("|%034.49hhd\n\n", 1431044252);
*/
/*
	a = printf(" |%0*.*i|\n", 2, -2, 8);
	b = ft_printf("f|%0*.*i|\n\n", 2, -2, 8);
	print_error(a, b);

		a = printf(" |%02.*i|\n", -2, 8);
	b = ft_printf("f|%02.*i|\n\n", -2, 8);

			a = printf(" |%02.*i|\n",2, 8);
	b = ft_printf("f|%02.*i|\n\n",2, 8);
	print_error(a, b);

	a = printf("|%2.0%|\n");
	b = ft_printf("|%2.0%|\n\n");
	print_error(a, b);
*/
	int d = -12;

	printf("-->|%0*.d|<--\n", 4, d);
	ft_printf("-->|%0*.d|<--\n\n", 4, d);
	printf("-->|%0*.%|<--\n", 4);
	ft_printf("-->|%0*.%|<--\n\n", 4);
	printf("-->|%04.d|<--\n", d);
	ft_printf("-->|%04.d|<--\n\n", d);
	printf("-->|%04.d|<--\n", d);	
		ft_printf("-->|%04.d|<--\n", d);	
 	printf("-->|%04.*d|<--\n", -4, d);
	 ft_printf("-->|%04.*d|<--\n", -4, d);
 	printf("-->|%04.*d|<--\n", -3, d); 
	 ft_printf("-->|%04.*d|<--\n", -3, d); 
 	printf("-->|%04.*d|<--\n", -2, d);
	 ft_printf("-->|%04.*d|<--\n", -2, d);
	printf("-->|%0*.d|<--\n", 1, d); 
	ft_printf("-->|%0*.d|<--\n", 1, d); 
 	printf("-->|%0*.d|<--\n", 2, d);
	 ft_printf("-->|%0*.d|<--\n", 2, d);
 	printf("-->|%0*.d|<--\n", 3, d);  
	  ft_printf("-->|%0*.d|<--\n", 3, d);   
	printf("-->|%0*.d|<--\n", 4, d); 
	ft_printf("-->|%0*.d|<--\n", 4, d); 
	
	printf("-->|%0*.%|<--\n", -1); 
	ft_printf("-->|%0*.%|<--\n", -1);
	
	printf("-->|%0*.%|<--\n", 2); 
	ft_printf("-->|%0*.%|<--\n", 2);  
	
	printf("-->|%0*.*%|<--\n", 2, -4);  
	ft_printf("-->|%0*.*%|<--\n", 2, -4);  
	
	printf("-->|%0*.*%|<--\n", 2, -3);  
	ft_printf("-->|%0*.*%|<--\n", 2, -3); 
	printf("-->|%04.3%|<--\n");  
	ft_printf("-->|%04.3%|<--\n");  
	
	printf("-->|%4.3%|<--\n"); 
	ft_printf("-->|%4.3%|<--\n"); 

	printf("-->|%02.3%|<--\n");  
	ft_printf("-->|%02.3%|<--\n");

		printf("-->|%03.3%|<--\n");  
	ft_printf("-->|%03.3%|<--\n");

			printf("-->|%03.2%|<--\n");  
	ft_printf("-->|%03.2%|<--\n");
	
	
return (0);

}
