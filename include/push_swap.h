/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:28:17 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/14 16:24:52 by vicperri         ###   ########lyon.fr   */
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

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// push_swap.c
int					main(int argc, char **argv);

// sort_the_list
void				sort_the_list(t_stack **stack);
void				update_stack_a(int min, t_stack **stack_a);

// utils
void				print_error(void);
void				rot_lstadd_back(t_stack *stack, t_stack *new);
void				fill_the_list(int argv, t_stack **stack);
t_stack				*stack_init(int content);

#endif