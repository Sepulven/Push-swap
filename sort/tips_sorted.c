/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tips_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:32:51 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 12:16:49 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	diviser_tips_sorted_b(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		sub_diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = sub_diviser_value(*a, range);
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

static void	diviser_tips_sorted_a(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		sub_diviser;
	int		i;

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

void	diviser_tips_sorted(t_list **a, t_list **b, int range, char stack)
{
	if (stack == 'a')
	{
		diviser_tips_sorted_a(a, b, range);
		diviser_to_tips(a, b, range / 2, 'a');
	}
	else if (stack == 'b')
	{
		diviser_tips_sorted_b(a, b, range);
		diviser_to_tips(a, b, range / 2, 'b');
	}
}
