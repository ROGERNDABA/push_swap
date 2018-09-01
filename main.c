/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:19:18 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/31 12:16:12 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  list_last(t_list *head)
{
	t_list *list;

	list = head;
	while (list->next != NULL)
		list = list->next;
	return(list->data);
}

int val_dist(t_list *list, int a, int b)
{
	int i = 0;
	t_list *e;

	e = list;
	while (list != NULL)
	{
		printf(GREEN"outer loop\n");
		if (list->data == a)
		{
			printf(RED"if statement\n");
			i = 0;
			while (list->data != b)
			{
				printf(YELLOW"inner loop\n"DEFAULT);
				list = list->next;
				i++;
			}
			return (i);
		}
		list = list->next;
	}
	return (0);
}

int lowest(t_list *e, int i)
{
	int r;
	t_list *list;

	list = e;
	r = list->data;
	while (list != NULL)
	{
		if (i == 0)
			r = (r < list->data) ? r : list->data;
		else
			r = (r > list->data) ? r : list->data;
		list = list->next;
	}
	return (r);
}

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		list_center(t_list *head)
{
	int i;
	int z;
	t_list *list;

	i = -1;
	list = head;
	z = ft_list_size(list);
	if (z % 2 == 0)
	{
		while (++i < (z / 2) - 1)
			list = list->next;
	}
	else
	{
		while (++i < z / 2)
			list = list->next;
	}
	return (list->data);
}

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


int algo(int n)
{
	int i = n;
	if (n == 1)
		return (n);
	else if (n <= 100)
	{
		while (i > 0)
		{
			if ((n / i) > 4)
				return (i);
			i -= 1;
		}
	}
	else
	{
		while (i > 0)
		{
			if ((n / i) > 6)
				return (i);
			i -= 1;
		}
	}
	return (1);
}

void start_algo(t_push *e)
{
	int i = 0;
	int s = e->fctr;
	while (i < e->size)
	{
		if (ft_list_size(e->a) < 10)
			break;
		if (e->a->data < e->sorted[s])
		{
			pb(&e->a, &e->b);
			i = 0;
		}
		else if (e->a->next->data < e->sorted[s])
		{
			sa(&e->a);
			pb(&e->a, &e->b);
			i = 0;
		}
		else if (list_last(e->a) < e->sorted[s])
		{
			rra(&e->a);
			pb(&e->a, &e->b);
			i = 0;
		}
		else
			ra(&e->a);
		if (ft_list_size(e->b) == s)
		{
			s = s + e->fctr - 1;
			continue;
		}
		i++;
	}
	//return(e);
}

void solve(t_push *e)
{
	int i = 0;
	int low;
	int high;
	start_algo(e);
	//printf("\n");
	int c = (list_center(e->b));
	int size = ft_list_size(e->b);
	//while (i < size)
	//{
		high = lowest(e->b, 1);
		low = lowest(e->b, 0);
		printf(RED"low %d\nc %d\nhigh %d\n"DEFAULT, low, c, high);//val_dist(e->b, low, c));
		printf(RED"low %d\nc %d\n"DEFAULT, val_dist(e->b, low, c), c);//val_dist(e->b, low, c));
		//if (val_dist(e->b, low, c) > val_dist(e->b, c, high))
		//{
			while(e->b->data != low)
				rrb(&e->b);
			pa(&e->a, &e->b);
			//break;
		//}
	//}
}

int main(int ac, char **av)
{
	t_push *e;

	if (ac == 1)
		return (0);
	e = init_push();
	e->array = join_args(av + 1);
	e->a = make_stack_a(e->a, e->array);
	e->size = ft_arrsize(e->array);
	e->fctr = algo(e->size);
	e->sorted = make_array(&e->array);
	while (1)
		;
	//printf("\n SHIT >>");
	//for(int i = 0;i < e->size;i++)
	//	printf("%d ", e->sorted[i]);
	solve(e);
	//printf(">>>> %d\n",algo(e->size));
	//printf("distance %d\n", val_dist(e->a, 3, 6));
	//printf("\nStack A = ");
	//while (e->a != NULL)
	//{
	//	printf("%d ", e->a->data);
	//	e->a = e->a->next;
	//}
	//printf("\n");
	//printf("Stack B = ");
	//while (e->b != NULL)
	//{
	//	printf("%d ", e->b->data);
	//	e->b = e->b->next;
	//}
	//printf("\n");
}
