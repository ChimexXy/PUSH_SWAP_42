/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:31:03 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/16 21:50:49 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_atoi(char *str)
{
	long i = 0;
	long res = 0;
	long sig = 1;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sig *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sig);
}
