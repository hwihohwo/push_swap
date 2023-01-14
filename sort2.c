/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:03:54 by marvin            #+#    #+#             */
/*   Updated: 2023/01/13 18:03:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_position(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*start;
	t_node	*temp;
	int		b_top;

	start = stack_a->bottom;
	while (stack_b->count > 0)
	{
		b_top = stack_b->top->content;
		temp = start;
		if (temp->content > b_top && temp->next->content < b_top)
		{
			calc_path(stack_a, temp);
			pa(stack_a, stack_b);
		}
		else
			temp = temp->next;
	}
}

void	calc_path(t_stack *stack_a, t_node *pos)
{
	t_node	*temp;
	int		count;

	count = 0;
	temp = stack_a->bottom;
	while (temp == pos)
	{
		count++;
		temp = temp->next;
	}
	if (count < (stack_a->count + 1) / 2)
		while (stack_a->top == pos)
			rra(stack_a);
	else
		while (stack_a->top == pos)
			ra(stack_a);
}