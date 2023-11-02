/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:22 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:35:17 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrbb(t_pile_ab *ab)
{
	t_pile	*cell_a;
	t_pile	*penultimate;

	cell_a = ab->b;
	while (ab->b->next != NULL)
		ab->b = ab->b->next;
	ab->b->next = cell_a;
	penultimate = ab->b->previous;
	penultimate->next = NULL;
	ab->b->previous = NULL;
	cell_a->previous = ab->b;
}

static void	rraa(t_pile_ab *ab)
{
	t_pile	*cell_a;
	t_pile	*penultimate;

	cell_a = ab->a;
	while (ab->a->next != NULL)
		ab->a = ab->a->next;
	ab->a->next = cell_a;
	penultimate = ab->a->previous;
	penultimate->next = NULL;
	ab->a->previous = NULL;
	cell_a->previous = ab->a;
}

void	rrr(t_pile_ab *ab)
{
	if (ab->a == NULL || ab->b == NULL)
		return ;
	rraa(ab);
	rrbb(ab);
	write (1, "rrr\n", 4);
}
