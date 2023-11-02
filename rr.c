/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:49:16 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:34:43 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	raa(t_pile_ab *ab)
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
}

static void	rbb(t_pile_ab *ab)
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
}

void	rr(t_pile_ab *ab)
{
	if (ab->a == NULL || ab->b == NULL)
		return ;
	raa(ab);
	rbb(ab);
	write (1, "rr\n", 3);
}
