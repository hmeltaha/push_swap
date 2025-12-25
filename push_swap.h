/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeltaha <hmeltaha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:32:09 by hmeltaha          #+#    #+#             */
/*   Updated: 2025/04/23 16:42:17 by hmeltaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}					t_node;

t_node				*fill_stack(int argc, char **argv);
t_node				*create_node(int value);
void				add_to_stack(t_node **stack, t_node *new);
void				free_stack(t_node **stack);
void				push(int a);
void				ft_lstsize(t_node **lst);
void				choose_sort(t_node **a, t_node **b);
void				index_stack(t_node *stack);
void				sort_3(t_node **a);
void				sort_4(t_node **a, t_node **b);
void				sort_5(t_node **a, t_node **b);
void				sa(t_node **a);
void				ra(t_node **a);
void				rra(t_node **a);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				radix_sort(t_node **a, t_node **b);
long				ft_atoi(const char *nptr);
int					get_index(t_node *a, t_node *node);
int					handle_errors(int argc, char **argv, t_node **stack_a);
int					is_valid_input(char **argv);
int					has_duplicates(t_node *stack);
int					is_sorted(t_node *stack);
int					stack_size(t_node *stack);

#endif
