/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:28:12 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/12 09:19:44 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void take_list(t_list **list)
{
	t_list *stack_a;
	int count;

	stack_a = *list;
	count = lst_count(stack_a);
	if(count == 2)
		sort_2_num(&stack_a);
	if(count == 3)
		sort_3_num(&stack_a);
	if(count == 4)
		sort_4_num(&stack_a);
	// if(count == 5)
	// 	sort_5_num(&stack_a);
	printList(stack_a);
}
