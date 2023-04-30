/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:49 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 12:57:55 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	split_b_with_diviser_asc(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*b, range);
	while (*b && i < range)
	{
		if (*(int *)(*b)->content > diviser)
			rb(b);
		else
			pa(a, b);
		i++;
	}
}

static void	split_b_with_diviser_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*b, range);
	while (*b && i < range)
	{
		if (*(int *)(*b)->content < diviser)
			rb(b);
		else
			pa(a, b);
		i++;
	}
}

static void	split_a_with_diviser_asc(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*a, range);
	while (*a && i < range)
	{
		if (*(int *)(*a)->content > diviser)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

static void	split_a_with_diviser_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*a, range);
	while (*a && i < range)
	{
		if (*(int *)(*a)->content < diviser)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

void	split_stack(t_list **a, t_list **b, t_stat s)
{
	if (s.stack == 'a')
	{
		if (s.order == 'c')
			split_a_with_diviser_asc(a, b, s.range);
		else if (s.order == 'd')
			split_a_with_diviser_des(a, b, s.range);
	}
	else if (s.stack == 'b')
	{
		if (s.order == 'c')
			split_b_with_diviser_asc(a, b, s.range);
		else if (s.order == 'd')
			split_b_with_diviser_des(a, b, s.range);
	}
}
