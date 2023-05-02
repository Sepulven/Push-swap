/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:35:35 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 02:27:49 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

int	*populate_arr(t_list *lst, int range)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(range * sizeof (int));
	if (!arr)
		return (NULL);
	i = 0;
	while (lst && i < range)
	{
		arr[i] = *(int *)lst->content;
		lst = lst->next;
		i++;
	}
	return (arr);
}

static void	err(int *buff)
{
	free(buff);
	ft_printf("Couldn't allocate the buffer.");
	exit(EXIT_FAILURE);
}

static void	sort_arr(int *buff, int range)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!buff)
		return ;
	while (i < range - 1)
	{
		j = 0;
		while (j < range - 1)
		{
			if (buff[j] > buff[j + 1])
				ft_swap(&buff[j], &buff[j + 1]);
			j++;
		}
		i++;
	}
}

int	diviser_value(t_list *lst, int range)
{
	int	*buff;
	int	i;

	buff = populate_arr(lst, range);
	if (!buff)
		err(buff);
	sort_arr(buff, range);
	i = (range - 1) / 2;
	range = buff[i];
	free(buff);
	return (range);
}

int	sub_diviser_value(t_list *lst, int range)
{
	int	*buff;
	int	i;

	buff = populate_arr(lst, range);
	if (!buff)
		err(buff);
	sort_arr(buff, range);
	range = (range - 1) / 2;
	i = range / 2;
	range = buff[i];
	free(buff);
	return (range);
}
