/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:50:14 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/24 08:26:09 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_list *stack)
{
    int max = lst_count(stack);
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    int max_bits;
    int i;
	int size;

	max_bits = get_max_bits(*stack_a);
	i = 0;
    while (i < max_bits)    
    {
        size = lst_count(*stack_a);
        while (size > 0)
        {
            if (((((*stack_a)->index >> i) & 1) == 0) && ((is_sorted(*stack_a)) == 0))
                push_b(stack_a, stack_b);
            else if ((((*stack_a)->index >> i) & 1) == 1)
                rotate_a(stack_a);
            size--;
        }
        while (*stack_b)
            push_a(stack_a, stack_b);
        
        i++;
    }
}
