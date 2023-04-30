/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tips_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:32:51 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 18:08:55 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	diviser_tips_sorted_b_asc(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		sub_diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = get_nth_greatness_value(*a, range, 0, range / 4);
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

static void	diviser_tips_sorted_b_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		sub_diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = get_nth_greatness_value(*a, range, 0, range - (range / 4));
	while (*a && i < range)
	{
		if (*(int *)(*a)->content < diviser)
			ra(a);
		else
		{
			if (*(int *)(*a)->content < sub_diviser)
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

static void	diviser_tips_sorted_a_asc(t_list **a, t_list **b, int range)
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

static void	diviser_tips_sorted_a_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		sub_diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*b, range);
	sub_diviser = get_nth_greatness_value(*b, range, 0, range - (range / 4));
	while (*b && i < range)
	{
		if (*(int *)(*b)->content < diviser)
			rb(b);
		else
		{
			if (*(int *)(*b)->content < sub_diviser)
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

void	diviser_tips_sorted(t_list **a, t_list **b, t_stat s)
{
	if (s.stack == 'a')
	{
		if (s.order == 'c')
			diviser_tips_sorted_a_asc(a, b, s.range);
		else if (s.order == 'd')
			diviser_tips_sorted_a_des(a, b, s.range);
		diviser_tips(a, b, (t_stat){s.stack, s.order, s.range / 2});
	}
	else if (s.stack == 'b')
	{
		if (s.order == 'c')
			diviser_tips_sorted_b_asc(a, b, s.range);
		else if (s.order == 'd')
			diviser_tips_sorted_b_des(a, b, s.range);
		diviser_tips(a, b, (t_stat){s.stack, 'd', s.range / 2});
	}
}
