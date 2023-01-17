/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:01:57 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 20:40:52 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_element_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count == 1)
		return ;
	else if (stack_a->count == 2)
	{
		if (stack_a->bottom->n < stack_a->top->n)
			sa(stack_a);
		else
			return ;
	}
	else if (stack_a->count == 3)
		sort_element_3(stack_a);
	else if (stack_a->count == 4)
		sort_element_4(stack_a, stack_b);
	else if (stack_a->count == 5)
		sort_element_5(stack_a, stack_b);
}

void	sort_element_3(t_stack *stack_a)
{
	if (stack_a->bottom->n < stack_a->bottom->next->n && \
		stack_a->bottom->next->n < stack_a->top->n)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->bottom->n < stack_a->top->n && \
			stack_a->top->n < stack_a->bottom->next->n)
		rra(stack_a);
	else if (stack_a->bottom->next->n < stack_a->bottom->n && \
			stack_a->bottom->n < stack_a->top->n)
		ra(stack_a);
	else if (stack_a->top->n < stack_a->bottom->n && \
			stack_a->bottom->n < stack_a->bottom->next->n)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->bottom->next->n < stack_a->top->n && \
			stack_a->top->n < stack_a->bottom->n)
		sa(stack_a);
}

void	sort_element_4(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*start;
	t_node	*temp;

	start = stack_a->bottom;
	temp = stack_a->bottom;
	pb(stack_a, stack_b);
	sort_element_3(stack_a);
	while (temp->next)
	{
		if (stack_b->top->n < temp->n && \
		stack_b->top->n > temp->next->n)
			break ;
		else
			temp = temp->next;
	}
	while (temp != stack_a->top)
		ra(stack_a);
	pa(stack_a, stack_b);
	if (stack_a->top->prev->n < stack_a->top->n)
		start = stack_a->top;
	move_to_bottom(stack_a, start);
}

void	sort_element_5(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;
	t_node	*start;

	start = stack_a->bottom;
	temp = find_min_node(stack_a);
	move_to_top(stack_a, temp);
	pb(stack_a, stack_b);
	temp = find_min_node(stack_a);
	move_to_top(stack_a, temp);
	pb(stack_a, stack_b);
	sort_element_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

t_node	*find_min_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*save;
	int		min;

	min = 0;
	temp = stack->bottom;
	save = stack->bottom;
	while (temp)
	{
		if (temp->n < min)
		{
			min = temp->n;
			save = temp;
		}
		temp = temp->next;
	}
	return (save);
}
