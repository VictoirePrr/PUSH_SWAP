/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:28:17 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/28 15:27:40 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR 1
# define SUCCESS 0
# define QUAD 0.000003
# define MIN_CHUNK 18

typedef struct s_data
{
	int				min_pos;
	int				min;
	int				index;
	float			chunk_size;
}					t_data;

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// init the list
void				rot_lstadd_back(t_stack **stack, t_stack *new_node);
void				rot_lstadd_front(t_stack **stack, t_stack *new_node);
void				fill_the_list(int argv, t_stack **stack);
t_stack				*stack_init(int content);

// push_swap.c
int					main(int argc, char **argv);

// sort_the_small_list
void				sort_the_small_list(t_stack **stack_a, t_stack **stack_b);
void				search_best_instruct(t_stack **stack, t_data *data);
void				sort_three(t_stack **stack_a);
void				search_smallest_small_list(t_stack **stack, t_data *data);

// instructions
void				push_into_stack(t_stack **src, t_stack **dst, char c);
void				ft_swap(t_stack **stack, char c);
void				rotate_next(t_stack **stack, char c);
void				rotate_prev(t_stack **stack, char c);

// utils
void				print_error(void);
void				rm_node(t_stack **stack);
void				ft_print_list(t_stack **stack);
int					size_of_list(t_stack **stack);

// big_list_utils
void				search_sort_index(t_stack **stack, t_data *data);
void				set_index(t_stack **stack);
void				compute_chunks(t_stack **stack, t_data *data);
int					check_if_node_processed(t_stack **stack);
void				search_smallest_big_list(t_stack **stack, t_data *data);

// sort_the_big_list
void				sort_the_big_list(t_stack **stack_a, t_stack **stack_b);
void				korean_algo(t_stack **stack, t_stack **stack_b,
						t_data *data);
void				push_b_in_a_korean_way(t_stack **stack_a, t_stack **stack_b,
						int size_a);
void				sort_stack_a_korean_way(t_stack **stack_a);
#endif