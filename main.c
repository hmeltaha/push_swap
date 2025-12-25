/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:42:29 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/04/23 16:25:58 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_errors(int argc, char **argv, t_node **stack_a)
{
	if (argc < 2)
		return (0);
	if (!is_valid_input(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	*stack_a = fill_stack(argc, argv);
	if (!*stack_a || has_duplicates(*stack_a))
	{
		free_stack(stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(*stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	return (-1);
}

void	choose_sort(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
	{
		index_stack((*a));
		radix_sort(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		result;

	result = handle_errors(argc, argv, &stack_a);
	if (result != -1)
		return (result);
	stack_b = NULL;
	choose_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
