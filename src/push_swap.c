/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:18 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/29 18:26:50 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_args(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
}

int	split_and_list_argv(int argc, char **argv, t_stack **stack)
{
	int		j;
	int		i;
	int		num;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			return (ERROR);
		j = 0;
		while (args[j])
		{
			if (ft_isdigit(args[j]) == ERROR)
				return (print_error(), ERROR);
			num = ft_atoi(args[j]);
			if (fill_and_check_the_list(num, stack) == ERROR)
				return (ERROR);
			j++;
		}
		ft_free_args(args);
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	int i;
	t_stack *stack_a;
	// t_stack *stack_b;

	i = 1;
	stack_a = NULL; // init the stack before the first node
	// stack_b = NULL; // init the stack before the first node
	if (split_and_list_argv(argc, argv, &stack_a) == ERROR)
		return (ERROR);
	else
		printf("SUCCESS");
	// if (argc > 2)
	// {
	// while (i < argc)
	// {
	// 	fill_the_list(ft_atoi(argv[i]));
	// 	i++;
	// }
	// if (size_of_list(&stack_a) <= 12)
	// 	sort_the_small_list(&stack_a, &stack_b);
	// else
	// 	sort_the_big_list(&stack_a, &stack_b);
	// }
	// else
	// 	print_error();
	return (SUCCESS);
}