/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:26:01 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/29 19:56:37 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	push_nodes(stack_a, stack_b);
	printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push_nodes(stack_b, stack_a);
	printf("pb\n");
}

void	sa(t_list **stack)
{
	swap_node(*stack);
	printf("sa\n");
}

void	sb(t_list **stack)
{
	swap_node(*stack);
	printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_node(*stack_a);
	swap_node(*stack_b);
	printf("ss\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	printf("rr\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate_nodes(stack_a);
	rrotate_nodes(stack_b);
	printf("rrr\n");
}

void	ra(t_list **stack_a)
{
	rotate_nodes(stack_a);
	printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate_nodes(stack_b);
	printf("rb\n");
}

void	rra(t_list **stack_a)
{
	rrotate_nodes(stack_a);
	printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rrotate_nodes(stack_b);
	printf("rrb\n");
}

