/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_newnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:34:50 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/02 14:37:23 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *new_node(int data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node->content = data;
	node->next = NULL;
	return(node);
}
