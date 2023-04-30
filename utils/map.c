/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:11:09 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 22:12:03 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*reverse_map(char *map)
{
	int		i;
	int		size;
	char	*new;

	size = ft_strlen(map);
	new = malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	size--;
	while (size >= 0)
	{
		new[i] = map[size];
		size--;
		i++;
	}
	new[i] = '\0';
	if (map)
		free(map);
	return (new);
}

static char	*revert_map(char *map)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(ft_strlen(map) + 1);
	if (!new)
		return (NULL);
	while (map[i])
	{
		if (map[i] == 'd')
			new[i] = 'c';
		else if (map[i] == 'c')
			new[i] = 'd';
		i++;
	}
	new[i] = '\0';
	if (map)
		free(map);
	return (reverse_map(new));
}

static char	*normalize_odd(char *map)
{
	char	*new;
	int		i;
	int		j;
	int		size;

	if (!map)
		return (NULL);
	size = ft_strlen(map);
	i = 0;
	j = 0;
	new = (char *)malloc(size * sizeof(char));
	if (!new)
		return (NULL);
	while (i < (size / 2) - 1 && map[j])
		new[i++] = map[j++];
	j += 2;
	new[i++] = 'c';
	while (i < size - 1 && map[j])
		new[i++] = map[j++];
	new[i] = '\0';
	free(map);
	return (new);
}

char	*create_map(int num)
{
	if (num == 1)
		return (ft_strdup("c"));
	else if (num == 2)
		return (ft_strdup("dc"));
	else if (num == 3)
		return (ft_strdup("dcc"));
	else
	{
		if (num % 2 != 0)
			return (normalize_odd(create_map(num + 1)));
		else
			return (ft_strjoinf(revert_map(create_map(num / 2)), \
			create_map(num / 2)));
	}
}
