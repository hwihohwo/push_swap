/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:41:24 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 15:45:41 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*half_under(t_stack *stk_a, t_stack *stk_b, int count_a, int count_b)
{
	t_info	*ret;

	ret = (t_info *)malloc(sizeof(t_info));
	if (ret == 0)
	{
		clear_stack(stk_a);
		clear_stack(stk_b);
		exit(1);
	}
	ret->order_count = 0;
	ret->rrr_flag = 1;
	ret->rr_flag = 0;
	while (count_a != 0 && count_b != 0)
	{
		count_a--;
		count_b--;
		ret->order_count++;
	}
	ret->order_count += (count_a + 1) + (count_b + 1);
	return (ret);
}

t_info	*half_upper(t_stack *stk_a, t_stack *stk_b, int count_a, int count_b)
{
	t_info	*ret;
	int		a_order;
	int		b_order;

	ret = (t_info *)malloc(sizeof(t_info));
	if (ret == 0)
	{
		clear_stack(stk_a);
		clear_stack(stk_b);
		exit(1);
	}
	a_order = stk_a->count - count_a - 1;
	b_order = stk_b->count - count_b - 1;
	ret->order_count = 0;
	ret->rrr_flag = 0;
	ret->rr_flag = 1;
	while (a_order != 0 && b_order != 0)
	{
		a_order--;
		b_order--;
		ret->order_count++;
	}
	ret->order_count += a_order + b_order;
	return (ret);
}

t_info	*opposite_dir(t_stack *stack, int count, t_info *ret)
{
	ret->rrr_flag = 0;
	ret->rr_flag = 0;
	if (count + 1 < (stack->count - count - 1))
		ret->order_count += count + 1;
	else
		ret->order_count += stack->count - count - 1;
	return (ret);
}
