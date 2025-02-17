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

// int get_min_value(t_list *stack_a)
// {
//     int min = stack_a->content;
//     while (stack_a)
//     {
//         if (stack_a->content < min)
//             min = stack_a->content;
//         stack_a = stack_a->next;
//     }
//     return min;
// }

// int get_max_bits(t_list **stack_a)
// {
//     int max = 0;
//     t_list *temp = *stack_a;
//     while (temp)
//     {
//         if (temp->content > max)
//             max = temp->content;
//         temp = temp->next;
//     }
//     int bits = 0;
//     while ((max >> bits) != 0)
//         bits++;
//     return bits;
// }

// // Radix Sort Algorithm
// void radix_sort(t_list **stack_a, t_list *stack_b)
// {
//     int max_bits = get_max_bits(stack_a);
//     int i = 0;
//     while (i < max_bits)
//     {
//         int j = 0;
//         int size = lst_count(*stack_a);
//         while (j < size)
//         {
//             if ((((*stack_a)->content >> i) & 1) == 0)
//                 push_b(stack_a, &stack_b);
//             else
//                 rotate_a(stack_a);
//             j++;
//         }
//         while (stack_b)
//             push_a(stack_a, &stack_b);
//         i++;
//     }
// }

// void radix_sort(t_list **stack_a, t_list *stack_b)
// {
//     int min_value = get_min_value(*stack_a);
//     t_list *temp = *stack_a;
//     while (temp)
//     {
//         temp->content -= min_value; // Normalize to make all values non-negative
//         temp = temp->next;
//     }
    
//     int max_bits = get_max_bits(stack_a);
//     int i = 0;
//     while (i < max_bits)
//     {
//         int j = 0;
//         int size = lst_count(*stack_a);
//         while (j < size)
//         {
//             if ((((*stack_a)->content >> i) & 1) == 0)
//                 push_b(stack_a, &stack_b);
//             else
//                 rotate_a(stack_a);
//             j++;
//         }
//         while (stack_b)
//             push_a(stack_a, &stack_b);
//         i++;
//     }
    
//     temp = *stack_a;
//     while (temp)
//     {
//         temp->content += min_value;
//         temp = temp->next;
//     }
// }


// void get_min_max_value(t_list *stack, int *min, int *max)
// {
//     *min = stack->content;
//     *max = stack->content;
//     while (stack)
//     {
//         if (stack->content < *min)
//             *min = stack->content;
//         if (stack->content > *max)
//             *max = stack->content;
//         stack = stack->next;
//     }
// }

// // Get the maximum number of bits required
// int get_max_bits(t_list **stack)
// {
//     int min, max;
//     get_min_max_value(*stack, &min, &max);
//     int max_abs = (min < 0 && -min > max) ? -min : max;
//     int bits = 0;
//     while ((max_abs >> bits) != 0)
//         bits++;
//     return bits;
// }

// // Radix Sort Algorithm (Handles Negative Numbers)
// void radix_sort(t_list **stack_a, t_list *stack_b)
// {
//     int min_value, max_value;
//     get_min_max_value(*stack_a, &min_value, &max_value);
//     t_list *temp = *stack_a;
//     while (temp)
//     {
//         temp->content -= min_value; // Normalize to make all values non-negative
//         temp = temp->next;
//     }
    
//     int max_bits = get_max_bits(stack_a);
//     int i = 0;
//     while (i < max_bits)
//     {
//         int j = 0;
//         int size = lst_count(*stack_a);
//         while (j < size)
//         {
//             if ((((*stack_a)->content >> i) & 1) == 0)
//                 push_b(stack_a, &stack_b);
//             else
//                 rotate_a(stack_a);
//             j++;
//         }
//         while (stack_b)
//             push_a(stack_a, &stack_b);
//         i++;
//     }
    
//     // Restore original values by adding back the offset
//     temp = *stack_a;
//     while (temp)
//     {
//         temp->content += min_value;
//         temp = temp->next;
//     }
// }


int get_max_bits(t_list *stack)
{
    int max = lst_count(stack) - 1;
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

// Radix Sort Algorithm using indices
void radix_sort(t_list **stack_a, t_list *stack_b)
{
    assign_indices(*stack_a);
    int max_bits = get_max_bits(*stack_a);
    int i = 0;
    while (i < max_bits)
    {
        int j = 0;
        int size = lst_count(*stack_a);
        while (j < size)
        {
            if ((((*stack_a)->index >> i) & 1) == 0)
                push_b(stack_a, &stack_b);
            else
                rotate_a(stack_a);
            j++;
        }
        while (stack_b)
            push_a(stack_a, &stack_b);
        i++;
    }
}

// void radix_sort(t_list **stack_a, t_list *stack_b)
// {
//     assign_indices(*stack_a);
//     int max_bits = get_max_bits(*stack_a);
//     int i = 0;
//     while (i < max_bits)
//     {
//         int j = 0;
//         int size = lst_count(*stack_a);
//         while (j < size)
//         {
//             if ((((*stack_a)->index >> i) & 1) == 0)
//                 push_b(stack_a, &stack_b);
//             else
//                 rotate_a(stack_a);
//             j++;
//         }
//         while (stack_b)
//             push_a(stack_a, &stack_b);
        
//         // Reverse rotate optimization
//         if (i < max_bits - 1 && lst_count(*stack_a) > 10)
//             reverse_rotate_a(stack_a);
        
//         i++;
//     }
// }
