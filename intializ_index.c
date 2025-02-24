/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intializ_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:30:10 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/24 01:08:20 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int *list_to_num(t_list *stack_a)
{
	t_list *tmp = stack_a;
	int size = lst_count(stack_a);
	int *tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL); // Handle allocation failure
	int i = 0;

	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return tab;
}

int *sort_tab(t_list *stack_a)
{
	int *tab;
	int i = 0;
	int j;
	int size = lst_count(stack_a);

	tab = list_to_num(stack_a);
	if (!tab)
		return (NULL);

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
	return tab;
}

void intializ_index(t_list *stack_a)
{
	int i;
	int *tab;
	t_list *tmp;
	int size = lst_count(stack_a);

	tab = sort_tab(stack_a);
	if (!tab)
		return;

	tmp = stack_a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == tab[i])
			{
				tmp->index = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(tab); // Free memory after use
}
