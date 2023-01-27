/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:03:54 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 22:10:31 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*order_calc(t_stack *stk_a, t_stack *stk_b, int count_a, int count_b)
{
	t_info	*ret;

	if (count_a < (stk_a->count + 1) / 2 && \
		count_b < (stk_b->count + 1) / 2)
			ret = half_under(stk_a, stk_b, count_a, count_b);
	else if (count_a >= (stk_a->count + 1) / 2 && \
		count_b >= (stk_b->count + 1) / 2)
			ret = half_upper(stk_a, stk_b, count_a, count_b);
	else
	{
		ret = (t_info *)malloc(sizeof(t_info));
		if (ret == 0)
		{
			clear_stack(stk_a);
			clear_stack(stk_b);
			exit(1);
		}
		ret->order_count = 0;
		ret = opposite_dir(stk_a, count_a, ret);
		ret = opposite_dir(stk_b, count_b, ret);
	}
	return (ret);
}

t_info	*order_count(t_stack *stack_a, t_stack *stack_b, t_node *b_tmp)
{
	int		count_a;
	int		count_b;
	int		pos;
	t_node	*tmp;
	t_info	*save;

	count_a = 0;
	count_b = 0;
	tmp = stack_b->bottom;
	while (tmp->n != b_tmp->n)
	{
		count_b++;
		tmp = tmp->next;
	}
	tmp = stack_a->bottom;
	pos = find_right_position(stack_a, b_tmp->n);
	while (tmp->n != pos)
	{
		count_a++;
		tmp = tmp->next;
	}
	save = order_calc(stack_a, stack_b, count_a, count_b);
	save->a_save = tmp->n;
	save->b_save = b_tmp->n;
	return (save);
}

t_info	*find_best_element(t_stack *stack_a, t_stack *stack_b)
{
	t_info	*min;
	t_node	*temp;
	t_info	*save;

	temp = stack_b->bottom;
	min = 0;
	save = 0;
	while (temp)
	{
		save = order_count(stack_a, stack_b, temp);
		if (min == 0 || min->order_count > save->order_count)
		{
			if (min != 0)
				free(min);
			min = save;
		}
		else
			free(save);
		temp = temp->next;
	}
	return (min);
}

void	sort_element(t_stack *stack_a, t_stack *stack_b)
{
	t_info	*save;

	save = 0;
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
	free(save);
	move_to_bottom(stack_a, find_max_node(stack_a));
}
