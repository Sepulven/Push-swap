/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tips_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:40:48 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 15:48:38 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**create_tips_map(int el)
{
	char	**map;
	int		i;

	map = ft_calloc(el + 1, sizeof (char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < el)
		map[i++] = ft_calloc(5 + 1, sizeof (char));
	return (map);
}

char	**tips_map(char **map)
{
	char	**new;
	int		i;
	int		len_map;
	int		len_new;

	if (!map)
		return (NULL);
	len_map = 0;
	while (map[len_map])
		len_map++;
	len_new = len_map / 2 + (len_map % 2 != 0);
	new = ft_calloc(len_new + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < (len_map / 2))
		new[i] = ft_itoa(ft_atoi(map[i]) + ft_atoi(map[len_map - i - 1]));
	if (i < len_new)
		new[i] = ft_strdup(map[i]);
	while (len_map > 0)
		free(map[len_map--]);
	free(map);
	return (ft_protectmatrix(new, len_new));
}
