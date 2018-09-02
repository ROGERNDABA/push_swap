/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:19:18 by rmdaba            #+#    #+#             */
/*   Updated: 2018/09/02 13:00:31 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

t_push		*init_push(void)
{
	t_push *e;

	e = (t_push *)malloc(sizeof(t_push));
	e->a = NULL;
	e->b = NULL;
	e->array = NULL;
	e->sorted = 0;
	e->size = 0;
	e->fctr = 0;
	return (e);
}

int		*make_array(char ***arr)
{
	int *tab;
	int i = -1;
	int size;

	size = ft_arrsize(*arr);
	tab = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		tab[i] = ft_atoi((*arr)[i]);
	sort_int_tab(tab, size);
	return (tab);
}




void start_algo(t_push *e)
{
	int i = 0;
	int s = e->fctr;
	while (i < e->size)
	{
		if (e->a->data <= e->sorted[s])
		{
			pb(&e->a, &e->b);
			i = 0;
		}
		else if (e->a->next->data <= e->sorted[s])
		{
			sa(&e->a);
			pb(&e->a, &e->b);
			i = 0;
		}
		else if (list_last(e->a) <= e->sorted[s])
		{
			rra(&e->a);
			pb(&e->a, &e->b);
			i = 0;
		}
		else if (scnd_last(e->a) <= e->sorted[s])
		{
			rra(&e->a);
			rra(&e->a);
			pb(&e->a, &e->b);
			i = 0;
		}
		//else
//			ra(&e->a);
		if (ft_list_size(e->b) == s)
		{
			s = s + e->fctr - 1;
			continue;
		}
		i++;
	}
	while (ft_list_size(e->a))
		pb(&e->a, &e->b);
}

void solve(t_push *e)
{
	int i = 0;
	int low;
	int high;
	start_algo(e);
	int c = (list_center(e->b));
	int size = ft_list_size(e->b);
	
	while (i < size && e->b != NULL)
	{
		low = lowest(e->b, 0);
		high = lowest(e->b, 1);
		//if(e->a->data == low || e->a->data == high)
			//pb(&e->a, &e->b);

		if (val_dist(e->b, low, c) > val_dist(e->b, c, high) && left_right(e->b, low) == 1)
		{
			//printf(YELLOW" %d\n"DEFAULT, left_right(e->b, low));
			//printf(CYAN"low position %d\n"DEFAULT, position(e->b, low));
			while(e->b->data != low)
				rb(&e->b);
			pa(&e->a, &e->b);
			ra(&e->a);
			print_list(e->a, 'A');
			print_list(e->b, 'B');	
			//i= 0;
			//break;
		}
		else if (val_dist(e->b, low, c) > val_dist(e->b, c, high) && left_right(e->b, low) == 2)
		{
			//printf(YELLOW" %d\n"DEFAULT, left_right(e->b, low));
			//printf(CYAN"low position %d\n"DEFAULT, position(e->b, low));
			while(e->b->data != low)
				rrb(&e->b);
			pa(&e->a, &e->b);
			ra(&e->a);
			print_list(e->a, 'A');
			print_list(e->b, 'B');
			//i= 0;
			//break;
		}
		else if (val_dist(e->b, c, high) > val_dist(e->b, low, c) && left_right(e->b, high) == 1)
		{
			//printf(YELLOW" %d\n"DEFAULT, left_right(e->b, high));
			//printf(CYAN"high position %d\n"DEFAULT, position(e->b, high));
			while(e->b->data != high)
				rb(&e->b);
//			printf(GREEN"data->b %d\n"DEFAULT, e->b->data);
			pa(&e->a, &e->b);
			print_list(e->a, 'A');
			print_list(e->b, 'B');
		}
		else if (val_dist(e->b, c, high) > val_dist(e->b, low, c) && left_right(e->b, high) == 2)
		{
			//printf(YELLOW" %d\n"DEFAULT, left_right(e->b, high));
			//printf(CYAN"high position %d\n"DEFAULT, position(e->b, high));
			while(e->b->data != high)
				rrb(&e->b);
			//printf(GREEN"data->b %d\n"DEFAULT, e->b->data);
			pa(&e->a, &e->b);
			print_list(e->a, 'A');
			print_list(e->b, 'B');
		}
		else if (e->b->data == low)
		{
			pa(&e->a, &e->b);
			ra(&e->a);
			print_list(e->a, 'A');
			print_list(e->b, 'B');
		}
		else if (e->b->data == high)
			pa(&e->a, &e->b);
		else if (val_dist(e->b, c, high) == val_dist(e->b, low, c))
		{
			while(e->b->data != high)
				rb(&e->b);
			pa(&e->a, &e->b);
			print_list(e->a, 'A');
			print_list(e->b, 'B');
		}
		else if (e->a->next->data == low)
		{
			sb(&e->b);
			pa(&e->a, &e->b);
			i = 0;
			print_list(e->a, 'A');
			print_list(e->b, 'B');
		}
		i++;
	}
	while (e->a->data != lowest(e->a, 0))
		ra(&e->a);
}

t_push *create_stuff(t_push *e, char **av)
{
	e->array = join_args(av + 1);
	e->a = make_stack_a(e->a, e->array);
	e->size = ft_arrsize(e->array);
	e->fctr = get_factor(e->size);
	e->sorted = make_array(&e->array);
	return (e);	
}

int main(int ac, char **av)
{
	t_push *e;

	if (ac == 1)
		return (0);
	e = init_push();
	e = create_stuff(e, av);
	if (is_sorted(e->a, e->array))
		return (0);
	solve(e);
	//printf(YELLOW"%d\n", left_right(e->a, 10));
	print_list(e->a, 'A');
	print_list(e->b, 'B');	
	printf("\n"DEFAULT);
}
