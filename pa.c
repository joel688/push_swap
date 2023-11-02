/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:35:19 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 12:07:47 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_one_elem_b(t_pile_ab *ab)
{
	t_pile	*a_first;

	a_first = ab->a;
	ab->a = ab->b;
	ab->a->next = a_first;
	a_first->previous = ab->a;
	ab->b = NULL;
}

static void	if_a_null(t_pile_ab *ab)
{
	t_pile	*tmp;

	tmp = ab->b->next;
	ab->b->next = NULL;
	ab->a = ab->b;
	ab->b = tmp;
	ab->b->previous = NULL;
}

static void	do_pa(t_pile_ab *ab)
{
	t_pile	*tmp;

	tmp = ab->a;
	if (ab->a == NULL)
		if_a_null(ab);
	else if (lst_len(ab->b) == 1)
		if_one_elem_b(ab);
	else
	{
		ab->a->previous = ab->b;
		ab->b = ab->b->next;
		ab->b->previous = NULL;
		ab->a = ab->a->previous;
		ab->a->next = tmp;
	}
}

void	pa(t_pile_ab *ab)
{
	if (ab->b == NULL)
		return ;
	do_pa(ab);
	write (1, "pa\n", 3);
}
