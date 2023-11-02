/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:44:27 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:35:55 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	saa(t_pile_ab *ab)
{
	t_pile	*tmp;

	if (do_nothing_one_or_no_arg(ab) == 0)
		return ;
	tmp = ab->a->next;
	ab->a->previous = ab->a->next;
	ab->a->next = tmp->next;
	tmp = tmp->next;
	tmp->previous = ab->a;
	tmp = ab->a;
	ab->a = ab->a->previous;
	ab->a->previous = NULL;
	ab->a->next = tmp;
	go_top(&ab->a);
}

static void	sbb(t_pile_ab *ab)
{
	t_pile	*tmp;

	if (do_nothing_one_or_no_arg(ab) == 0)
		return ;
	tmp = ab->b->next;
	ab->b->previous = ab->b->next;
	ab->b->next = tmp->next;
	tmp = tmp->next;
	tmp->previous = ab->b;
	tmp = ab->b;
	ab->b = ab->b->previous;
	ab->b->previous = NULL;
	ab->b->next = tmp;
	go_top(&ab->b);
}

void	ss(t_pile_ab *ab)
{
	saa(ab);
	sbb(ab);
	write (1, "ss\n", 3);
}
