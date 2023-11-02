/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:41:52 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:35:06 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_pile_ab *ab)
{
	t_pile	*cell_a;
	t_pile	*penultimate;

	cell_a = ab->b;
	if (ab->b == NULL || lst_len(ab->b) == 1)
		return ;
	while (ab->b->next != NULL)
		ab->b = ab->b->next;
	ab->b->next = cell_a;
	penultimate = ab->b->previous;
	penultimate->next = NULL;
	ab->b->previous = NULL;
	cell_a->previous = ab->b;
	write (1, "rrb\n", 4);
}
