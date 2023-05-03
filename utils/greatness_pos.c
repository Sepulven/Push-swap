/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatness_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:25:55 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/03 19:58:04 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

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
