/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:40:37 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/03 00:51:17 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_count(t_list *list)
{
	t_list	*head;
	int		i;

	head = list;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
