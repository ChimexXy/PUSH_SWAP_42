/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:21:16 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/11 03:07:19 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_list **stack_a)
{
    t_list *tmp;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    tmp = *stack_a;
    tmp->next = NULL;
    *stack_a = (*stack_a)->next;
	lst_add_back(stack_a, tmp);
}

void rotate_b(t_list **stack_b)
{
    t_list *tmp;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    tmp = *stack_b;
    tmp->next = NULL;
    *stack_b = (*stack_b)->next;
	lst_add_back(stack_b, tmp);
}

void rotate_a_b(t_list **stack_a, t_list **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}
