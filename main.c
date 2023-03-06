/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/06 16:34:50 by asepulve         ###   ########.fr       */
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

typedef struct s_presort
{
	void	(*sort_three_x)(t_list **, t_list **);
	void	(*sort_three_y)(t_list **, t_list **);
	void	(*merge)(t_list **, t_list **, int, int);
	t_list	**a;
	t_list	**b;
	int		*tmp;
}	t_presort;

//TODO: Create a map on how we want the the pre_sort_a_to_b; done
//TODO: Create a function that joins a string in the middle; done
//TODO: I must refactor this function
//TODO: Merge tips des and asc done

char	*ft_insert_substring(char *main, const char *sub, size_t index)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!sub || index > ft_strlen(main) - 1)
		return (NULL);
	str = (char *)malloc(ft_strlen(main) + ft_strlen(sub) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < index)
	{
		str[i] = main[i];
		i++;
	}
	j = 0;
	while (sub[j])
		str[i++] = sub[j++];
	while (main[index])
		str[i++] = main[index++];
	str[i] = '\0';
	free(main);
	return (str);
}

/*
BUG while merging:
merge_tips(3, 6); -> 15 13 8 1 4 5 6 10 14
crash!!!
*/

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
		return (write(2, "Error2\n", 7));\

	pre_sort_a_to_b(&a, &b, argc);
	merge_b_to_a_asc(&a, &b, 3, 3);
	merge_b_to_a_des(&a, &b, 3, 3);
	send_b_to_a(&a, &b);
	send_a_to_b(&a, &b);
	merge_b_to_a_asc(&a, &b, 6, 3);
	send_b_to_a(&a, &b);
	merge_a_to_b_asc(&a, &b, 6, 9);

	ft_lstclear(&a, free);
	ft_lstclear(&a, free);
	return (1);
}

/*
	ft_printf("pre_sort_a_to_b\n");
	pre_sort_a_to_b(&a, &b, argc);
	print_list(a);
	print_list(b);
	ft_printf("merge all triangles\n");
	merge_b_to_a_asc(&a, &b, 3, 3);
	merge_b_to_a_des(&a, &b, 3, 3);
	send_b_to_a(&a, &b);
	print_list(a);10
	ft_printf("merge all triangles\n");
	merge_b_to_a_asc(&a, &b, 3, 6);
	ft_printf("--------------------\n");
	print_list(a);
	print_list(b);
	send_b_to_a(&a, &b);
	print_list(a);
	print_list(b);
	ft_printf("final merge\n");
	merge_a_to_b_asc(&a, &b, 6, 9);
	print_list(a);
	print_list(b);

*/
