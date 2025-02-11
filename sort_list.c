/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:57:14 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/11 08:12:55 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
