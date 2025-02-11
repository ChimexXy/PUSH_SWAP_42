/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:18:54 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/11 06:13:55 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list{
	int content;
	// int index;
	struct s_list *next;
}	t_list;

int is_digit(char c);
int is_sign(char c, char c1);
int ft_check(char *str);
int check_double(t_list *head);
char **ft_split(char *str);
char *ft_substr(char *str, int start, int end);
int ft_count_word(char *str);
long ft_atoi(char *str);
void lst_add_front(t_list **lst, t_list *new);
void	lst_add_back(t_list **lst, t_list *new);
t_list *lst_new_node(int content);
t_list *ft_ret_lst(char *str);
int ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void printList(t_list *head);
void swap_fun(t_list **list);
void swap_a(t_list **stack_a);
void swap_b(t_list **stack_b);
void swap_a_b(t_list **stack_a ,t_list **stack_b);
void rotate_fun(t_list **list);
void rotate_a(t_list **stack_a);
void rotate_b(t_list **stack_b);
void rotate_a_b(t_list **stack_a, t_list **stack_b);
void lst_add_front(t_list **lst, t_list *new);
void reverse_rotate_fun(t_list **list);
void reverse_rotate_a(t_list **stack_a);
void reverse_rotate_b(t_list **stack_b);
void reverse_rotate_a_b(t_list **stack_a ,t_list **stack_b);
void take_list(t_list **stack_a);
void push_a(t_list **stack_a, t_list **stack_b);
void push_b(t_list **stack_a, t_list **stack_b);
int lst_count(t_list *list);
void sort_2_num(t_list **list);

#endif