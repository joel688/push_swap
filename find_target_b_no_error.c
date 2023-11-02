/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b_no_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:41:59 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:02:28 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	good_top_a(t_pile_ab *ab, int target)
{
	int	move;

	move = best_move(ab->a, target);
	while (ab->a->rank != target)
	{
		if (move == 0)
			ra(ab);
		else
			rra(ab);
	}
}

int	find_target_b_no_error(t_pile_ab *ab)
{
	t_pile	*z;
	int		to_comp;
	int		target;
	int		ret;
	int		for_good_top;

	z = ab->a;
	ret = find_target_b(ab);
	for_good_top = ab->a->rank;
	target = ab->a->rank - ret;
	while (ab->a != NULL)
	{
		to_comp = ab->a->rank - ret;
		if (to_comp > 0 && to_comp < target)
		{
			for_good_top = ab->a->rank;
			target = ab->a->rank - ret;
		}
		ab->a = ab->a->next;
	}
	ab->a = z;
	go_top(&ab->a);
	good_top_a(ab, for_good_top);
	return (ret);
}
