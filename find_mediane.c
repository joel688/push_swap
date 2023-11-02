/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:56:24 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:37:25 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_rank(t_pile_ab *ab)
{
	t_pile	*tmp;

	tmp = ab->a;
	while (ab->a != NULL)
	{
		if (ab->a->rank == 0)
		{
			go_top(&ab->a);
			return (0);
		}
		ab->a = ab->a->next;
	}
	ab->a = tmp;
	go_top(&ab->a);
	return (1);
}

static t_pile	*find_min(t_pile_ab *ab)
{
	t_pile	*min;

	min = ab->a;
	while (min->rank != 0)
		min = min->next;
	while (ab->a->next != NULL)
	{
		if (min->number > ab->a->number && ab->a->rank == 0)
			min = ab->a;
		ab->a = ab->a->next;
	}
	if (min->number > ab->a->number && ab->a->rank == 0)
		min = ab->a;
	go_top(&ab->a);
	return (min);
}

static t_pile_ab	*del_min(t_pile_ab *ab, t_pile *min)
{
	static int	i = 1;

	if (min == NULL)
		i = 1;
	else
	{
		min->rank = i;
		i++;
	}
	return (ab);
}

void	find_mediane(t_pile_ab *ab)
{
	t_pile	*min;
	int		i;

	i = 0;
	while (i == 0)
	{
		min = find_min(ab);
		ab = del_min(ab, min);
		i = check_rank(ab);
	}
	del_min(ab, NULL);
}
