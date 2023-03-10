/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:11:09 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/10 22:36:12 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char *reverse_map(char *map)
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
		size--; i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*revert_map(char *map)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	new = malloc(ft_strlen(map) + 1);
	while (map[i])
	{
		if (map[i] == 'd')
			new[i] = 'c';
		else if (map[i] == 'c')
			new[i] = 'd';
		i++;
	}
	new[i] = '\0';
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
	new = (char *)malloc(i * sizeof(char));
	if (!new)
		return (NULL);
	while (i < (size / 2) - 1)
		new[i++] = map[j++];
	new[i++] = 'c';
	j += 2;
	while (i < size - 1)
		new[i++] = map[j++];
	new[i] = '\0';
	free(map);
	return (new);
}

char	*create_map(int	num, char *map)
{
	if (num == 1)
		return (ft_strjoin("c", map));
	else if (num == 2)
		return (ft_strjoin("dc", map));
	else if (num == 3)
		return (ft_strjoin("ddc", map));
	else
	{
		if (num % 2 != 0)
			return (normalize_odd(create_map(num + 1, map)));
		else
			return (create_map(num / 2, revert_map(create_map(num / 2, map))));
	}
}
