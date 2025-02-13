/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:57:14 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/12 20:49:53 by mozahnou         ###   ########.fr       */
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

void sort_2_num(t_list **list)
{
	t_list *head;

	head = *list;
	if(head->content > head->next->content)
		swap_a(&head);
}

void sort_3_num(t_list **list)
{
	if ((*list)->content > (*list)->next->content)
		swap_a(list);
	if((*list)->next->content > (*list)->next->next->content)
	{
		rotate_a(list);
		swap_a(list);
		reverse_rotate_a(list);
	}
	if((*list)->content > (*list)->next->content)
		swap_a(list);
		
}

void sort_4_num(t_list **list)
{
	t_list *tmp;

	if (is_sorted(*list) == 1)
		return;
	tmp = NULL;
	push_b(list, &tmp);
	sort_3_num(list);
	push_a(list, &tmp);
	if(((*list)->content > (*list)->next->content) && ((*list)->content < (*list)->next->next->content))
		swap_a(list);
	if ((*list)->content > (*list)->next->next->next->content)
		rotate_a(list); 
	if (((*list)->content > (*list)->next->next->content) 
		&& ((*list)->content < (*list)->next->next->next->content))
	{
		reverse_rotate_a(list);
		swap_a(list);
		rotate_a(list);
		rotate_a(list); 
	}
	// printList((*list));
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
