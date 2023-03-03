/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:07 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/03 19:59:54 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: I need to manage how to merge the tips;
//TODO: I need to manage in case where the number of triangles are odd;
//TODO: merge_a
//TODO: merge_b

int	merge_a(t_list **a, t_list **b, int triangles, int tips)
{
	int		l_tip;
	int		r_tip;
	int		tmp;

	tmp = triangles;
	while (triangles > 1)
	{
		r_tip = right_tip_size(a);
		if (r_tip >= tips)
			r_tip = tips;
		l_tip = left_tip_size(a);
		if (l_tip >= tips)
			l_tip = tips;
		if (*(int *)(*a)->content < *(int *)(*a)->next->content)
			merge_a_to_b_des(a, b, l_tip, r_tip);
		else
			merge_a_to_b_asc(a, b, l_tip, r_tip);
		triangles -= 2;
	}
	if (triangles == 1)
		send_a_to_b(a, b);
	return ((tmp / 2) + triangles);
}

int	merge_b(t_list **a, t_list **b, int triangles, int tips)
{
	int		l_tip;
	int		r_tip;
	int		tmp;

	tmp = triangles;
	while (triangles > 1)
	{
		r_tip = right_tip_size(b);
		if (r_tip >= tips)
			r_tip = tips;
		l_tip = left_tip_size(b);
		if (l_tip >= tips)
			l_tip = tips;
		if (*(int *)(*b)->content < *(int *)(*b)->next->content)
			merge_b_to_a_des(a, b, l_tip, r_tip);
		else
			merge_b_to_a_asc(a, b, l_tip, r_tip);
		triangles -= 2;
	}
	if (triangles == 1)
		send_b_to_a(a, b);
	return ((tmp / 2) + triangles);
}

void	merge_all(t_list **a, t_list **b)
{
	int		triangles;
	int		tips;

	tips = 3;
	// Assuming it's multiples of three;
	triangles = ft_lstsize(*b) / 3;

	while (triangles > 1)
	{
		if (ft_lstsize(*b) != 0)
			triangles = merge_b(a, b, triangles, tips);
		else
			triangles = merge_a(a, b, triangles, tips);
		tips += tips;
	}
}
