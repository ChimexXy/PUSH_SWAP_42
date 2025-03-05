/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 05:57:14 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/05 03:15:16 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *node)
{
	t_list	*head;

	head = node;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_2_num(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
}

void	sort_3_num(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		rotate_a(stack_a);
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		reverse_rotate_a(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);

}



// {
// 	if ((*stack_a)->content > (*stack_a)->next->content)
// 		swap_a(stack_a);
// 	if ((*stack_a)->next->content > (*stack_a)->next->next->content)
// 	{
// 		rotate_a(stack_a);
// 		swap_a(stack_a);
// 		reverse_rotate_a(stack_a);
// 	}
// 	if ((*stack_a)->content > (*stack_a)->next->content)
// 		swap_a(stack_a);
// }

void	sort_4_num(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	push_b(stack_a, stack_b);
	sort_3_num(stack_a);
	push_a(stack_a, stack_b);
	if (((*stack_a)->content > (*stack_a)->next->content) 
		&& ((*stack_a)->content < (*stack_a)->next->next->content))
		swap_a(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->next->next->content)
		rotate_a(stack_a); 
	if (((*stack_a)->content > (*stack_a)->next->next->content) 
		&& ((*stack_a)->content < (*stack_a)->next->next->next->content))
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
}
