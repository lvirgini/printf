/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:35:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/27 17:50:34 by lvirgini         ###   ########.fr       */
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
**	///* diviser chaque octet du flag->arg et en faire un tableau : 
** char flag->arg[size] = [octet1][octet2][octet3][octet4]  ou l'inverse a verifier
**
** write (1, flag->arg, size);
*/


/*
**  Récupère la taille du wchar pour envoi en conversion
*/

void		c_unicode(va_list args, t_flag *flag)
{
	char 		size;

	flag->uarg = va_arg(args, int);
	size = -1;
	while ((unsigned)flag->uarg >> ++size)
		;
	if (size < 8)
		print_character(args, flag);
	else
		convert_unicode(flag, size);
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

/*	unsigned int oct;
	oct = 0;
	oct = 0xF0808080 | (((unsigned)flag->uarg << 6) & 0x7000000)
					| (((unsigned)flag->uarg << 4) & 0x3F0000)
					| (((unsigned)flag->uarg << 2) & 0x3F00)
					| ((unsigned)flag->uarg & 0x3F);
*/	
	char *s;
	
	s = octet;
	//write(1, octet, 4);
	write(1, s, 4);


printf("\n\n");
}