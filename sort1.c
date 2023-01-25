/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:21:22 by seonghwc          #+#    #+#             */
/*   Updated: 2023/01/17 19:49:40 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_node	*find_pivot_sub(t_stack *stack)
{
	int		n;
	t_node	*check;

	n = 0;
	check = stack->bottom;
	while (n < 3)
	{
		check = check->next;
		n++;
	}
	return (check);
}

int	find_pivot(t_stack *stack)
{
	int		n;
	t_node	*ret;
	t_node	*check;
	t_node	*temp;

	n = 0;
	check = find_pivot_sub(stack);
	ret = check;
	while (1)
	{
		temp = check;
		n = 0;
		while (temp)
		{
			if (temp->n < ret->n)
				n++;
			temp = temp->next;
		}
		if (n == (stack->count - 3) / 2)
			return (ret->n);
		ret = ret->next;
	}
}

void	push_to_b_and_sort3(t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;
	t_node	*temp;

	temp = stack_a->bottom;
	pivot = find_pivot(stack_a);
	while (stack_a->count > 3)
	{
		if (temp->n >= pivot)
			pb(stack_a, stack_b);
		else
		{
			pb(stack_a, stack_b);
			sb(stack_b);
		}
	}
	sort_element_3(stack_a);
}
