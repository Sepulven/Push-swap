/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:44:17 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/10 22:42:14 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_a_to_b(t_list **a, t_list **b, int size)
{
	int		i;
	char	*map;

	map = create_map(size);
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

// d -> decrescent
// c -> crescent
char	*map_pre_sort(int size)
{
	char	*map;
	int		triangles;
	int		flag;

	map = (char *)malloc((size / 3)* sizeof(char));
	if (!map)
		return (NULL);
	triangles = (size / 3);
	flag = -1;
	while (triangles > 0)
	{
		if (triangles == 1)
		{
			if (map[0] == 'd')
				map = ft_insert_substring(map, "c", ft_strlen(map) / 2);
			else if (map [0] == 'c')
				map = ft_insert_substring(map, "d", ft_strlen(map) / 2);
			break ;
		}
		if (flag < 0)
			map = ft_insert_substring(map, "dc", ft_strlen(map) / 2);
		else
			map = ft_insert_substring(map, "cd", ft_strlen(map) / 2);
		flag *= -1;
		triangles -= 2;
	}
	ft_printf("%s\n", map);
	return (map);
}
