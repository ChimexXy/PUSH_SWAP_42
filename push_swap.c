/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:33:17 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/04 02:51:15 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_free(t_list *list)
{
	t_list	*tmp;

	if (list == NULL)
	{
		free(list);
		return ;
	}
	while (list) 
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_list	*ft_all_use(int ac, char **str)
{
	int		i;
	char	*s;
	t_list	*head;

	i = 1;
	s = malloc(1);
	while (i < ac)
	{
		s = ft_strjoin(s, str[i]);
		i++;
	}
	head = ft_ret_lst(s);
	if (!ft_check(s) || !check_double(head))
	{
		free(s);
		lst_free(head);
		return (0);
	}
	free(s);
	return (head);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	if (ac < 1)
		return (0);
	stack_a = ft_all_use(ac, av);
	stack_b = NULL;
	if (stack_a == 0)
	{
		lst_free(stack_a);
		exit (1);
	}
	push_swap(&stack_a, &stack_b);
	lst_free(stack_a);
}
