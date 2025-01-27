/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:18 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/24 16:06:56 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// make chuncks that you divide by 11 or 5 depending on the number of numbers
// then inside those chunks you put the numbers between 0 to 45 for ex then 46 to 90 and so on.
// then you put it back sorted to the stack a using the best rule given.

int	main(int argc, char **argv)
{
	int i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL; // init the stack before the first node
	if (argc > 2)
	{
		while (i < argc)
		{
			fill_the_list(atoi(argv[i]), &stack_a);
			i++;
		}
		if (size_of_list(&stack_a) <= 12)
			sort_the_small_list(&stack_a, &stack_b);
		else
			sort_the_big_list(&stack_a, &stack_b);
		// ft_print_list(&stack_a);
		// printf("sorted !\n");
	}
	else
		print_error();
	return (0);
}