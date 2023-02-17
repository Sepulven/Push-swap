/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/17 15:55:20 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list *converter(int argc, char *argv[])
{
	t_list	*stack;
	void	*nbr;
	int		i;

	i = 1;
	nbr = malloc(sizeof(int));
	*(int *)nbr = ft_atoi(argv[i++]);
	stack = ft_lstnew(nbr);
	while (i < argc)
	{
		nbr = malloc(sizeof(int));
		*(int *)nbr = ft_atoi(argv[i++]);
		ft_lstadd_back(&stack, ft_lstnew(nbr));
	}
	return (stack);
}

int	check_limit(char *num)
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

int	validator(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!ft_isnum(argv[i]) || !check_limit(argv[i]))
			return (0);
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strncmp(argv[i], argv[j], 12))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void print_list(t_list *head)
{
	while (head)
	{
		ft_printf("->%d \n", *(int *)head->content);
		head = head->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list *a;
	
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	print_list(a);
	return (1);
}
