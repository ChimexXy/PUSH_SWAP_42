/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:28:12 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/05 23:58:10 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = lst_count(*stack_a);
	intializ_index(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (count == 2)
		sort_2_num(stack_a);
	if (count == 3)
		sort_3_num(stack_a);
	if (count == 4)
		sort_4_num(stack_a, stack_b);
	if (count == 5)
		sort_5_num(stack_a, stack_b);
	if (count > 5)
		radix_sort(stack_a, stack_b);
	printList(*stack_a);
}

// void	printList(t_list *head)
// {
//     t_list *temp = head; 

// 	if(!head)
// 		return;
//     while (temp != NULL) 
// 	{  
// 		printf("content-> %d ,index -> %d \n", temp->content, temp->index);
//         temp = temp->next; 
//     }
// }