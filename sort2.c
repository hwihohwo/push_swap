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

t_info	*order_calc(t_stack *stk_a, t_stack *stk_b, int count_a, int count_b)
{
	t_info	*ret;

	if (count_a < (stk_a->count + 1) / 2 && \
		count_b < (stk_b->count + 1) / 2)
			ret = half_under(stk_a, stk_b, count_a, count_b);
	else if (count_a >= (stk_a->count + 1) /2  && \
		count_b >= (stk_b->count + 1) / 2)
			ret = half_upper(stk_a, stk_b, count_a, count_b);
	else
	{
		ret = common_case(stk_a, count_a);
		ret = common_case(stk_b, count_b);
	}
	return (ret);
}

t_info	*order_count(t_stack *stack_a, t_stack *stack_b, t_node *b_temp)
{
	int		count_a;
	int		count_b;
	t_node 	*tmp;
	t_info	*save;

	count_a = 0;
	count_b = 0;
	tmp = stack_b->bottom;
	while (tmp != b_temp)
	{
		count_b++;
		tmp = tmp->next;
	}
	tmp = stack_a->bottom;
	while (!(tmp->content > tmp->content && tmp->next->content < tmp->content))
	{
		count_a++;
		tmp = tmp->next;
	}
	save = order_calc(stack_a, stack_b, count_a, count_b);
	save->a_save = tmp;
	return (save);
}

t_info	*find_best_element(t_stack *stack_a, t_stack *stack_b)
{
	int		max;
	t_node 	*temp;
	t_info	*save;

	temp = stack_b->bottom;
	max = 0;
	while (temp)
	{
		save = order_count(stack_a, stack_b, temp);
		if (max < save->order_count)
		{
			max = save->order_count;
			save->b_save = temp;
		}
		temp = temp->next;
	}
	return (save);
}

void	sort_element(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*start;
	t_info	*save;
	int		count;

	save = 0;
	start = stack_a->bottom;
	while (stack_b->count > 0)
	{
		save = find_best_element(stack_a, stack_b);
		if (save->rr_flag == 1)
			case_rr(stack_a, stack_b, save);
		else if (save->rrr_flag == 1)
			case_rrr(stack_a, stack_b, save);
		else
			case_common(stack_a, stack_b, save);
		pa(stack_a, stack_b);
	}
	count = count_index(stack_a, start);
	if (count < (stack_a->count - count))
		while (stack_a->bottom != start)
			rra(stack_a);
	else
		while (stack_a->bottom != start)
			ra(stack_a);
}
