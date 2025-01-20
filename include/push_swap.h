/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:28:17 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/20 13:43:05 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR 1
# define SUCCESS 0

typedef struct s_node
{
	int				pos;
	int				min;
}					t_node;

typedef struct s_stack
{
	t_node			node;
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// init the list
void				rot_lstadd_back(t_stack **stack, t_stack *new_node);
void				fill_the_list(int argv, t_stack **stack);
t_stack				*stack_init(int content);

// push_swap.c
int					main(int argc, char **argv);

// sort_the_list
void				sort_the_list(t_stack **stack_a, t_stack **stack_b);
void				search_best_instruct(t_stack **stack);
void				sort_three(t_stack **stack_a);
void				search_smallest(t_stack **stack);

// instructions
void				push_into_stack(t_stack **src, t_stack **dst, char c);
void				ft_swap(t_stack **stack, char c);
void				rotate_next(t_stack **stack, char c);
void				rotate_prev(t_stack **stack, char c);

// utils
void				print_error(void);
void				rm_node(t_stack **stack);
int					size_of_list(t_stack **stack);
void				ft_print_list(t_stack **stack);

#endif