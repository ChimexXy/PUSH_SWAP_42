/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:28:12 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/12 13:50:09 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void take_list(t_list **list)
{
	int count;

	count = lst_count(*list);
	if(count == 2)
		sort_2_num(list);
	if(count == 3)
		sort_3_num(list);
	if(count == 4)
		sort_4_num(list);
	if(count == 5)
		sort_5_num(list);
	printList(*list);
	// if(count == 5)
	// 	sort_5_num(&stack_a);
}
