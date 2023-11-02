/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:29:44 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:35:44 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_two(t_pile_ab *ab, t_pile *tmp)
{
	ab->b->previous = tmp;
	ab->b->next = NULL;
	ab->b = tmp;
	ab->b->next = ab->b->previous;
	ab->b->previous = NULL;
}

void	sb(t_pile_ab *ab)
{
	t_pile	*tmp;

	if (do_nothing_one_or_no_arg(ab) == 0)
		return ;
	tmp = ab->b->next;
	if (lst_len(ab->b) == 2)
	{
		for_two(ab, tmp);
	}
	else
	{
		ab->b->previous = ab->b->next;
		ab->b->next = tmp->next;
		tmp = tmp->next;
		tmp->previous = ab->b;
		tmp = ab->b;
		ab->b = ab->b->previous;
		ab->b->previous = NULL;
		ab->b->next = tmp;
	}
	go_top(&ab->b);
	write (1, "sb\n", 3);
}
