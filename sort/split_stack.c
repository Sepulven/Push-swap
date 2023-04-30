/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:49 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 12:27:09 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	split_b_with_diviser(t_list **a, t_list **b, int range)
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

static void	split_a_with_diviser(t_list **a, t_list **b, int range)
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

void	split_with_diviser(t_list **a, t_list **b, int range, char stack)
{
	if (stack == 'a')
		split_a_with_diviser(a, b, range);
	else if (stack == 'b')
		split_b_with_diviser(a, b, range);
}
