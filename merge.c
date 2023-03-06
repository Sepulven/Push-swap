/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:07 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/04 21:52:51 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: I need to manage how to merge the tips;
//TODO: I need to manage in case where the number of triangles are odd;
//TODO: merge_a
//TODO: merge_b

int	merge_a(t_list **a, t_list **b, t_stats stats)
{
	int		l_tip;
	int		r_tip;
	int		tmp;

	tmp = stats.triangles;
	while (stats.triangles > 1)
	{
		r_tip = stats.tips;
		l_tip = stats.tips;
		if (stats.side == 'r')
			r_tip = stats.diff;
		if (stats.side == 'l')
			l_tip = stats.diff; 
		if (*(int *)(*a)->content < *(int *)(*a)->next->content)
			merge_a_to_b_des(a, b, l_tip, r_tip);
		else
			merge_a_to_b_asc(a, b, l_tip, r_tip);
		stats.triangles -= 2;
		stats.diff = 0;
	}
	if (stats.triangles == 1)
		send_a_to_b(a, b);
	return ((tmp / 2) + stats.triangles);
}

int	merge_b(t_list **a, t_list **b,	t_stats stats)
{
	int		l_tip;
	int		r_tip;
	int		tmp;

	tmp = stats.triangles;
	while (stats.triangles > 1)
	{
		r_tip = stats.tips;
		l_tip = stats.tips;
		if (stats.side == 'r')
			r_tip = stats.diff;
		if (stats.side == 'l')
			l_tip = stats.diff;
		if (*(int *)(*b)->content < *(int *)(*b)->next->content)
			merge_b_to_a_des(a, b, l_tip, r_tip);
		else
			merge_b_to_a_asc(a, b, l_tip, r_tip);
		stats.triangles -= 2;
		stats.diff = 0;
	}
	if (stats.triangles == 1)
		send_b_to_a(a, b);
	return ((tmp / 2) + stats.triangles);
}

void	normalize_tip(t_list **list, void (*rrx)(t_list **), t_stats stats)
{
	int	i;

	if (left_tip_size(list) > 0)
		return ;
	i = 0;
	while (i < stats.tips)
	{
		rrx(list);
		i++;
	}
}

void	merge_all(t_list **a, t_list **b)
{
	int		triangles;
	int		tips;
	int		diff;
	char	side;

	tips = 3;
	diff = 0;
	side = 'l';
	// Assuming it's multiples of three;
	triangles = ft_lstsize(*b) / 3;
	while (triangles > 1)
	{
		if (ft_lstsize(*b) != 0)
			triangles = merge_b(a, b,(t_stats){triangles,  tips, diff, side});
		else
			triangles = merge_a(a, b,(t_stats){triangles,  tips, diff, side});
		tips += tips;
		if (triangles % 2 != 0)
		{
			diff = 3;
			if (side == 'l')
				side = 'r';
			else
				side = 'l';
		}
	}
}
