/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/27 02:30:31 by asepulve         ###   ########.fr       */
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
// Free the list; done
// Organize the code; done
// create a simple algo that sort 5 integeers under 12 moves

//TODO: Regardless of the size of the list I always want to pre sort everything; done

//TODO: I must refactor this function
//TODO: Merge tips des and asc done
void	pre_sort_a_to_b(t_list **a, t_list **b, int size)
{
	int tmp;
	
	tmp = size;
	while (tmp > 0)
	{
		if (tmp - 3 == 1)
		{
			sort_three_asc(a, b);
			pb(a, b);
			rb(b);
			merge_b_to_a_asc(a, b, 3, 1);
			tmp -= 4;
		}
		else if (tmp - 3 == 2)
		{
			sort_three_asc(a, b);
			if (*(int *)(*a)->content > *(int *)(*a)->next->content)
				sa(a);
			pb(a, b);
			pb(a, b);
			merge_b_to_a_asc(a, b, 2, 3);
			tmp -= 5;
		}
		else if (tmp > 0 && tmp%2 == 0)
			sort_three_des(a, b);
		else if (tmp > 0)
			sort_three_asc(a, b);
		tmp -= 3;
	}
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
	// ft_printf("argc: %d\n", argc - 1);
	pre_sort_a_to_b(&a, &b, argc - 1);
	merge_b_to_a_asc(&a, &b, 3, 3);
	merge_all(&a, &b);
	// merge_a_to_b_des(&a, &b, 3, 3);
	// merge_b_to_a_asc(&a, &b, 6, 6);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (1);
}
