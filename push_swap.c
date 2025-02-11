/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:33:17 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/11 05:11:59 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printList(t_list *head) 
{
    t_list *temp = head; 

	if(!head)
		return;
    while (temp != NULL) 
	{  
		printf("-> %d \n", temp->content);
        temp = temp->next; 
    }
}

t_list *ft_all_use(int ac,char **str)
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
		return 0;
	return (head);
		
}

int main(int ac, char *av[])
{
	t_list *stack_a;
	// t_list *stack_b;
	
	stack_a = ft_all_use(ac, av);
	// stack_b = NULL;
	if(stack_a == 0)
	{
		free(stack_a);
		exit (1);
	}
	swap_a(&stack_a );
	printList(stack_a);
	// stack_a(head);

}
