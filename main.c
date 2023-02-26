/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/26 05:23:58 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
	Always NULL terminate popped nodes or linked lists.
*/

// If I pass as a argument 01 and 1 it runs; Done
// Validation to the correct moves -> check null cases; done
// Create a simple algo that sort a stack of integers using 2 stacks; done
// create a simple algo that sort 3 integers under 2 moves; done
// Free the list;
// Organize the code;
// create a simple algo that sort 5 integeers under 12 moves;

void sort_temp(t_list **a, t_list **b)
{
	t_list	*temp;

	while (ft_lstsize(*a) > 0)
	{
		temp = *a;
		ra(a);
		while (ft_lstsize(*b) != 0 && *(int *)temp->content > *(int *)(*b)->content)
		{
			pa(a, b);
		}
		rra(a);
		pb(a, b);
	}
	
}

// Regardless of the size of the list I always want to pre sort everything;

void	pre_sort_a_to_b(t_list **a, t_list **b, int size)
{
	int tmp;

	tmp = size;
	while (ft_lstsize(*a) != 0)
	{
		if (tmp - 3 == 1)
		{
			sort_three_asc(a, b);
			pb(a, b);
			rb(b);
			print_list(*b);
			merge_tips(b, a, 3, 1);
		}
		else if (tmp - 3 == 2)
		{
			sort_three_asc(a, b);
			if (*(int *)(*a)->content > *(int *)(*a)->next->content)
				sa(a);
			pb(a, b);
			pb(a, b);
			rb(b);
			rb(b);
			merge_tips(a, b, 3 , 2);
		}
		else if (tmp > (size / 2))
			sort_three_des(a, b);
		else
			sort_three_asc(a, b);
		tmp -= 3;
	}
}

// void merge_all(t_list **a, t_list **b)
// {
	
// }

int	main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	// pre_sort_a_to_b(&a, &b, argc - 1);
	// print_list(a);
	merge_tips(&a, &b, 1, 3);
	print_list(a);
	print_list(b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (1);
}
