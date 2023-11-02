/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:12:35 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:33:49 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile_ab *ab)
{
	t_pile	*tmp;

	if (ab->a == NULL || lst_len(ab->a) == 1)
		return ;
	tmp = ab->a;
	ab->a = ab->a->next;
	ab->a->previous = NULL;
	while (ab->a->next != NULL)
		ab->a = ab->a->next;
	ab->a->next = tmp;
	tmp->next = NULL;
	tmp = ab->a;
	ab->a = ab->a->next;
	ab->a->previous = tmp;
	go_top(&ab->a);
	write (1, "ra\n", 3);
}
