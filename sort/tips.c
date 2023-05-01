/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tips.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:13:33 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 00:26:04 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	diviser_to_tips_b_asc(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*a, range);
	while (*a && i < range)
	{
		if (*(int *)(*a)->content > diviser)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
		i++;
	}
}

static void	diviser_to_tips_b_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*a, range);
	while (*a && i < range)
	{
		if (*(int *)(*a)->content < diviser)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
		i++;
	}
}

static void	diviser_to_tips_a_asc(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = get_nth_greatness_value(*b, range, 0, range / 2);
	while (*b && i < range)
	{
		if (*(int *)(*b)->content > diviser)
		{
			pa(a, b);
			ra(a);
		}
		else
			pa(a, b);
		i++;
	}
}

static void	diviser_to_tips_a_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*b, range);
	while (*b && i < range)
	{
		if (*(int *)(*b)->content < diviser)
		{
			pa(a, b);
			ra(a);
		}
		else
			pa(a, b);
		i++;
	}
}

void	diviser_tips(t_list **a, t_list **b, t_stat s)
{
	if (s.stack == 'a')
	{
		if (s.order == 'c')
			diviser_to_tips_a_asc(a, b, s.range);
		else if (s.order == 'd')
			diviser_to_tips_a_des(a, b, s.range);
	}
	else if (s.stack == 'b')
	{
		if (s.order == 'c')
			diviser_to_tips_b_asc(a, b, s.range);
		else if (s.order == 'd')
			diviser_to_tips_b_des(a, b, s.range);
	}
}
