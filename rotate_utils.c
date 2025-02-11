/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:21:16 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/11 02:32:12 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_list **stack_a)
{
    t_list *tmp;
    t_list *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    last = *stack_a;
    
    while (last->next != NULL)
        last = last->next;

    last->next = tmp;
    tmp->next = NULL;
}

void rotate_b(t_list **stack_b)
{
    t_list *tmp;
    t_list *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;

    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    last = *stack_b;
    
    while (last->next != NULL)
        last = last->next;

    last->next = tmp;
    tmp->next = NULL;
}

void rotate_a_b(t_list **stack_a, t_list **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}
