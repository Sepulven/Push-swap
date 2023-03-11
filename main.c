/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/11 20:32:31 by asepulve         ###   ########.fr       */
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
//TODO: Create a map on how we want the the pre_sort_a_to_b; done
//TODO: Create a function that joins a string in the middle; done
//TODO: I must refactor this function
//TODO: Merge tips des and asc done


int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	(void)a;
	(void)b;
	a = NULL;
	b = NULL;
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	// print_list(a);
	// print_list(b);
	// print_list(a);
	// print_list(b);
	// sort_three_des(&a, &b);
	// print_list(a);
	// print_list(b);
	pre_sort_a_to_b(&a, &b, argc - 1);

	// ft_printf("\n\n Pre sort done! \n\n");
	// print_list(b);
	// ft_printf("\n\n Starting merge all! \n\n");
	merge_all(&a, &b);
	// sort_three_asc(&a, &b);
	// sort_three_asc(&a, &b);
	// sort_three_asc(&a, &b);
	// sort_three_asc(&a, &b);
	// print_list(a);
	// print_list(b);
	//1 6 14 2 11 12 8 15 13 3 9 7
	ft_lstclear(&a, free);
	ft_lstclear(&a, free);
	return (1);
}
