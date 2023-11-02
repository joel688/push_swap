/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:32:15 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:33:59 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_pile_ab *ab)
{
	t_pile	*tmp;

	if (ab->b == NULL || lst_len(ab->b) == 1)
		return ;
	tmp = ab->b;
	ab->b = ab->b->next;
	ab->b->previous = NULL;
	while (ab->b->next != NULL)
		ab->b = ab->b->next;
	ab->b->next = tmp;
	tmp->next = NULL;
	tmp = ab->b;
	ab->b = ab->b->next;
	ab->b->previous = tmp;
	go_top(&ab->b);
	write (1, "rb\n", 3);
}
