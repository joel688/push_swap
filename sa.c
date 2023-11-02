/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:03 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:35:32 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_two(t_pile_ab *ab, t_pile *tmp)
{
	ab->a->previous = tmp;
	ab->a->next = NULL;
	ab->a = tmp;
	ab->a->next = ab->a->previous;
	ab->a->previous = NULL;
}

void	sa(t_pile_ab *ab)
{
	t_pile	*tmp;

	if (do_nothing_one_or_no_arg(ab) == 0)
		return ;
	tmp = ab->a->next;
	if (lst_len(ab->a) == 2)
	{
		for_two(ab, tmp);
	}
	else
	{
		ab->a->previous = ab->a->next;
		ab->a->next = tmp->next;
		tmp = tmp->next;
		tmp->previous = ab->a;
		tmp = ab->a;
		ab->a = ab->a->previous;
		ab->a->previous = NULL;
		ab->a->next = tmp;
	}
	go_top(&ab->a);
	write (1, "sa\n", 3);
}
