/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:02:43 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/03 02:41:29 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_pointer(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array); 
	array = NULL;
}

t_list	*ft_ret_lst(char *str)
{
	int		ind;
	long	data;
	char	**ret;
	t_list	*head;

	if (!str)
		return (NULL);
	ind = 0;
	data = 0;
	ret = ft_split(str);
	head = NULL;
	while (ret[ind])
	{
		data = ft_atoi(ret[ind]);
		if (data > INT_MAX || data < INT_MIN)
		{
			write(2, "Error\n", 6);
			free(ret);
			return (0);
		}
		lst_add_back(&head, lst_new_node(data));
		ind++;
	}
	free_double_pointer(ret);
	return (head);
}
