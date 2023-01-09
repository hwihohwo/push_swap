/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:21:43 by marvin            #+#    #+#             */
/*   Updated: 2023/01/05 09:21:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(1);
	node->content = content;
	node->next = NULL;
	if (stack->bottom == NULL && stack->top == NULL)
	{
		stack->bottom = node;
		stack->top = node;
		node->prev = NULL;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->count++;
}

int	pop(t_stack *stack)
{
	int		ret;
	t_node	*temp;
	t_node 	*next_top;

	temp = stack->top;
	ret = stack->top->content;
	if (stack->top->prev != NULL)
		stack->top = stack->top->prev;
	else
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	free(temp);
	stack->count--;
	return (ret);
}

int	is_empty(t_stack *stack)
{
	if (stack->count == 0)
		return (0);
	else
		return (1);
}