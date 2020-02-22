/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:35:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/22 18:59:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Mise en place des 4 masques binaires
**
**										 		8765 4321
** mask0 = 										0XXX XXXX  1 octet =  8 bits
** mask1 = 							110X XXXX   10XX XXXX  2 octet = 16 bits 
** mask2 = 		  		1110 XXXX	10XX XXXX	10XX XXXX  3 octet = 24 bits
** mask3 = 1111 0XXX	10XX XXXX	10XX XXXX	10XX XXXX  4 octet = 32 bits
** 
** mask0 =  1 bit mask  et 7 flag->arghar 
** mask1 =  5 bits mask et 11 flag->arghar	on garde 5 puis  (on passe 2 << on garde 6 x) 
** mask2 =  8 bits mask et 16 flag->arghar	on garde 4 puis  (on passe 2 << on garde 6 x) x 2 
** mask3 = 11 bits mask et 21 flag->arghar	on garde 3 puis  (on passe 2 << on garde 6 x) x 3 
**
** 	Verification de la taille du flag->arghar
** 	relation avec les mask
** 
** size < 8 : pas de mask
** size < 16 : mask 1
** size < 24 : mask 2
** size < 32 : mask 3
**
**			diviser chaque octet du flag->arg et en faire un tableau : 
** char flag->arg[size] = [octet1][octet2][octet3][octet4]  ou l'inverse a verifier
**
** write (1, flag->arg, size);
*/

void print_binaire(unsigned wc)
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
**  Récupère la taille du wchar pour envoi en conversion
*/

int		char_or_unicode(t_flag *flag)
{
	char 			size;
	int				nb_oct;

	size = 0;
	while ((unsigned)flag->uarg >> size)
		size++;
	if (size < 8)
		nb_oct = 1;
	else if (size < 12)
		nb_oct = 2;
	else if (size < 18)
		nb_oct = 3;
	else
		nb_oct = 4;
	return (nb_oct);
}

/*
** Masque binaires et leur correspondance pour reception d'octet.
** MB1  = 	0x80 =	10xx xxxx
** WC1  = 	0x3F = 	0011 1111
** 
** MB2  =	0xC0 =	110x xxxx
** WC2  =	0x1F =	0001 1111
**
** MB3  = 	0xE0 = 	1110 xxxx
** WC3  = 	0xF	 = 	0000 1111
**
** MB4  = 	0xF0 = 	1111 0xxx
** WC4  = 	7	 =	0000 0111
** 
*/

int		convert_unicode(t_flag *flag, int nb_oct)
{
	unsigned char	octet[nb_oct];
	
	ft_bzero(octet, nb_oct);
	if (nb_oct == 1)
		octet[0] = (unsigned char)flag->uarg;
	else if (nb_oct == 2)
	{
		octet[0] = (((unsigned)flag->uarg >> 6) & WC2) | MB2;
		octet[1] = ((unsigned)flag->uarg & WC1) | MB1;
	}
	else if (nb_oct == 3)
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
/*	print_binaire(flag->uarg);
	print_binaire(octet[0]);
	print_binaire(octet[1]);
	print_binaire(octet[2]);
	print_binaire(octet[3]);
*/	write(1, octet, nb_oct);
	return (nb_oct);
	//s = (char *)octet;
	//write(1, s, 4);
	//return (s);

	/*

		(1111 0)000 (10)10 0010 (10)00 0001 (10)00 0101
			<< 6			<<4			<< 2

		1111 0000
		0000 0111

		1000 0000	0000 0000	0000 0000	mask 3 	= 800000 | (arg >> 12) & mask 3b
		0011 1111	0000 0000	0000 0000  	mask 3b = 3f0000

					1000 0000 	0000 0000	mask 2  = 8000 | (arg >> 6) & 3f00)
					0011 1111	0000 0000	mask 2b = 3f00

								10xx xxxx	mask 1 = 80 | (arg & 3f)		
								0011 1111	mask 1b = 3f

	*/


/*	wchar_t oct;
	printf("sizeof wchart = %ld\n", sizeof(wchar_t));
	oct = 0;

	oct = ((0xf0000000 | (((unsigned)flag->uarg << 6) & 0x7000000)) |
		(0x800000 | (((unsigned)flag->uarg << 4) & 0x3f0000)) |
		(0x8000 | (((unsigned)flag->uarg << 2) & 0x3f00)) |
		(0x80 | ((unsigned)flag->uarg & 0x3f)));
	oct = 0xF0808080 | (((unsigned)flag->uarg << 6) & 0x7000000)
					| (((unsigned)flag->uarg << 4) & 0x3F0000)
					| (((unsigned)flag->uarg << 2) & 0x3F00)
					| ((unsigned)flag->uarg & 0x3F);
*/	
/*	print_binaire(flag->uarg << 2);
	print_binaire(0x3f00);
	print_binaire((flag->uarg << 2 ) & 0x3f00);
	print_binaire(0x8000);
	print_binaire(oct);
	printf("sizeof wchart = %ld\n", sizeof(wchar_t));

	s = (char)&oct;
*///	write(1, oct, 4);
//	write (1, s, 4);
	//flag->uarg = oct;
	//print_binaire(flag->uarg);
	
	//s = ft_itoa(oct);
	//write(1, &oct, 4);
	//return (s);
	//return (octet);
	//write(1, octet, 4);
//	printf("%lc\n", oct);
	//write(1, s, ft_strlen(s));
}
