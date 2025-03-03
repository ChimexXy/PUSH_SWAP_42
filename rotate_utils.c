/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:21:16 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/03 02:44:35 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_fun(t_list **list)
{
	t_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	lst_add_back(list, tmp);
}

void	rotate_a(t_list **stack_a)
{
	rotate_fun(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	rotate_fun(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rotate_fun(stack_a);
	rotate_fun(stack_b);
	write(1, "rr\n", 3);
}
