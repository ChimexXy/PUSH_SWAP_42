/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:34:50 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/05 16:41:04 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *lst_new_node(int content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if(!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return(node);
}
