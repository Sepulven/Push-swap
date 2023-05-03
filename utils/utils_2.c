/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:50:19 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/03 22:33:35 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

void	free_matrix(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	if (array)
		free(array);
}

size_t	matrix_size(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**join_matrix(char **dst, char **src)
{
	char	**new;
	int		i;
	int		j;

	if (!dst || !src)
		return (NULL);
	new = ft_calloc(matrix_size(dst) + matrix_size(src) + 1, sizeof (char *));
	if (!new)
		return (NULL);
	i = 0;
	while (dst[i])
	{
		new[i] = ft_strdup(dst[i]);
		i++;
	}
	j = i;
	i = 0;
	while (src[i])
		new[j++] = ft_strdup(src[i++]);
	free_matrix(dst);
	free_matrix(src);
	return (new);
}

char	**normalize_argv(int argc, char **argv)
{
	int		i;
	int		j;
	char	**new;
	char	**buff;

	i = 1;
	j = 0;
	buff = NULL;
	new = ft_calloc(1, sizeof (char *));
	while (i < argc)
	{
		buff = ft_split(argv[i], ' ');
		if (buff)
			new = join_matrix(new, buff);
		i++;
	}
	return (new);
}
