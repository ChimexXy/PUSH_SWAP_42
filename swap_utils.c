/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:16:32 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/05 03:32:04 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_fun(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	// tmp = NULL;
	if ((*list) && (*list)->next)
	{
		tmp = (*list)->next;
		(*list)->next = tmp->next;
		tmp->next = (*list);
		(*list) = tmp;
	}
	else
		return ;
}

void	swap_a(t_list **stack_a)
{
	swap_fun(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	swap_fun(stack_b);
	write(1, "sb\n", 3);
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap_fun(stack_a);
	swap_fun(stack_b);
	write(1, "ss\n", 3);
}
