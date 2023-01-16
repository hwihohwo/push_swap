/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2023/01/16 20:13:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_rr(t_stack *stk_a, t_stack *stk_b, t_info *save)
{
	while (stk_a->top != save->a_save && \
				stk_b->top != save->b_save)
	{
		rr(stk_a, stk_b);
		save->order_count--;
	}
	while (stk_a->top != save->a_save)
		ra(stk_a);
	while (stk_b->top != save->b_save)
		rb(stk_b);
}

void	case_rrr(t_stack *stk_a, t_stack *stk_b, t_info *save)
{
	while (stk_a->top != save->a_save && \
				stk_b->top != save->b_save)
	{
		rrr(stk_a, stk_b);
		save->order_count--;
	}
	while (stk_a->top != save->a_save)
		rra(stk_a);
	while (stk_b->top != save->b_save)
		rrb(stk_b);
}

void	case_common(t_stack *stk_a, t_stack *stk_b, t_info *save)
{
	int	count;

	count = count_index(stk_a, save->a_save);
	if (count + 1 < (stk_a->count -count - 1))
		while (stk_a->top != save->a_save)
			rra(stk_a);
	else
		while (stk_a->top != save->a_save)
			ra(stk_a);
	count = count_index(stk_b, save->b_save);
	if (count + 1 < (stk_b->count -count - 1))
		while (stk_b->top != save->b_save)
			rrb(stk_b);
	else
		while (stk_b->top != save->b_save)
			rb(stk_b);
}