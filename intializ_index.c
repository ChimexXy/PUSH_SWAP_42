/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intializ_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:30:10 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/21 16:07:49 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

// int main()
// {
// 	int a = 12;
// 	int b = 59;
// 	ft_swap(&a, &b);
// 	printf("a ===== %d\n", a);
// }

int *list_to_num(t_list *stack_a)
{
	t_list *tmp = stack_a;
	int *tab = malloc((lst_count(stack_a)) * sizeof(int));
	int i = 0;

	while(tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int *sort_tab(t_list *stack_a)
{
	int *tab;
	int i;
	int j;

	i = 0;
	tab = list_to_num(stack_a);
	while(tab[i])
	{
		j = i + 1;
		while(tab[j])
		{
			if(tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}

void intializ_index(t_list **stack_a)
{
	int i;
	int j;
	int *tab;
	t_list *tmp;

	j = 0;
	tmp = *stack_a;
	tab = sort_tab(tmp);
	while(tmp)
	{
		i = 0;
		while(tab[i])
		{
			if(tmp->content == tab[i])
			{
				tmp->index = i;
				break;
			}
			i++;
				
		}
		tmp = tmp->next;
	}
}