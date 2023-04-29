/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatness.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:36:21 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 15:49:50 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	*create_sub_stack(t_list *lst, int l_side, int r_side)
{
	int	lst_size;
	int	i;
	int	index_holder;
	int	*stack;

	lst_size = ft_lstsize(lst);
	stack = malloc((l_side + r_side) * sizeof (int));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < l_side && lst)
	{
		stack[i++] = *(int *)lst->content;
		lst = lst->next;
	}
	index_holder = i;
	while (i < lst_size - r_side && lst)
	{
		lst = lst->next;
		i++;
	}
	while (i < lst_size && lst)
	{
		stack[index_holder++] = *(int *)lst->content;
		i++;
		lst = lst->next;
	}
	return (stack);
}

/*
	* Retorna o valor de tamanha grantitude.
*/
int	get_nth_greatness_value(t_list *lst, int l_side, int r_side, int greatness)
{
	int	i;
	int	j;
	int	*sub_stack;

	if (greatness - 1 > l_side + r_side || greatness < 0)
	{
		ft_printf("Greatness out of range.\n");
		exit(EXIT_FAILURE);
	}
	sub_stack = create_sub_stack(lst, l_side, r_side);
	if (!sub_stack)
	{
		ft_printf("We couldn't create the sub_stack");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < l_side + r_side)
	{
		j = 0;
		while (j < l_side + r_side - 1)
		{
			if (sub_stack[j] > sub_stack[j + 1])
				ft_swap(&sub_stack[j], &sub_stack[j + 1]);
			j++;
		}
		i++;
	}
	j = sub_stack[greatness - 1];
	free(sub_stack);
	return (j);
}

/*
	* Nos basicamente queremos a posicao do el., recebemos a grandeza do elemento 
	* dentro do do sub_stack e retornamos a posição dentro do stack principal.
*/
int	get_nth_greatness_pos(t_list *lst, int l_side, int r_side, int greatness)
{
	int	value;
	int	pos;

	value = get_nth_greatness_value(lst, l_side, r_side, greatness);
	pos = 0;
	while (lst)
	{
		if (value == *(int *)lst->content)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (-1);
}
