/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:37:41 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 17:55:27 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdefs.h"
#include <stdlib.h>

t_dict	**get_val_dict(void)
{
	t_dict	**dict;

	dict = malloc(sizeof(void *) * 29);
	dict[0] = malloc(sizeof(t_dict));
	dict[0]->name = "zero";
	dict[0]->value = 0;
	dict[1] = malloc(sizeof(t_dict));
	dict[1]->name = "one";
	dict[1]->value = 1;
	dict[2] = malloc(sizeof(t_dict));
	dict[2]->name = "two";
	dict[2]->value = 2;
	dict[3] = malloc(sizeof(t_dict));
	dict[3]->name = "three";
	dict[3]->value = 3;
	dict[4] = malloc(sizeof(t_dict));
	dict[4]->name = "four";
	dict[4]->value = 4;
	dict[5] = malloc(sizeof(t_dict));
	dict[5]->name = "five";
	dict[5]->value = 5;
	dict[6] = malloc(sizeof(t_dict));
	dict[6]->name = "six";
	dict[6]->value = 6;
	dict[7] = malloc(sizeof(t_dict));
	dict[7]->name = "seven";
	dict[7]->value = 7;
	dict[8] = malloc(sizeof(t_dict));
	dict[8]->name = "eight";
	dict[8]->value = 8;
	dict[9] = malloc(sizeof(t_dict));
	dict[9]->name = "nine";
	dict[9]->value = 9;
	dict[10] = malloc(sizeof(t_dict));
	dict[10]->name = "ten";
	dict[10]->value = 10;
	dict[11] = malloc(sizeof(t_dict));
	dict[11]->name = "eleven";
	dict[11]->value = 11;
	dict[12] = malloc(sizeof(t_dict));
	dict[12]->name = "twelve";
	dict[12]->value = 12;
	dict[13] = malloc(sizeof(t_dict));
	dict[13]->name = "thirteen";
	dict[13]->value = 13;
	dict[14] = malloc(sizeof(t_dict));
	dict[14]->name = "fourteen";
	dict[14]->value = 14;
	dict[15] = malloc(sizeof(t_dict));
	dict[15]->name = "fifteen";
	dict[15]->value = 15;
	dict[16] = malloc(sizeof(t_dict));
	dict[16]->name = "sixteen";
	dict[16]->value = 16;
	dict[17] = malloc(sizeof(t_dict));
	dict[17]->name = "seventeen";
	dict[17]->value = 17;
	dict[18] = malloc(sizeof(t_dict));
	dict[18]->name = "eighteen";
	dict[18]->value = 18;
	dict[19] = malloc(sizeof(t_dict));
	dict[19]->name = "nineteen";
	dict[19]->value = 19;
	dict[20] = malloc(sizeof(t_dict));
	dict[20]->name = "twenty";
	dict[20]->value = 20;
	dict[21] = malloc(sizeof(t_dict));
	dict[21]->name = "thirty";
	dict[21]->value = 30;
	dict[22] = malloc(sizeof(t_dict));
	dict[22]->name = "forty";
	dict[22]->value = 40;
	dict[23] = malloc(sizeof(t_dict));
	dict[23]->name = "fifty";
	dict[23]->value = 50;
	dict[24] = malloc(sizeof(t_dict));
	dict[24]->name = "sixty";
	dict[24]->value = 60;
	dict[25] = malloc(sizeof(t_dict));
	dict[25]->name = "seventy";
	dict[25]->value = 70;
	dict[26] = malloc(sizeof(t_dict));
	dict[26]->name = "eighty";
	dict[26]->value = 80;
	dict[27] = malloc(sizeof(t_dict));
	dict[27]->name = "ninety";
	dict[27]->value = 90;
	dict[28] = malloc(sizeof(t_dict));
	dict[28]->name = "hundred";
	dict[28]->value = 100;
	dict[0]->next = dict[1];
	dict[1]->next = dict[2];
	dict[2]->next = dict[3];
	dict[3]->next = dict[4];
	dict[4]->next = dict[5];
	dict[5]->next = dict[6];
	dict[6]->next = dict[7];
	dict[7]->next = dict[8];
	dict[8]->next = dict[9];
	dict[9]->next = dict[10];
	dict[10]->next = dict[11];
	dict[11]->next = dict[12];
	dict[12]->next = dict[13];
	dict[13]->next = dict[14];
	dict[14]->next = dict[15];
	dict[15]->next = dict[16];
	dict[16]->next = dict[17];
	dict[17]->next = dict[18];
	dict[18]->next = dict[19];
	dict[19]->next = dict[20];
	dict[20]->next = dict[21];
	dict[21]->next = dict[22];
	dict[22]->next = dict[23];
	dict[23]->next = dict[24];
	dict[24]->next = dict[25];
	dict[25]->next = dict[26];
	dict[26]->next = dict[27];
	dict[27]->next = dict[28];
	dict[28]->next = NULL;
	return (dict);
}

t_dict	**get_mag_dict(void)
{
	t_dict	**dict;

	dict = malloc(sizeof(void *) * 13);
	dict[0] = malloc(sizeof(t_dict));
	dict[0]->name = "thousand";
	dict[0]->value = 1;
	dict[1] = malloc(sizeof(t_dict));
	dict[1]->name = "million";
	dict[1]->value = 2;
	dict[2] = malloc(sizeof(t_dict));
	dict[2]->name = "billion";
	dict[2]->value = 3;
	dict[3] = malloc(sizeof(t_dict));
	dict[3]->name = "trillion";
	dict[3]->value = 4;
	dict[4] = malloc(sizeof(t_dict));
	dict[4]->name = "quadrillion";
	dict[4]->value = 5;
	dict[5] = malloc(sizeof(t_dict));
	dict[5]->name = "quintillion";
	dict[5]->value = 6;
	dict[6] = malloc(sizeof(t_dict));
	dict[6]->name = "sextillion";
	dict[6]->value = 7;
	dict[7] = malloc(sizeof(t_dict));
	dict[7]->name = "septillion";
	dict[7]->value = 8;
	dict[8] = malloc(sizeof(t_dict));
	dict[8]->name = "octillion";
	dict[8]->value = 9;
	dict[9] = malloc(sizeof(t_dict));
	dict[9]->name = "nonillion";
	dict[9]->value = 10;
	dict[10] = malloc(sizeof(t_dict));
	dict[10]->name = "decillion";
	dict[10]->value = 11;
	dict[11] = malloc(sizeof(t_dict));
	dict[11]->name = "undecillion";
	dict[11]->value = 12;
	dict[0]->next = dict[1];
	dict[1]->next = dict[2];
	dict[2]->next = dict[3];
	dict[3]->next = dict[4];
	dict[4]->next = dict[5];
	dict[5]->next = dict[6];
	dict[6]->next = dict[7];
	dict[7]->next = dict[8];
	dict[8]->next = dict[9];
	dict[9]->next = dict[10];
	dict[10]->next = dict[11];
	dict[11]->next = NULL;
	return (dict);
}
