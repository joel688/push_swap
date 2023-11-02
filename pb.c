/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:09:18 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 12:07:40 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_one_elem_a(t_pile_ab *ab)
{
	t_pile	*b_first;

	b_first = ab->b;
	ab->b = ab->a;
	ab->b->next = b_first;
	b_first->previous = ab->b;
	ab->a = NULL;
}

static void	if_b_null(t_pile_ab *ab)
{
	t_pile	*tmp;

	tmp = ab->a->next;
	ab->a->next = NULL;
	ab->b = ab->a;
	ab->a = tmp;
	ab->a->previous = NULL;
}

static void	do_pb(t_pile_ab *ab)
{
	t_pile	*tmp;

	tmp = ab->b;
	if (ab->b == NULL)
		if_b_null(ab);
	else if (lst_len(ab->a) == 1)
		if_one_elem_a(ab);
	else
	{
		ab->b->previous = ab->a;
		ab->a = ab->a->next;
		ab->a->previous = NULL;
		ab->b = ab->b->previous;
		ab->b->next = tmp;
	}
}

void	pb(t_pile_ab *ab)
{
	if (ab->a == NULL)
		return ;
	do_pb(ab);
	write (1, "pb\n", 3);
}
