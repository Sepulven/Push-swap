/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:38:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/03 23:33:29 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	issorted(t_list **list)
{
	t_list	*tmp;

	if (!*list)
		return (0);
	tmp = *list;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	check_limit(char *num)
{
	if (ft_strlen(num) > 11)
		return (0);
	if (ft_strlen(num) <= 9)
		return (1);
	if (ft_strncmp("-2147483648", num, 12) <= 0)
		return (0);
	if (ft_strncmp("2147483647", num, 11) <= 0)
		return (0);
	return (1);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (!ft_isdigit(num[i]))
	{
		if (num[i++] != '-')
			return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i++]))
			return (0);
	}
	return (1);
}

t_list	*converter(int argc, char *argv[])
{
	t_list	*stack;
	void	*nbr;
	int		i;

	i = 0;
	stack = NULL;
	while (i < argc)
	{
		nbr = malloc(sizeof(int));
		*(int *)nbr = ft_atoi(argv[i++]);
		ft_lstadd_back(&stack, ft_lstnew(nbr));
	}
	return (stack);
}

int	validator(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*pointer;

	i = 0;
	if (argc < 1)
		return (0);
	while (i < argc)
	{
		pointer = ft_strchr(argv[i], '-');
		if (!ft_isnum(argv[i]) || !check_limit(argv[i])
			|| (pointer && !ft_isdigit(pointer[1])))
			return (0);
		j = i + 1;
		while (j < argc)
		{	
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
