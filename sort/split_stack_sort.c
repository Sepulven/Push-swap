/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:13:47 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 12:29:28 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	split_b_stack_sorted(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;
	int		sub_diviser;

	i = 0;
	diviser = diviser_value(*b, range);
	sub_diviser = sub_diviser_value(*b, range);
	while (*b && i < range)
	{
		if (*(int *)(*b)->content > diviser)
			rb(b);
		else
		{
			if (*(int *)(*b)->content > sub_diviser)
			{
				pa(a, b);
				ra(a);
			}
			else
				pa(a, b);
		}
		i++;
	}
}

static void	split_a_stack_sorted(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;
	int		sub_diviser;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = sub_diviser_value(*b, range);
	while (*a && i < range)
	{
		if (*(int *)(*a)->content > diviser)
			ra(a);
		else
		{
			if (*(int *)(*a)->content > sub_diviser)
			{
				pb(a, b);
				rb(b);
			}
			else
				pb(a, b);
		}
		i++;
	}
}

void	split_stack_diviser(t_list **a, t_list **b, int range, char stack)
{
	if (stack == 'a')
		split_a_stack_sorted(a, b, range);
	else if (stack == 'b')
		split_b_stack_sorted(a, b, range);
}
