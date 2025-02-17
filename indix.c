/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:34:06 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/17 02:36:04 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_indices(t_list *stack)
{
    int size = lst_count(stack);
    int *array = malloc(sizeof(int) * size);
    t_list *temp = stack;
    for (int i = 0; i < size; i++)
    {
        array[i] = temp->content;
        temp = temp->next;
    }
    
    // Sort the array
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int swap = array[i];
                array[i] = array[j];
                array[j] = swap;
            }
        }
    }
    
    // Assign index
    temp = stack;
    while (temp)
    {
        for (int i = 0; i < size; i++)
        {
            if (temp->content == array[i])
            {
                temp->index = i;
                break;
            }
        }
        temp = temp->next;
    }
    free(array);
}
