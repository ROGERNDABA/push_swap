/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 08:34:00 by rmdaba            #+#    #+#             */
/*   Updated: 2018/09/01 11:44:35 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	char	*line;
	char	**array;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	array = join_args(av + 1);
	stack_a = make_stack_a(stack_a, array);
	stack_a->data_size = 0;
	while (get_next_line(0, &line) > 0)
	{
		check_cmd(&stack_a, &stack_b, line);
		free(line);
	}
	tmp = stack_a;
	ft_printf((is_sorted(tmp, array)) ? "OK\n" : "KO\n");
	//ft_freearray(&array);
	del_nodes(&stack_a);
	del_nodes(&stack_b);
	return (0);
}
