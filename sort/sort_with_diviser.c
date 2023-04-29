/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_diviser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:50:31 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 16:32:53 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	diviser_value(t_list *list, int range)
{
	int	*buff;
	int	i;
	int	j;
	int	tmp;

	buff = malloc(range * sizeof (int));
	if (!buff)
		return (-0);
	i = 0;
	while (list && i < range)
	{
		buff[i] = *(int *)list->content;
		list = list->next;
		i++;
	}
	// Bubble sort
	i = 0;
	while (i < range - 1)
	{
		j = 0;
		while (j < range - 1)
		{
			if (buff[j] > buff[j + 1])
				ft_swap(&buff[j], &buff[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < (range - 1) / 2)
		i++;
	tmp = buff[i + (range % 2 != 0)];
	free(buff);
	return (tmp);
}

float	calculate_avrg(t_list *list, int range)
{
	float	sum;
	int		size;

	size = 0;
	sum = 0;
	while (list && size < range)
	{
		sum += *(int *)list->content;
		size++;
		list = list->next;
	}
	return (sum / size);
}

void	sort_with_diviser(t_list **a, t_list **b, int range, char order, char stack)
{
	int		i;
	int		left;
	int		right;
	int		diviser;

	if (stack == 'a')
	{
		left = 0;
		right = 0;
		i = 0;
		if (!a || !*a)
			return ;
		diviser = diviser_value(*a, range);
		while (*a && i < range)
		{
			if (order == 'c' && *(int *)(*a)->content >= diviser)
			{
				pb(a, b);
				left++;
			}
			else if (order == 'c')
			{
				pb(a, b);
				rb(b);
				right++;
			}
			else if (order == 'd' && *(int *)(*a)->content <= diviser)
			{
				pb(a, b);
				left++;
			}
			else if (order == 'd')
			{
				pb(a, b);
				rb(b);
				right++;
			}
			i++;
		}
	}
	else if (stack == 'b')
	{
		left = 0;
		right = 0;
		i = 0;
		if (!b || !*b)
			return ;
		ft_printf("dentro\n");
		diviser = diviser_value(*b, range);
		ft_printf("dentro\n");
		while (*b && i < range)
		{
			ft_printf("dentro\n");
			if (order == 'c' && *(int *)(*b)->content >= diviser)
			{
				pa(a, b);
				left++;
			}
			else if (order == 'c')
			{
				pa(a, b);
				ra(a);
				right++;
			}
			else if (order == 'd' && *(int *)(*b)->content <= diviser)
			{
				pa(a, b);
				left++;
			}
			else if (order == 'd')
			{
				pa(a, b);
				ra(a);
				right++;
			}
			i++;
		}
	}
}

void	sort_n(t_list **a, t_list **b, \
		int (*f)(t_list *, int, int), t_sort_n stat)
{
	int	pos;
	int	size;

	if (stat.stack == 'a')
		size = ft_lstsize(*b);
	else if (stat.stack == 'b')
		size = ft_lstsize(*a);
	if (size == stat.l_side + stat.r_side)
	{
		stat.l_side = size;
		stat.r_side = 0;
	}
	while (stat.l_side + stat.r_side > 0 && size)
	{
		if (stat.stack == 'a')
			pos = f(*b, stat.l_side - 1, stat.r_side - 1);
		else if (stat.stack == 'b')
			pos = f(*a, stat.l_side - 1, stat.r_side - 1);
		send_el_to(a, b, pos, stat.stack);
		if (pos < stat.l_side) // Left
		{
			stat.r_side += pos;
			stat.l_side -= pos;
		}
		else if (pos >= size - stat.r_side) // Right
		{
			stat.l_side = stat.l_side + (size - pos);
			stat.r_side = stat.r_side - (size - pos);
		}
		size--;
		stat.l_side--;
	}
}

void	print_char_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("[%d]%s\n", i, matrix[i]);
		i++;
	}
}

