#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
 

void print_binaire(unsigned wc)
{
	/* pour 32 bits */
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

void print_binaire_8bits(unsigned wc)
{

	/* Pour 8 bits */
	int i;
	printf("%d = \t", wc);
	for (i = 7; i >= 0; i--)
	{
		printf("%d", (wc >> i ) & 1);
		if (i % 4 == 0)
			printf(" ");
	}
	printf("\n"); 
}

int main()
{
	char c = 1;

/*	for (c = 0; c < 20 ; c++)
	{
		printf("%d ", c);
		print_binaire_8bits
	(c);
		printf("\n");
	}*/

	//wchar_t wc = 0;
/*	printf("Operation binaires \n\n\tSHR ou <<  décallage a gauche\n\n");
	printf("0001 << 1 en binaire donne 0010\n0001 << 2 en binaire donne 0100\n");
	printf("exemple pour c = 1  ; c << 1 ;  c << 2\n");
	print_binaire_8bits(c);
	print_binaire_8bits(c << 1);
	print_binaire_8bits(c << 2);

	printf("\n\n\tSHL ou  >>  décallage a droite\n\n");
	printf("1000 >> 1 en binaire donne 0100\n1000 >> 2 en binaire donne 0010\n");
	printf("exemple pour c = 8  ; c >> 1 ;  c >> 2\n");
	print_binaire_8bits(8);
	print_binaire_8bits(8 >> 1);
	print_binaire_8bits(8 >> 2);

	printf("\n\n\tAND ou  &  \n\n");
	printf("1 & 1 = 1\n1 & 0 = 0\n0 & 0 = 0 \n\n");
	
	printf("5 & 12\n");
	print_binaire_8bits(5);
	print_binaire_8bits(12);
	print_binaire_8bits(5 & 12);

		printf("\n107 & 213\n");
	print_binaire_8bits(107);
	print_binaire_8bits(213);
	print_binaire_8bits(107 & 213);


	printf("\n\n\tOU ou  |  \n\n");
	printf("1 | 1 = 1\n1 | 0 = 1\n0 | 0 = 0 \n\n");
	
	printf("5 | 12\n");
	print_binaire_8bits(5);
	print_binaire_8bits(12);
	print_binaire_8bits(5 | 12);

		printf("\n107 | 213\n");
	print_binaire_8bits(107);
	print_binaire_8bits(213);
	print_binaire_8bits(107 | 213);

	printf("\n\n\tXOR ou  ^  si identique 0 si different 1\n\n");
	printf("1 ^ 1 = 0\n1 ^ 0 = 1\n0 ^ 0 = 0 \n\n");
	
	printf("5 ^ 12\n");
	print_binaire_8bits(5);
	print_binaire_8bits(12);
	print_binaire_8bits(5 ^ 12);

		printf("\n107 ^ 213\n");
	print_binaire_8bits(107);
	print_binaire_8bits(213);
	print_binaire_8bits(107 ^ 213);

	printf("\n\n\tNOT ou  ~c = not c, inverse les 0 et les 1\n\n");
	printf("~c => tous les 1 = 0 et tous les 0 = 1\n\n");
	
	printf("5 et ~5\n");
	print_binaire_8bits(5);
	print_binaire_8bits(~5);

	printf("\n12 et ~12\n");
	print_binaire_8bits(12);
	print_binaire_8bits(~12);

	printf("\n213 et ~213\n");
	print_binaire_8bits(213);
	print_binaire_8bits(~213);
*/
/*
**	TRADUCTION D UN HEXA EN BINAIRE :
**
**  BE57 
**	hexa	deci	binaire
** 	B		11		1011
**	E		14		1110
**	5		5		0101
**	7		7		0111
**
**	BE57 = 1011 1110 0101 0111 en binaire
**
** DU BINAIRE EN HEXA : 
**
**1100 0000 1000 0000 = C080 mask 1
**	binaire	deci	hexa
**	1100	12		C
**	0000	0		0
**	1000	8		8
**	0000	0		0

**	1000	8		8
**	1100	12		C
**	1110	14		E
**	1111	15		F
**	0001	1		1
**	0011	3		3

** C080
**
** mask 1 = E0C0								1110 0000	1100 0000
** ~mask 1										0001 1111	0011 1111
**
**					octet 2 :	a >> 8			0001 1111				mb 2
**					octet 1		a				0000 0000	0011 1111	Mb 1
**							
** mask 2 = F0C0					1111 0000	1100 0000	1100 0000
** ~mask2 							0000 1111	0011 1111	0011 1111
**
**				octet 1: 	a		0000 0000	0000 0000	0011 1111 	mb 1
**				octet 2 	a >> 8 										mb 1
**				octet 3		a >> 16 0000 1111							mb 3
**

** mask 3 = F8C0C0 		1111 1000	1100 0000	1100 0000	1100 0000
						 0000 0000	 0000 0010 	0010 0000	0100 0101 		
** ~ mask1 =			0000 0111
**
**				octet 1 a			mb 1
**				octet 2 a >> 8		mb 1
**				octet 3 a >> 16		mb 1
**				octet 4 a >> 24		mb 4
**
**		if mask 1 			mzask 2 		mask 3
	octet1 = 	mb 1		mb 1			mb 1
	octet 2 = 	mb 2		mb 1			mb 1
	octet 3 =	 0			mb 3			mb 1
	octet 4 =	 0			0				mb 4


	if mask 1 

		octet 1 = a & mb 1
		octet 2 = (a >> 8) & mb 2

		write tab[otet]

**
**
*/

/*
	unsigned int mask1 = 0xC080;
	unsigned int mask2 = 0xE08080;
	unsigned int mask3 = 0xF0808080;

	printf("\nmask 1 = %x %x\n", mask1, ~mask1);
	print_binaire(mask1);
	print_binaire(~mask1);

	printf("\nmask 2 =%x %x\n", mask2, ~mask2);
	print_binaire(mask2);
	print_binaire(~mask2);

	printf("\nmask 3 =%x %x\n", mask3, ~mask3);
	print_binaire((unsigned)mask3);
	print_binaire((unsigned)~mask3);
	
	printf("\n\n");

	unsigned int test = 0xC07F;
	char size = -1;

	while (test >> ++size)
		print_binaire(test >> size);
	printf("\n\n");

	#include <locale.h>
	#include <stddef.h>
	#include <unistd.h>

	char happy[] = { 0xe2, 0x98, 0xba };
	write (1, happy, 3);
	setlocale(LC_ALL, NULL);

	wchar_t b = L'Ħ';
	
	printf("\n\n%lc", b);
	print_binaire('Ħ');


	int mask = 0;
	size = -1;
		while (b >> ++size)
			;
	if (size < 8)
	mask = 1;
	else if (size < 16)
	mask = 2;
	else if (size < 24)
	mask = 3;

	printf("mask = %d\n", mask);
	
	printf("%d\n", sizeof(wchar_t));
	


	int mb1 = 0x3F;
	int mb2 = 0x1F00;
	int mb3 = 0xF0000;
	int mb4 = 0x7000000;
	int a = L'𢁅';



	size = -1;
	while (a >> ++size)
		;
	char	*res = 0;
	//res = (a & mb4) | (a & mb3) | (a & mb2) | (a & mb1);

	a  = 'Ħ';
	print_binaire(a);
	print_binaire('Ħ');
	print_binaire(res);

 	res = (a & mb2) | (a & mb1);
	print_binaire(res);
	write(1, res, 2);
	char tab[2];

	tab[0] = mask1 | (a & mb2);
	tab[1] = mask2 | (a & mb1);
	write(1, tab, 2);
*/
	//char happy[] = { 0xe2, 0x98, 0xba };
/*	printf("\n\n");
	write (1, happy, 3);
	printf("\n\n");

	print_binaire(0xe2 << 16 | 0x98 << 8 | 0xba);
	print_binaire(0xe2);
	print_binaire(0x98);
	print_binaire(0xba);
*/
	printf("\nEND TEST\n\n");

	wchar_t wc = '𢁅';
/*	print_binaire(wc);
	print_binaire('𢁅');
	print_binaire(L'𢁅');
	print_binaire((wc >> 8) & 0xff);
	print_binaire((wc >> 16) & 0xff);
	print_binaire((wc >> 24) & 0xff);

*/
unsigned char res[4];
/*	res[0] = wc & 0xff;
	res[1] = ((wc >> 8) & 0xff);
	res[2] = (wc >> 16) & 0xff;
	res[3] = (wc >> 24) & 0xff;

	print_binaire(res[0]);
	print_binaire(res[1]);
	print_binaire(res[2]);
	print_binaire(res[3]);
printf("\n\n");
*/


//res[1] = 0;

/*print_binaire(wc);
print_binaire((unsigned)wc >> 24);
print_binaire(0xff);
print_binaire(((unsigned)wc >> 24) & 0xff);
res[0] = ((unsigned)wc >> 24) & 0xff;
print_binaire(res[1]);
*/
/*
	res[0] = ((unsigned)wc >> 24) & 0xff;
	res[1] = ((unsigned)wc >> 16) & 0xff;
	res[2] = ((unsigned)wc >> 8) & 0xff;
	res[3] = (unsigned)wc & 0xff;


	printf("\n\n");
	print_binaire(wc);
	print_binaire(res[0]);
	print_binaire(res[1]);
	print_binaire(res[2]);
	print_binaire(res[3]);
	write (1, res, 4);
	printf("\n");
*/
	int size = 0;
	wc = 139333;
	while ((unsigned)wc >> ++size)
			;

	res[0] = (((unsigned)wc >> 18) & 0xf) | 0xf0;
	res[1] = (((unsigned)wc >> 12) & 0x3f) | 0x80;
	res[2] =(((unsigned)wc >> 6) & 0x3f) | 0x80;
	res[3] = ((unsigned)wc & 0x3f) | 0x80;
	print_binaire(wc);
	print_binaire(res[0]);
	print_binaire(res[1]);
	print_binaire(res[2]);
	print_binaire(res[3]);
	write (1, res, 4);
	printf("\n");
	if (size <= 6)
		return 0;
	if (size <= 12)
	{

	}
	if (size <= 18)
	{

	}
	else
	{
		
	}
	
/*


void		convert_unicode(t_flag *flag, char size)
{

	unsigned char	octet[size];

	if (size < 12)
	{
		octet[0] = (((unsigned)flag->uarg >> 6) & WC2) | MB2;
		octet[1] =((unsigned)flag->uarg & WC1) | MB1;
	}
	if (size < 18)
	{
		octet[0] = (((unsigned)flag->uarg >> 12) & WC3) | MB3;
		octet[1] = (((unsigned)flag->uarg >> 6) & WC1) | MB1;
		octet[2] = ((unsigned)flag->uarg  & WC1) | MB1;
	}
	else
	{
		octet[0] = (((unsigned)flag->uarg >> 18) & WC4) | MB4;
		octet[1] = (((unsigned)flag->uarg >> 12) & WC1) | MB1;
		octet[2] = (((unsigned)flag->uarg >> 6) & WC1) | MB1;
		octet[3] = ((unsigned)flag->uarg & WC1) | MB1;
	}

	int oct;
	
	oct = 0xF0808080 | ((unsigned)flag->uarg << 6) & 0x7000000)
					| ((unsigned)flag->uarg << 4) & 0x3F0000)
					| ((unsigned)flag->uarg << 2) & 0x3F00)
					| ((unsigned)flag->uarg & 0x3F)
	write(1, octet, 4);
printf("\n\n");
}



139333 en binaire : 		0000	0000	xx10 0010 	xx00 0001	xx00 0101 
							1111 	xxxx	10xx xxxx 	10xx xxxx 	10xx xxxx
139333 en binaire : 	0000 0000 0010 0010 1000 0001 1000 0101 
-257785467 en binaire : 1111 0000 1010 0010 1000 0001 1000 0101 
240 en binaire :        0000 0000 0000 0000 0000 0000 1111 0000 
162 en binaire :        0000 0000 0000 0000 0000 0000 1010 0010 
129 en binaire :        0000 0000 0000 0000 0000 0000 1000 0001 
133 en binaire :        0000 0000 0000 0000 0000 0000 1000 0101 
𢁅
*/
	return 0;
}