/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 12:36:48 by gleger            #+#    #+#             */
/*   Updated: 2014/05/11 10:46:50 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>



void ft_putchar(const char c)
{
	write(1,&c,1);
}

int ft_strlen (const char *src)
{
	int loop = 0;
	while (src[loop])
		loop++;
	return (loop);
}

void ft_putstr(const char *str)
{
	int size = ft_strlen(str);
	int loop = -1;
	char end_line = '\n';

	while (++loop < size)
		ft_putchar(str[loop]);
	ft_putchar(end_line);
}

int ft_atoi(char c)
{
	int value=0;

	return (value = c - '0');
}
char ft_itoa(int i)
{
	char value;

	return (value = i + '0');
}

char	*ft_add(char *arg1, char *arg2, int max, int neg)
{

	int size1 = ft_strlen(arg1);
	int size2 = ft_strlen(arg2);
	int retenue = 0;
	char *result;

	result = malloc(size2*sizeof(char)+1);
	max = size2;
	if (result == NULL)
		exit(-1);
	int loop = max;
	while (loop != neg)
	{
		result[loop-1] = ft_itoa(ft_atoi(arg2[size2-1])+ft_atoi(arg1[size1-1]));
		loop--;
		size2--;
		if (size1-2 < neg)
			arg1[neg]='0';
		else
			size1--;
	}
	return (result);
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		char *arg1 = argv[1];
		char *arg2 = argv[2];
		char *result;
		bool neg1;
		bool neg2;
    int neg = 2;

		ft_putstr(arg1);
		ft_putstr(arg2);
		int size1 = ft_strlen(arg1);
		int size2 = ft_strlen(arg2);
		if (arg1[0]=='-')
			neg1=true;
		else
			neg1=false;
		if (arg2[0]=='-')
			neg2=true;
		else
			neg2=false;
		if ((!neg1 && !neg2) || (neg1 && neg2))
		{
			int retenue = 0;
			int max = 0;
      if (neg1)
        neg=1;
      else
        neg=0;
			if (size2 > size1)
			{
				result = ft_add(arg1, arg2, size2, neg);
			}
			else
			{
				result = ft_add(arg2, arg1, size1, neg);
			}
		}
		else
		{

		}
    if (neg == 1)
      ft_putchar('-');
		ft_putstr(result);
	}
	return (0);
}
