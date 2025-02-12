/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:57:14 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/12 09:19:38 by mozahnou         ###   ########.fr       */
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
	t_list *head;

	head = *list;
	if (head->content > head->next->content)
		swap_a(&head);
	if(head->next->content > head->next->next->content)
	{
		rotate_a(&head);
		swap_a(&head);
		reverse_rotate_a(&head);
	}
	if(head->content > head->next->content)
		swap_a(&head);
		
}

void sort_4_num(t_list **list)
{
	t_list *head;
	t_list *tmp;

	head = *list;
	if (is_sorted(head) == 1)
		return;
	tmp = NULL;
	push_b(&head, &tmp);
	sort_3_num(&head);
	push_a(&head, &tmp);
	if((head->content > head->next->content) && (head->content < head->next->next->content))
		swap_a(&head);
	if((head->content > head->next->content) && (head->content > head->next->next->content)
		&& (head->content > head->next->next->next->content))
		rotate_a(&head);
	if((head->content > head->next->content) 
		&& (head->content > head->next->next->content)
			&& (head->content < head->next->next->next->content))
	{
		reverse_rotate_a(&head);
		swap_a(&head);
		rotate_a(&head);
		rotate_a(&head);
	}
	// printList(head);
}
