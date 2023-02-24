/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/24 16:04:12 by asepulve         ###   ########.fr       */
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


void	sort_five_asc(t_list **list)
{
	if ((*list)->next < (*list)->next->next)
		return ;
}

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
	merge_tips(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (1);
}
