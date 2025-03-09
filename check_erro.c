/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:59:34 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/05 02:32:22 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_sign(char c, char c1)
{
	if ((c == '-' && c1 != '-') || (c == '+' && c1 != '+')
		|| (c == '+' && c1 != '-') || (c == '-' && c1 != '+'))
		return (1);
	return (0);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if ((str[i] == '+' && str[i + 1] == '-') 
			|| (str[i] == '-' && str[i + 1] == '+'))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (str[i] == 32 || is_sign(str[i], str[i + 1]))
			i++;
		else if (!is_digit(str[i]) || (is_digit(str[i]) && str[i + 1] == '-')
			|| (is_digit(str[i]) && str[i + 1] == '+'))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else
			i++;
	}
	return (1);
}

int	check_double(t_list *head)
{
	t_list	*node;

	while (head)
	{
		node = head->next;
		while (node)
		{
			if (head->content == node->content)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			node = node->next;
		}
		head = head->next;
	}
	lst_free(node);
	return (1);
}
