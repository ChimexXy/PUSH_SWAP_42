/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:33:17 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/02 11:42:19 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strcmp(char *str1, char *str2)
{
	int i = 0;
	while(str1[i])
	{
		if(str1[i] != str2[i])
			return(1);
		i++;
	}
	return(0);
}

int is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}
int is_sign(char c, char c1)
{
	if((c == '-' && c1 != '-') || (c == '+' && c1 != '+'))
		return (1);
	return (0);
}

int ft_check(char *str)
{
	int i = 0;
	
	if(!str[i])
		return (0);
	while(str[i])
	{
		if(str[i] == 32 || is_sign(str[i], str[i + 1]))
			i++;
		else if(!is_digit(str[i]))
		{
			write(2, "Error\n", 6);
			return 0;
		}
		else
			i++;
	}
	return 1;
}

int *ft_return_num(char *str)
{
	int i;
	int cnt;
	int *tab;
	char **ret;

	i = 0;
	ret = ft_split(str);
	cnt = ft_count_word(str);
	while(i < cnt)
	{
		tab[i] = ft_atoi(ret[i]);
		i++;
	}
	return(tab);
}

int main(int ac, char *av[])
{
	int j = 1;
	char **s = ft_split(av[j]);
	while(j < ac)
	{
		if(ft_check(av[j]) == 1)
		{
			printf("%s", s[1]);
		}
		else
			return 0;
		j++;
	}

}
