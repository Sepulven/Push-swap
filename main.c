/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/08 23:50:04 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	* 1:	Check num;
	* 2:	Check duplicate;
	* 3:	Change to int;
	* 4:	Pass to the stack;
	* 5:	Check limit of integer
*/

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

int	check_limits(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (nums[i][0] == '-' && ft_strlen(nums[i]) > 10 && ft_strncmp("-2147483648", nums[i], 12) < 0)
			return (0);
		else if ((ft_strlen(nums[i]) > 9 && ft_strncmp("2147483647", nums[i], 11) < 0) || (nums[i][0] != '-' && ft_strlen(nums[i]) > 10))
			return (0);
		i++;
	}
	return (1);
}

int	validator(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2 || !check_limits(&argv[1]))
		return (0);
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
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

int	main(int argc, char *argv[])
{
	t_list *a;
	
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	while (a)
	{
		ft_printf("->%d \n", *(int *)a->content);
		a = a->next;
	}
	return (1);
}
