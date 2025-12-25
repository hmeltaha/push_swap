/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:50:48 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/04/23 14:02:05 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1- get max num in stack
2- get max bit of the max-num
10011 >> 1  = 01001
10011 >> 2  = 00100
10011 >> 3  = 00010
10011 >> 4  = 00001
10011 >> 5  = 00000
3-
*/
#include "push_swap.h"

void	index_stack(t_node *stack)
{
	t_node	*cur1;
	t_node	*cur2;
	int		ind;

	cur1 = stack;
	while (cur1)
	{
		cur2 = stack;
		ind = 1;
		while (cur2)
		{
			if (cur2->data < cur1->data)
				ind++;
			cur2 = cur2->next;
		}
		cur1->index = ind;
		cur1 = cur1->next;
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	size;

	i = 0;
	while (i < 32)
	{
		size = stack_size(*a);
		while (size--)
		{
			if (((*a)->index >> i & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		i++;
		while (*b)
			pa(a, b);
		if (is_sorted(*a))
			break ;
	}
}
