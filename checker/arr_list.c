/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:36:50 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/30 16:57:27 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**arr_join(char **arr1, char **arr2)
{
	int		i;
	int		j;
	int		arr_size;
	char	**strarr;

	i = -1;
	arr_size = ft_arrsize(arr1) + ft_arrsize(arr2);
	if (!(strarr = (char **)malloc(sizeof(char *) * arr_size + 1)))
		return (NULL);
	while (arr1[++i])
		strarr[i] = ft_strdup(arr1[i]);
	ft_freearray(&arr1);
	j = 0;
	while (arr2[j] != NULL)
	{
		strarr[i + j] = ft_strdup(arr2[j]);
		j++;
	}
	ft_freearray(&arr2);
	strarr[j + i] = NULL;
	return (strarr);
}

char	**join_args(char **av)
{
	int		i;
	char	**array;
	char	**split;

	i = -1;
	array = (char **)malloc(sizeof(char *));
	*array = NULL;
	while (av[++i] != NULL)
	{
		if (!strcmp(av[i], "-v") || !ft_strcmp(av[i], "-c"))
			continue ;
		split = ft_strsplit(av[i], ' ');
		array = arr_join(array, split);
	}
	return (array);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = -1;
	while (++i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
	}
}

int		is_sorted(t_list *list, char **av)
{
	int i;
	int j;
	int *arr;

	i = -1;
	if (!(arr = (int *)malloc(sizeof(int) * ft_arrsize(av))))
		exit(EXIT_FAILURE);
	j = -1;
	while (av[++j] && ++i < ft_arrsize(av))
		arr[i] = ft_atoi(av[j]);
	sort_int_tab(arr, ft_arrsize(av));
	i = 0;
	while (i < ft_arrsize(av) && list != NULL)
	{
		if (arr[i] != list->data)
			return (0);
		i++;
		list = list->next;
	}
	return (1);
}
