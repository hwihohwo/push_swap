/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:17:48 by seonghwc          #+#    #+#             */
/*   Updated: 2023/01/26 21:41:39 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_bottom(t_stack *stack, t_node *node)
{
	int	count;

	count = count_index(stack, node->n);
	if (count < (stack->count - count))
		while (stack->bottom->n != node->n)
			rra(stack);
	else
		while (stack->bottom->n != node->n)
			ra(stack);
}

void	move_to_top(t_stack *stack, t_node *node)
{
	int	count;

	count = count_index(stack, node->n);
	if (count + 1 < (stack->count - count - 1))
		while (stack->top->n != node->n)
			rra(stack);
	else
		while (stack->top->n != node->n)
			ra(stack);
}

int	find_right_position(t_stack *stack, int n)
{
	t_node	*current;
	t_node	*next;
	int		min;

	min = stack->bottom->n;
	current = stack->bottom;
	while (current)
	{
		if (current->next != 0)
			next = current->next;
		else
			next = stack->bottom;
		if (min > current->n)
			min = current->n;
		if (current->n > n && next->n < n)
			return (current->n);
		else
			current = current->next;
	}
	return (min);
}

t_node	*find_max_node(t_stack *stack)
{
	int		max;
	t_node	*max_node;
	t_node	*temp;

	max = stack->bottom->n;
	max_node = stack->bottom;
	temp = stack->bottom;
	while (temp)
	{
		if (max < temp->n)
		{
			max = temp->n;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

int	check_ordered(t_stack *stack)
{
	int		count;
	t_node	*cursur;

	count = 0;
	cursur = stack->bottom;
	while (cursur->next && cursur->n > cursur->next->n)
	{
		count++;
		cursur = cursur->next;
	}
	if (count + 1 == stack->count)
		return (1);
	else
		return (0);
}
