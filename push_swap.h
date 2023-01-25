/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:22:00 by marvin            #+#    #+#             */
/*   Updated: 2023/01/19 20:52:29 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;
};

typedef struct s_node	t_node;

typedef struct s_stack
{
	t_node	*bottom;
	t_node	*top;
	int		count;
}	t_stack;

typedef struct s_info
{
	int		b_save;
	int		a_save;
	int		order_count;
	int		rr_flag;
	int		rrr_flag;
}	t_info;

void	push(t_stack *stack, int content);
int		pop(t_stack *stack);
int		is_empty(t_stack *stack);
void	init_stack(t_stack *stack);
void	clear_stack(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		is_integer(char *argv);
int		check_dup(t_stack *stack_a, int num);
int		check_and_push_integer(t_stack *stack_a, char *argv);
void	push_input(t_stack *stack_a, int argc, char *argv[]);
void	sort_element(t_stack *stack_a, t_stack *stack_b);
void	calc_path(t_stack *stack_a, t_node *pos);
int		count_index(t_stack *stk, int n);
void	move_to_bottom(t_stack *stack, t_node *node);
void	move_to_top(t_stack *stack, t_node *node);
void	sort_element_small(t_stack *stack_a, t_stack *stack_b);
void	sort_element_3(t_stack *stack_a);
void	sort_element_4(t_stack *stack_a, t_stack *stack_b);
void	sort_element_5(t_stack *stack_a, t_stack *stack_b);
t_node	*find_min_node(t_stack *stack);
int		check_ordered(t_stack *stack);
void	push_to_b_and_sort3(t_stack *stack_a, t_stack *stack_b);
t_info	*order_calc(t_stack *stk_a, t_stack *stk_b, int count_a, int count_b);
t_info	*order_count(t_stack *stack_a, t_stack *stack_b, t_node *b_tmp);
t_info	*find_best_element(t_stack *stack_a, t_stack *stack_b);
void	sort_element(t_stack *stack_a, t_stack *stack_b);
t_info	*half_under(t_stack *stk_a, t_stack *stk_b, int count_a, int count_b);
t_info	*half_upper(t_stack *stk_a, t_stack *stk_b, int count_a, int count_b);
t_info	*opposite_dir(t_stack *stack, int count, t_info *ret);
void	case_rr(t_stack *stk_a, t_stack *stk_b, t_info *save);
void	case_rrr(t_stack *stk_a, t_stack *stk_b, t_info *save);
void	case_common(t_stack *stk_a, t_stack *stk_b, t_info *save);
int		find_right_position(t_stack *stack, int n);
t_node	*find_max_node(t_stack *stack);

#endif