/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/03 13:03:58 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sub_stack(t_list **a, t_list **b, t_sort_n stat)
{
	int		pos;
	int		r_a_tip;

	r_a_tip = 0;
	while (stat.l_side + stat.r_side > 1 && stat.size)
	{
		pos = best_el(*b, stat.l_side, stat.r_side, &stat);
		send_el_to(a, b, pos, 'a');
		calc_tips_size(&stat, pos);
		checker(a, b, &stat, &r_a_tip);
	}
	pa(a, b);
	while (r_a_tip-- > 0)
		rra(a);
}

// ! Falta me verificar se o lado da esquerda calhou um número ímpar
// * Acho que isto ja esta feito dado que 
void	init_stacks_size(int *range, int size)
{
	// * Supostamente devo colocar na ordem em que vamos utilizando.
	// * Para duas stack devemos ter aproxidamente 2 + 4 + 8 ranges.
	// * Dois primeiros stacks
	range[0] = size / 2; // * Numeros pares terão parte menor
	range[1] = size / 2 + (size % 2 != 0);
	// * Os quatros do meio
	range[2] = range[0] / 2;
	range[3] = range[0] / 2 + (range[0] % 2 != 0);
	range[4] = range[1] / 2;
	range[5] = range[1] / 2 + (range[1] % 2 != 0);
	// * Os oito ultimos
	range[6] = range[2] / 2;
	range[7] = range[2] / 2 + (range[2] % 2 != 0);
	range[8] = range[3] / 2;
	range[9] = range[3] / 2 + (range[3] % 2 != 0);
	range[10] = range[4] / 2;
	range[11] = range[4] / 2 + (range[4] % 2 != 0);
	range[12] = range[5] / 2;
	range[13] = range[5] / 2 + (range[5] % 2 != 0);
}

void	push_swap(t_list **a, t_list **b, int size)
{
	int	i;
	int	range[14];

	(void)i;
	(void)range;
	init_stacks_size(range, size);
	split_stack_diviser(a, b, (t_stat){'a', 'c', size});
	diviser_tips(a, b, (t_stat){'a', 'c', range[4]});
	diviser_tips(a, b, (t_stat){'a', 'c', range[5]});
	diviser_tips(a, b, (t_stat){'b', 'd', range[10]});
	i = 0;
	while (i++ < range[11])
		rra(a);
	diviser_tips(a, b, (t_stat){'b', 'd', range[11]});
	diviser_tips(a, b, (t_stat){'b', 'd', range[12]});
	i = 0;
	while (i++ < range[13])
		rra(a);
	diviser_tips(a, b, (t_stat){'b', 'd', range[13]});
	split_stack_diviser(a, b, (t_stat){'a', 'c', range[0]});
	diviser_tips_sorted(a, b, (t_stat){'b', 'c', range[2]});
	sort_sub_stack(a, b, (t_sort_n){size, 0, 'b', 'g', ft_lstsize(*b)});
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
		return (write(2, "Error\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error\n", 7));
	if (argc - 1 == 2 && !issorted(&a))
		sa(&a);
	if (argc - 1 < 50 && argc - 1 > 2)
		sort_n_own_stack(&a, &b);
	else if (argc - 1 > 50)
		push_swap(&a, &b, argc - 1);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
