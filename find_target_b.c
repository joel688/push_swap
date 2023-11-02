/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:44:57 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:02:03 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_b(t_pile_ab *ab)
{
	int		target;
	int		to_comp;
	int		ret;
	t_pile	*z;

	z = ab->b;
	target = ab->a->rank - ab->b->rank;
	ret = 0;
	while (ab->b != NULL)
	{
		to_comp = ab->a->rank - ab->b->rank;
		if (to_comp > 0 && to_comp < target)
		{
			ret = ab->b->rank;
			target = ab->a->rank - ab->b->rank;
		}
		ab->b = ab->b->next;
	}
	ab->b = z;
	go_top(&ab->b);
	return (ret);
}
