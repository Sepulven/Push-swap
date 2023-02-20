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


// If I pass as a argument 01 and 1 it runs; Done
// Validation to the correct moves -> check null cases; done
// Create a simple algo that sort a stack of integers using 2 stacks;
// create a simple algo that sort 3 integers under 2 moves;
// create a simple algo that sort 5 integeers under 12 moves;

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
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
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
		ft_printf("->%d ", *(int *)head->content);
		head = head->next;
	}
	ft_printf("\n");
}

void sort_three_asc(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		sa(list);

	tmp = (*list)->next;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		rra(list);
}

void sort_three_des(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (*(int *)tmp->content > *(int *)tmp->next->content)
		sa(list);

	tmp = (*list)->next;
	if (*(int *)tmp->content > *(int *)tmp->next->content)
		rra(list);
}

void sort_five(t_list **a, t_list **b)
{
	(void)b;
	(void)a;
}

void sort_temp(t_list **a, t_list **b)
{
	t_list	*temp;

	while (ft_lstsize(*a) > 0)
	{
		temp = 
		while (ft_lstsize(*b) > 0 && *(int *)(*b)->content > *(int *)temp->content)
		{
			pa(a, b);
		}
		pb(a, b);
	}
	
	while (ft_lstsize(*a) > 0 && temp->next)
	{
		if (ft_lstsize(*b) == 0)
		{	
			pb(a, b);
			temp = *a;
		}
		while (ft_lstsize(*b) > 1 && *(int *)(*b)->content > *(int *)temp->content)
		{
			pa(a, b);
			temp = *a;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	(void)b;
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	// sort_three_des(&a);
	// print_list(a);
	sort_temp(&a, &b);
	// print_list(a);
	// print_list(b);
	// sort_five(&a, &b);
	return (1);
}
