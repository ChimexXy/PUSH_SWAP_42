/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:33:17 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/22 10:23:05 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void lst_free(t_list *list)
{
	if(list == NULL)
	{
		free(list);
		return;
	}
	t_list *tmp;

    while (list) 
	{
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void printList(t_list *head) 
{
    t_list *temp = head; 

	if(!head)
		return;
    while (temp != NULL) 
	{  
		printf("content-> %d ,index -> %d \n", temp->content, temp->index);
        temp = temp->next; 
    }
}

t_list *ft_all_use(int ac, char **str)
{
	int i;
	char *s;
	t_list *head;

	i = 1;
	s = "";
	while(i < ac)
	{
		s = ft_strjoin(s, str[i]);
		i++;
	}
	head = ft_ret_lst(s);
	if(!ft_check(s) || !check_double(head))
	{
		free(s);
		lst_free(head);
		return 0;
	}
	free(s);
	return (head);
		
}

int main(int ac, char *av[])
{
	t_list *stack_a;
	
	stack_a = ft_all_use(ac, av);
	if(stack_a == 0)
	{
		lst_free(stack_a);
		exit (1);
	}
	take_list(&stack_a);
	lst_free(stack_a);
	// system("leaks -g a.out");
}
