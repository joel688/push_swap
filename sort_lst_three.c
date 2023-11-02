/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:23:44 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:06 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_lst_three(t_pile_ab *ab)
{
	t_pile	*o;
	t_pile	*t;
	t_pile	*d;

	o = ab->a;
	t = ab->a->next;
	d = ab->a->next->next;
	if (o->rank < t->rank && t->rank > d->rank && o->rank < d->rank)
	{
		sa(ab);
		ra(ab);
	}
	else if (o->rank > t->rank && o->rank < d->rank && t->rank < d->rank)
		sa(ab);
	else if (o->rank < t->rank && o->rank > d->rank && t->rank > d->rank)
		rra(ab);
	else if (o->rank > t->rank && o->rank > d->rank && t->rank > d->rank)
	{
		sa(ab);
		rra(ab);
	}
	else if (o->rank > t->rank && o->rank > d->rank && t->rank < d->rank)
	{
		ra(ab);
	}
}
