/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:02:04 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/10 23:07:40 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void lst_add_front(t_list **lst, t_list *new)
{
	if(!lst || !new)
		return; 
	new->next = *lst;
	*lst = new;
}