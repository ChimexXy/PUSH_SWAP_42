/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:50:14 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/17 02:49:09 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_list *stack)
{
    int max = lst_count(stack) - 1;
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    // printf("%d\n", bits);   
    return bits;
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    assign_indices(*stack_a); // Ensure indices are assigned properly
    int max_bits = get_max_bits(*stack_a);
    int i = 0;
    
    // Iterate through all bit positions
    while (i < max_bits)    
    {
        int size = lst_count(*stack_a);
        
        // Process each element based on the current bit position
        while (size > 0)
        {
            if ((((*stack_a)->index >> i) & 1) == 0)  // If the i-th bit of the index is 0
                push_b(stack_a, stack_b);
            else
                rotate_a(stack_a);  // Rotate if the i-th bit is 1

            size--;  // Decrease size after processing one element
        }

        // Move all elements back from B to A after each round
        while (*stack_b)
            push_a(stack_a, stack_b);
        
        i++;  // Move to the next bit position
    }
}
