/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:40:13 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/04/23 16:42:25 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *a)
{
	t_node	*min;

	if (!a)
		return (NULL);
	if (!a->next)
		return (a);
	min = a;
	while (a)
	{
		if (min->data > a->data)
			min = a;
		a = a->next;
	}
	return (min);
}

t_node	*fill_stack(int argc, char **argv)
{
	int		i;
	long	value;
	t_node	*stack;
	t_node	*new;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
		{
			free_stack(&stack);
			return (NULL);
		}
		new = create_node(value);
		if (!new)
		{
			free_stack(&stack);
			return (NULL);
		}
		add_to_stack(&stack, new);
		i++;
	}
	return (stack);
}

void	sort_3(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (second < first && first < third)
		sa(a);
	else if (third < first && first < second)
		rra(a);
	else if (second < third && third < first)
		ra(a);
	else if (first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (third < second && second < first)
	{
		ra(a);
		sa(a);
	}
}

void	sort_4(t_node **a, t_node **b)
{
	t_node	*min;

	min = find_min(*a);
	while ((*a) != min)
		ra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_node **a, t_node **b)
{
	t_node	*min;
	int		pos;
	int		size;

	size = stack_size(*a);
	while (size > 3)
	{
		min = find_min(*a);
		pos = get_index(*a, min);
		if (pos <= size / 2)
			while ((*a) != min)
				ra(a);
		else
			while ((*a) != min)
				rra(a);
		pb(a, b);
		size--;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
