/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:27:33 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:34:54 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile_ab *ab)
{
	t_pile	*cell_a;
	t_pile	*penultimate;

	cell_a = ab->a;
	if (ab->a == NULL)
		return ;
	while (ab->a->next != NULL)
		ab->a = ab->a->next;
	ab->a->next = cell_a;
	penultimate = ab->a->previous;
	penultimate->next = NULL;
	ab->a->previous = NULL;
	cell_a->previous = ab->a;
	write (1, "rra\n", 4);
}
