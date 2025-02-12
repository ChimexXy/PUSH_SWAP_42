/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:19:33 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/11 13:03:21 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_list **stack_a, t_list **stack_b)
{
	t_list *head;

	head = *stack_b;
	*stack_b = (*stack_b)->next;
	lst_add_front(stack_a, head);
	write(1, "pa\n", 3);
}

void push_b(t_list **stack_a, t_list **stack_b)
{
	t_list *head;

	head = *stack_a;
	*stack_a = (*stack_a)->next;
	lst_add_front(stack_b, head);
	write(1, "pb\n", 3);
}