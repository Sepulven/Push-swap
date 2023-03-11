/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:44:17 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/11 19:24:28 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_a_to_b(t_list **a, t_list **b, int size)
{
	int		i;
	char	*map;

	map = create_map(size, "");
	if (!map)
		return ;
	i = ft_strlen(map) - 1;
	while (i >= 0)
	{
		if (map[i] == 'd')
			sort_three_asc(a, b);
		if (map[i] == 'c')
			sort_three_des(a, b);
		i--;
	}
}
