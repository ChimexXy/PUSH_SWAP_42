/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:18:54 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/17 02:34:57 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct s_list{
	int content;
	int index;
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
void sort_3_num(t_list **list);
void sort_4_num(t_list **list, t_list **stack_b);
void sort_5_num(t_list **list, t_list **stack_b);
void radix_sort(t_list **stack_a, t_list **stack_b);
void assign_indices(t_list *stack);;

/////////////////////////////

// void move_to_b(t_list **a, t_list **b);
// int find_best_position_in_a(t_list *a, int number);
// int find_best_position_in_b(t_list *b, int number);
// // int find_index(t_list *stack, int number);
// void rotate_to_top(t_list **stack, int index);
// int find_min_index(t_list *a);
// void move_back_to_a(t_list **a, t_list **b);
// int calculate_moves(t_list *a, t_list *b, int index);
// int find_best_move(t_list *a, t_list *b);
// t_list *get_nth(t_list *stack, int n);

//////////////////////////////////////////


// // Chunk Sorting Functions
// int	ft_sqrt(int nb);
// void push_chunks_to_b(t_list **a, t_list **b);
// // void push_chunks_to_b(t_list **a, t_list **b);
// void move_back_to_a(t_list **a, t_list **b);
// void chunk_sort(t_list **a, t_list **b);
// int *lst_to_array(t_list *stack, int size);
// // int find_median(t_list *stack, int size);
// void quicksort(int *arr, int low, int high);
// int partition(int *arr, int low, int high);
// void swap(int *a, int *b);
// void rotate_to_top(t_list **stack, int index);
// int find_best_position_in_a(t_list *a, int number);
// int find_min_index(t_list *a);


#endif