/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:27:17 by rmdaba            #+#    #+#             */
/*   Updated: 2018/09/02 12:06:57 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_cmd1(t_list **stack_a, t_list **stack_b, char *s)
{
	if (!ft_strcmp(s, "ss"))
	{
		swap_node(*stack_a);
		swap_node(*stack_b);
	}
	else if (!(ft_strcmp(s, "rr")))
	{
		rotate_nodes(stack_a);
		rotate_nodes(stack_b);
	}
	else if (!(ft_strcmp(s, "rrr")))
	{
		rrotate_nodes(stack_a);
		rrotate_nodes(stack_a);
	}
}

void	check_cmd(t_list **stack_a, t_list **stack_b, char *s)
{
	if (!(ft_strcmp(s, "sa")))
		swap_node(*stack_a);
	else if (!(ft_strcmp(s, "sb")))
		swap_node(*stack_b);
	else if (!(ft_strcmp(s, "ra")))
		rotate_nodes(stack_a);
	else if (!(ft_strcmp(s, "rb")))
		rotate_nodes(stack_b);
	else if (!(ft_strcmp(s, "rra")))
		rrotate_nodes(stack_a);
	else if (!(ft_strcmp(s, "rrb")))
		rrotate_nodes(stack_b);
	else if (!ft_strcmp(s, "ss") || !ft_strcmp(s, "rr") ||
			!ft_strcmp(s, "rrr"))
		check_cmd1(stack_a, stack_b, s);
	else if (!ft_strcmp(s, "pb") && *stack_a)
		push_nodes(stack_b, stack_a);
	else if (!ft_strcmp(s, "pa") && *stack_b)
		push_nodes(stack_a, stack_b);
	else
	{
		printf("Error\n");
		exit (1);
	}
}
