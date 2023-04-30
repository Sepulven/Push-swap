/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 18:09:31 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sub_stack(t_list **a, t_list **b, t_sort_n stat)
{
	int		pos;
	int		size;

	size = ft_lstsize(*b);
	while (stat.l_side + stat.r_side > 0 && size)
	{
		pos = best_el(*b, stat.l_side, stat.r_side, &stat);
		send_el_to(a, b, pos, 'a'); 
		calc_tips_size(&stat, pos, &size);
		checker(a, b, &stat, &size);
	}
}

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
	// sort_sub_stack(&a, &b, (t_sort_n){50, 50, 'b', 'g'});
	split_stack_diviser(&a, &b, (t_stat){'a', 'c', 100});
	diviser_tips(&a, &b, (t_stat){'a', 'c', 25});
	diviser_tips(&a, &b, (t_stat){'a', 'c', 25});
	diviser_tips(&a, &b, (t_stat){'b', 'd', 12});
	i = 0;
	while (i++ < 13)
		rra(&a);
	diviser_tips(&a, &b, (t_stat){'b', 'd', 13});
	diviser_tips(&a, &b, (t_stat){'b', 'd', 12});
	i = 0;
	while (i++ < 13)
		rra(&a);
	diviser_tips(&a, &b, (t_stat){'b', 'd', 13});
	diviser_tips_sorted(&a, &b, (t_stat){'b', 'c', 50});
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 12});
	// diviser_tips(&a, &b, (t_stat){'a', 'c', 24});
	// i = 0;
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 12});
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 13});
	// i = 0;
	// while (i < 12)
	// {
	// 	rra(&a);
	// 	i++;
	// }
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 13});
	// // * half of the stack 
	// diviser_tips(&a, &b, (t_stat){'b', 'c', 24});
	// diviser_tips_sorted(&a, &b, (t_stat){'b', 'c', 12});
	// diviser_tips_sorted(&a, &b, (t_stat){'b', 'c', 12});
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (1);
}

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
	