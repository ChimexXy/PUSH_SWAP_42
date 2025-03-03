/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:02:26 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/03 00:47:52 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_word(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == 32)
		i++;
	while (str[i])
	{
		if (str[i] != 32 && str[i])
			j++;
		while (str[i] != 32 && str[i])
			i++;
		while (str[i] == 32 && str[i])
			i++;
	}
	return (j);
}

char	*ft_substr(char *str, int start, int end)
{
	int		j;
	char	*ret;

	j = 0;
	ret = malloc((end - start) + 1);
	while (start < end)
	{
		ret[j] = str[start];
		start++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	**ft_split(char *str)
{
	int		i;
	int		cnt;
	int		start;
	int		len_word;
	char	**ret;

	i = 0;
	cnt = 0;
	len_word = ft_count_word(str);
	ret = malloc((len_word + 1) * sizeof(char *));
	while (cnt < len_word)
	{
		while (str[i] == 32)
			i++;
		start = i;
		while (str[i] != 32)
			i++;
		ret[cnt] = ft_substr(str, start, i);
		cnt++;
	}
	ret[cnt] = NULL;
	return (ret);
}
