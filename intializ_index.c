/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intializ_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:30:10 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/05 23:57:37 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(t_list *list)
{
	int min;
	t_list *tmp;

	tmp = list;
	min = tmp->index;
	while(tmp->next)
	{
		if (tmp->next->index < min)
			min = tmp->next->index;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	*list_to_num(t_list *stack_a)
{
	t_list	*tmp;
	int		size;
	int		*tab;
	int		i;

	tmp = stack_a;
	size = lst_count(stack_a);
	tab = malloc(size * sizeof(int));
	i = 0;
	if (!tab)
		return (NULL);
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

int	*sort_tab(t_list *stack_a)
{
	int	*tab;
	int	i;
	int	j;
	int	size;

	i = 0;
	size = lst_count(stack_a);
	tab = list_to_num(stack_a);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}

void	intializ_index(t_list *stack_a)
{
	int		i;
	int		*tab;
	t_list	*tmp;
	int		size;

	size = lst_count(stack_a);
	tmp = stack_a;
	tab = sort_tab(stack_a);
	if (!tab)
		return ;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == tab[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(tab);
}
