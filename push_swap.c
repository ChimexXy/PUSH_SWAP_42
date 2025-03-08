/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:33:17 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/08 17:37:55 by mozahnou         ###   ########.fr       */
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
	char	**ptr;
	t_list	*head;

	i = 1;
	s = malloc(1);
	while (i < ac)
	{
		s = ft_strjoin(s, str[i]);
		i++;
	}
	ptr = ft_split(s);
	head = ft_ret_lst(ptr);
	if (!head || !ft_check(s) || !check_double(head))
	{
		free(s);
		lst_free(head);
		exit (1);
	}
	free(s);
	return (head);
}

int	check_av(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (0);
	return (1);
}

int	ft_check_32_0(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_av(av[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac <= 1)
		return (0);
	if (!ft_check_32_0(av))
		exit (1);
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
