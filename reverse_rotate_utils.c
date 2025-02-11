/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:54:18 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/11 06:11:12 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_fun(t_list **list)
{
	t_list *last;
	t_list *tmp;

	last = *list;
	while(last->next != NULL)
	{
		if(last->next->next == NULL)
		{
			tmp = last->next;
			last->next = NULL;
			lst_add_front(list , tmp);
			return;
		}
		else
			last = last->next;
	}
}

void reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate_fun(stack_a);
	write(1, "rra\n", 4);
}

void reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate_fun(stack_b);
	write(1, "rrb\n", 4);
}

void reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_fun(stack_a);
	reverse_rotate_fun(stack_b);
	write(1, "rrr\n", 4);
}