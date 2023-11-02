/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:27:33 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 17:58:26 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_b(t_pile_ab *ab)
{
	int	tb;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tb = find_target_b(ab);
	while (ab->b->rank != tb && tb != 0)
	{
		ab->b = ab->b->next;
		i++;
	}
	while (ab->b->next != NULL)
		ab->b = ab->b->next;
	while (ab->b->rank != tb && tb != 0)
	{
		ab->b = ab->b->previous;
		j++;
	}
	go_top(&ab->b);
	if (i > j)
		return (j);
	else
		return (i);
}

static int	cost_a(t_pile_ab *ab)
{
	int	ta;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ta = find_target(ab);
	while (ab->a->rank != ta && ta != 0)
	{
		ab->a = ab->a->next;
		i++;
	}
	while (ab->a->next != NULL)
		ab->a = ab->a->next;
	while (ab->a->rank != ta && ta != 0)
	{
		ab->a = ab->a->previous;
		j++;
	}
	go_top(&ab->a);
	if (i > j)
		return (j);
	else
		return (i);
}

int	cost(t_pile_ab *ab)
{
	int	ta;
	int	tb;
	int	i;
	int	j;

	ta = find_target(ab);
	tb = find_target_b(ab);
	i = cost_a(ab);
	j = cost_b(ab);
	if (i > j && tb != 0)
		return (1);
	else if (i < j && ta != 0)
		return (0);
	return (0);
}
