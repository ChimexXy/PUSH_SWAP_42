/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:01:08 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/06 12:12:58 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	m;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	m = 0;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 3);
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[m++] = s1[i++];
	ptr[m] = ' ';
	m++;
	while (s2[j])
		ptr[m++] = s2[j++];
	ptr[m] = ' ';
	ptr[m + 1] = '\0';
	return (ptr);
}
