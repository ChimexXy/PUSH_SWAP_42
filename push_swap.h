/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:18:54 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/12 01:16:37 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

// check_error
int		is_digit(char c);
int		is_sign(char c, char c1);
int		ft_check(char *str);
int		check_double(t_list *head);
int		ft_check_32_0(char **av);
int		check_av(char *s);

//func_lib
char	**ft_split(char *str);
char	*ft_substr(char *str, int start, int end);
int		ft_count_word(char *str);
long	ft_atoi(char *str, int *val);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_swap(int *a, int *b);

//linked list
void	lst_add_front(t_list **lst, t_list *new);
void	lst_add_back(t_list **lst, t_list *new);
t_list	*lst_new_node(int content);
void	lst_add_front(t_list **lst, t_list *new);
int		lst_count(t_list *list);
void	lst_free(t_list *list);

// utils_function
void	swap_fun(t_list **list);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	rotate_fun(t_list **list);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_fun(t_list **list);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

//push_swap + algo
void	push_swap(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
t_list	*ft_all_use(int ac, char **str);
t_list	*ft_ret_lst(char **ret);

// sort_num_2_3_4
void	sort_2_num(t_list **list);
void	sort_3_num(t_list **list);
void	sort_4_num(t_list **stack_a, t_list **stack_b);
void	sort_5_num(t_list **stack_a, t_list **stack_b);

//helper
void	intializ_index(t_list *stack_a);
int		*list_to_num(t_list *stack_a);
int		*sort_tab(t_list *stack_a);
int		is_sorted(t_list *node);
void	free_double_pointer(char **array);
int		get_min(t_list *list);

#endif