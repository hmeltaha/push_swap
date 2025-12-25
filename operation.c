/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:44:48 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/04/23 12:47:34 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	int	tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_node **a)
{
	t_node	*tmp;
	t_node	*start;

	if (!a || !(*a) || !(*a)->next)
		return ;
	start = *a;
	tmp = *a;
	*a = (*a)->next;
	while (start->next)
		start = start->next;
	start->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_node **a)
{
	t_node	*tmp;
	t_node	*start;

	if (!a || !(*a) || !(*a)->next)
		return ;
	start = *a;
	while (start->next->next)
		start = start->next;
	tmp = start->next;
	tmp->next = *a;
	*a = tmp;
	start->next = NULL;
	write(1, "rra\n", 4);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*start_b;

	if (!b || !(*b))
		return ;
	start_b = *b;
	*b = (*b)->next;
	start_b->next = *a;
	*a = start_b;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*start_a;

	if (!a || !(*a))
		return ;
	start_a = *a;
	*a = (*a)->next;
	start_a->next = *b;
	*b = start_a;
	write(1, "pb\n", 3);
}
