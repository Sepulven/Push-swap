/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:13:47 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:32 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	split_b_stack_sorted_asc(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;
	int		sub_diviser;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = get_nth_greatness_value(*a, range, 0, range / 4);
	while (*a && i < range)
	{
		if (*(int *)(*a)->content > diviser)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b) && *(int *)(*b)->content <= sub_diviser \
			&& *(int *)(*a)->content > diviser)
			{
				rr(a, b);
				i++;
			}
			else if ((*b) && *(int *)(*b)->content <= sub_diviser)
				rb(b);
		}
		i++;
	}
}

static void	split_b_stack_sorted_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;
	int		sub_diviser;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = get_nth_greatness_value(*a, range, 0, range - (range / 4));
	while (*a && i < range)
	{
		if (*(int *)(*a)->content < diviser)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b) && *(int *)(*b)->content < sub_diviser \
			&& *(int *)(*a)->content < diviser)
			{
				rr(a, b);
				i++;
			}
			else if ((*b) && *(int *)(*b)->content < sub_diviser)
				rb(b);
		}
		i++;
	}
}

static void	split_a_stack_sorted_asc(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;
	int		sub_diviser;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = get_nth_greatness_value(*a, range, 0, range / 4);
	while (*a && i < range)
	{
		if (*(int *)(*a)->content > diviser)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b) && *(int *)(*b)->content <= sub_diviser \
			&& *(int *)(*a)->content > diviser)
			{
				rr(a, b);
				i++;
			}
			else if ((*b) && *(int *)(*b)->content <= sub_diviser)
				rb(b);
		}
		i++;
	}
}

static void	split_a_stack_sorted_des(t_list **a, t_list **b, int range)
{
	int		diviser;
	int		i;
	int		sub_diviser;

	i = 0;
	diviser = diviser_value(*a, range);
	sub_diviser = get_nth_greatness_value(*a, range, 0, range - (range / 4));
	while (*a && i < range)
	{
		if (*(int *)(*a)->content < diviser)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b) && *(int *)(*b)->content < sub_diviser && \
			*(int *)(*a)->content < diviser)
			{
				rr(a, b);
				i++;
			}
			else if ((*b) && *(int *)(*b)->content < sub_diviser)
				rb(b);
		}
		i++;
	}
}

void	split_stack_diviser(t_list **a, t_list **b, t_stat s)
{
	if ((*a) && s.stack == 'a')
	{
		if (s.order == 'c')
			split_a_stack_sorted_asc(a, b, s.range);
		else if (s.order == 'd')
			split_a_stack_sorted_des(a, b, s.range);
	}
	else if ((*b) && s.stack == 'b')
	{
		if (s.order == 'c')
			split_b_stack_sorted_asc(a, b, s.range);
		else if (s.order == 'd')
			split_b_stack_sorted_des(a, b, s.range);
	}
}
