/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:07 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/27 03:24:09 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	merge_all(t_list **a, t_list **b)
{
	int	size;
	int	tips;

	size = ft_lstsize(*b);
	tips = 3;
	while (tips <= (size / 2))
	{
		// It means we are in B
		if (ft_lstsize(*b) != 0)
		{
			while (ft_lstsize(*b) != 0)
			{
				if (*(int *)(*b)->content < *(int *)(*b)->next->content)
					merge_b_to_a_des(a, b, tips, tips);
				else
					merge_b_to_a_asc(a, b, tips, tips);
			}
		}
		else 
		{
			while  (ft_lstsize(*a) != 0)
			{
				if (*(int *)(*a)->content < *(int *)(*a)->next->content)
					merge_a_to_b_des(a, b, tips, tips);
				else
					merge_a_to_b_asc(a, b, tips, tips);
			}
		}
		tips += tips;
	}
}

//TODO: void merge manager