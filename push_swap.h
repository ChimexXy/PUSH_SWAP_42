/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:18:54 by mozahnou          #+#    #+#             */
/*   Updated: 2025/02/02 11:52:49 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list{
	int content;
	// int index;
	struct s_list *next;
}	t_list;

int ft_strcmp(char *str1, char *str2);
int is_digit(char c);
int is_sign(char c, char c1);
int ft_check(char *str);
char **ft_split(char *str);
char *ft_substr(char *str, int start, int end);
int ft_count_word(char *str);
int ft_atoi(char *str);


#endif