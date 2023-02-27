/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:07 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/27 00:37:31 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	merge_all(t_list **a, t_list **b)
{
	int	size;

	(void)a;
	(void)b;
	size = ft_lstsize(*b);
	while (size > 0)
	{
		// merge_a_to_b_asc(a, b, 3, 3);
		size -= 6;
	}
}

//TODO: void merge manager