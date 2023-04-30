/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 13:14:41 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		lst_size;
	int		i;

	a = NULL;
	b = NULL;
	(void)lst_size;
	(void)i;
	(void)b;
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	split_stack_diviser(&a, &b, (t_stat){'a', 'd', argc - 1});
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (1);
}

	// diviser_to_tips(&a, &b, 25, 'a');
	// diviser_to_tips(&a, &b, 25, 'a');
	// diviser_to_tips(&a, &b, 13, 'b');
	// diviser_to_tips(&a, &b, 13, 'b');
	// diviser_to_tips(&a, &b, 25, 'b');
	// i = 0;
	// while (i < 25)
	// {
	// 	send_el_to_top(&a, &b, ft_lstsize(a) - 1, 'a');
	// 	i++;
	// }
	// diviser_to_tips(&a, &b, 25, 'b');
	// diviser_tips_sorted(&a, &b, 50, 'b');
	