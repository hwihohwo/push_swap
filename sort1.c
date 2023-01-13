/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:21:22 by seonghwc          #+#    #+#             */
/*   Updated: 2023/01/11 18:12:36 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ordered_length(t_node *current)
{
	int		count;
	t_node *cursur;

	count = 0;
	cursur = current;
	while (cursur->next != 0 && cursur->content > cursur->next->content)
	{
		count++;
		cursur = cursur->next;
	}
	return (count);
}

void	mov_ordered_to_bottom(t_stack *stack_a, t_node *save)
{
	int		bottom_to_save;
	t_node *temp;

	bottom_to_save = 0;
	temp = stack_a->bottom;
	while (temp != save)
	{
		bottom_to_save++;
		temp = temp->next;
	}
	if (bottom_to_save <= stack_a->count / 2)
		while (stack_a->bottom == save)
			rra(stack_a);
	else if (bottom_to_save > stack_a->count / 2)
		while (stack_a->bottom == save)
			ra(stack_a);
}

void	mov_to_stack_b(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_node *order_end;

	order_end = stack_a->bottom;
	while (count > 0)
	{
		order_end = order_end->next;
		count--;
	}
	while (stack_a->top != order_end)
		pb(stack_a, stack_b);
}

void	find_and_move_ordered(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*save;
	int		count;
	int		max;

	max = 0;
	current = stack_a->bottom;
	save = stack_a->bottom;
	while (current->next)
	{
		count = check_ordered_length(current);
		if (max < count)
		{
			max = count;
			save = current;
		}
		current = current->next;
	}
	mov_ordered_to_bottom(stack_a, save);
	mov_to_stack_b(stack_a, stack_b, count);
}
