/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:41:24 by marvin            #+#    #+#             */
/*   Updated: 2023/01/15 17:41:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	half_under(t_stack *stack_a, t_stack *stack_b, int count_a, int count_b)
{
	int	ret;

	ret = 0;
	while (count_a != 0 && count_b != 0)
	{
		count_a--;
		count_b--;
		ret++;
	}
	ret += (count_a + 1) + (count_b + 1);
	return (ret);
}

int	half_upper(t_stack *stack_a, t_stack *stack_b, int count_a, int count_b)
{
	int	ret;
	int	a_order;
	int	b_order;

	a_order = stack_a->count - count_a - 1;
	b_order = stack_b->count - count_b - 1;
	ret = 0;
	while (a_order != 0 && b_order != 0)
	{
		a_order--;
		b_order--;
		ret++;
	}
	ret += a_order + b_order;
	return (ret);
}

int	common_case(t_stack *stack, int count)
{
	if (count + 1 < (stack->count - count - 1))
		return (count + 1);
	else
		return (stack->count - count - 1);
}