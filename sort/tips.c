/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tips.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:13:33 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 11:09:58 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	diviser_to_tips_b(t_list **a, t_list **b, int range)
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

static void	diviser_to_tips_a(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;

	i = 0;
	diviser = diviser_value(*b, range);
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

void	diviser_to_tips(t_list **a, t_list **b, int range, char stack)
{
	if (stack == 'a')
		diviser_to_tips_a(a, b, range);
	else if (stack == 'b')
		diviser_to_tips_b(a, b, range);
}
