/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:37:20 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/11 14:50:22 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

void handler_a(t_list	**a, t_list	**b, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(operation, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(operation, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(a);
}

void handler_b(t_list	**a, t_list	**b, char *operation)
{
	if (!ft_strncmp(operation, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(b);
}

void handler_ab(t_list	**a, t_list	**b, char *operation)
{
	if (!ft_strncmp(operation, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(a, b);
}

int checker(t_list	**a, t_list	**b)
{
	char *line;
	
	(void)a;
	(void)b;
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, "sa\n", 3) || !ft_strncmp(line, "pa\n", 3) \
		|| !ft_strncmp(line, "ra\n", 3) || !ft_strncmp(line, "rra\n", 4))
			handler_a(a, b, line);
		if (!ft_strncmp(line, "sb\n", 3) || !ft_strncmp(line, "pb\n", 3) \
		|| !ft_strncmp(line, "rb\n", 3) || !ft_strncmp(line, "rrb\n", 4))
			handler_b(a, b, line);
		if (!ft_strncmp(line, "rr\n", 3) || !ft_strncmp(line, "rrr\n", 3))
			handler_ab(a, b, line);
		line = get_next_line(0);
	}
	if (!issorted(a))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	if (!checker(&a, &b))
		return (write(2, "KO\n", 3));
	else
		return (write(2, "OK\n", 3));
	return (0);
}