/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:02:43 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/11 23:53:23 by mozahnou         ###   ########.fr       */
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

int check_ret(char **ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(ret[j])
	{
		i = 0;
		while(ret[j][i])
		{
			if ((ret[j][i] == '-' && ret[j][i + 1] == '\0') 
				|| (ret[j][i] == '+' && ret[j][i + 1] == '\0'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

t_list	*ft_ret_lst(char **ret)
{
	int		ind;
	long	data;
	int		val;
	t_list	*head;

	val = 0;
	ind = 0;
	data = 0;
	head = NULL;
	
	while (ret[ind])
	{
		data = ft_atoi(ret[ind], &val);
		if (val == 1 || check_ret(ret) == 0)
		{
			write(2, "Error\n", 6);
			free_double_pointer(ret);
			lst_free(head);
			return (NULL);
		}
		lst_add_back(&head, lst_new_node(data));
		ind++;
	}
	free_double_pointer(ret);
	return (head);
}
