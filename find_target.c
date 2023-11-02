/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:39:57 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:01:20 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_pile_ab *ab)
{
	int		target;
	int		to_comp;
	int		ret;
	t_pile	*z;

	z = ab->a;
	target = ab->b->rank - ab->a->rank;
	ret = ab->a->rank;
	while (ab->a != NULL)
	{
		to_comp = ab->b->rank - ab->a->rank;
		if ((to_comp > target && to_comp < 0) || (target > 0 && to_comp < 0))
		{
			ret = ab->a->rank;
			target = ab->b->rank - ab->a->rank;
		}
		ab->a = ab->a->next;
	}
	ab->a = z;
	go_top(&ab->a);
	return (ret);
}
