/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:57:14 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/16 21:40:48 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list *node)
{
	t_list *head;

	head = node;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void sort_2_num(t_list **stack_a)
{
	if((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
}

void sort_3_num(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
	if((*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	if((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
		
}

void sort_4_num(t_list **stack_a, t_list *stack_b)
{
	if (is_sorted(*stack_a) == 1)
		return;
	push_b(stack_a, &stack_b);
	sort_3_num(stack_a);
	push_a(stack_a, &stack_b);
	if(((*stack_a)->content > (*stack_a)->next->content) 
		&& ((*stack_a)->content < (*stack_a)->next->next->content))
		swap_a(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->next->next->content)
		rotate_a(stack_a); 
	if (((*stack_a)->content > (*stack_a)->next->next->content) 
		&& ((*stack_a)->content < (*stack_a)->next->next->next->content))
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
}

void sort_5_num(t_list **list)
{
	t_list *tmp;

	if(is_sorted(*list) == 1)
		return;
	tmp = NULL;
	push_b(list, &tmp);
	sort_4_num(list);
	push_a(list, &tmp);
	if(((*list)->content > (*list)->next->content) && ((*list)->content < (*list)->next->next->content))
		swap_a(list);
	else if ((*list)->content > (*list)->next->next->next->next->content)
		rotate_a(list); 
	if (((*list)->content > (*list)->next->next->content)
		&& ((*list)->content < (*list)->next->next->next->content))
	{
		rotate_a(list);
		push_b(list, &tmp);
		push_b(list, &tmp);
		reverse_rotate_a(list);
		push_a(list, &tmp);
		push_a(list, &tmp);
	}
	if (((*list)->content > (*list)->next->next->next->content)
		&& ((*list)->content < (*list)->next->next->next->next->content))
	{
		reverse_rotate_a(list);
		swap_a(list);
		rotate_a(list);
		rotate_a(list);
	}
}
