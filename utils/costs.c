/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:40:55 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 15:52:05 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

// * Basei se no algo. utilizado pelo send_el_to
int	cost_send(int lst_size, int pos)
{
	if (lst_size < 0)
	{
		ft_printf("List size can't be negative.");
		exit(EXIT_FAILURE);
	}
	if (pos < (lst_size - 1) / 2)
		return (pos + 2);
	else
		return ((lst_size - 1) - pos + 2);
}

/*
	* Encontra o melhor el. para enviar baseando si no custo;
	* Seria interessante caso no momento de enviar eu soubesse precisamente o que vai acontecer no stack se tivesse
	*( Um destes precisa ter prioridade sobre o outro )
	* A prioridade deve encontrar-se naquele que melhor meche a stack para pos mais favoravel do conseguinte.
	* Pois há cenarios a onde o custo dos 3 podem ser iguais.
	* Dado a situação a onde eu precisaria fazer mais comparações dentro da 
	* função, farei uso desta ferramenta para um optimização mais tardia caso necessário.
		* //  Darei a prioridade para o maior e o segundo maior.
*/
int	best_el(t_list *lst, int l_pos, int r_pos, t_sort_n *stat)
{
	int	pos[4];
	int	cost[4];
	int	lst_size;

	lst_size = ft_lstsize(lst);
	pos[0] = get_nth_greatness_pos(lst, l_pos, r_pos, 1);
	pos[1] = get_nth_greatness_pos(lst, l_pos, r_pos, l_pos + r_pos - 1);
	pos[2] = get_nth_greatness_pos(lst, l_pos, r_pos, l_pos + r_pos);
	pos[3] = get_nth_greatness_pos(lst, l_pos, r_pos, 2);
	cost[0] = cost_send(lst_size, pos[0]) + 2;
	cost[1] = cost_send(lst_size, pos[1]) + 1;
	cost[2] = cost_send(lst_size, pos[2]);
	cost[3] = cost_send(lst_size, pos[3]) + 2; // * Possui o mesmo custo na hora de enviar, entretanto não possui a mesma prioridade.
	stat->greatness = 'g';
	if (cost[0] < cost[1] && cost[0] < cost[2] && cost[0] <= cost[3])
	{
		stat->greatness = 's';
		return (pos[0]);
	}
	else if (cost[1] <= cost[0] && cost[1] < cost[2] && cost[1] <= cost[3])
	{
		stat->greatness = '2';
		return (pos[1]);
	}
	else if (cost[3] < cost[0] && cost[3] < cost[1] && cost[3] < cost[2])
	{
		stat->greatness = 'S';
		return (pos[3]);
	}
	return (pos[2]);
}

// * Aplica a mesma logica antes vista pelo sort_n
void	calc_tips_size(t_sort_n *stat, int pos, int *size)
{
	if (pos < stat->l_side) // * Left
	{
		stat->r_side += pos;
		stat->l_side -= pos;
	}
	else if (pos >= *size - stat->r_side) // * Right
	{
		stat->l_side = stat->l_side + (*size - pos);
		stat->r_side = stat->r_side - (*size - pos);
	}
	(*size)--;
	stat->l_side--;
}
