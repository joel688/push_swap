/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:27:05 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:31:34 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_bis(t_pile_ab *ab)
{
	while (lst_len(ab->a) != 3)
	{
		if (ab->a->rank == 1 || ab->a->rank == 2)
			pb(ab);
		ra(ab);
	}
	sort_lst_three(ab);
	if (ab->b->rank < ab->b->next->rank)
		sb(ab);
	pa(ab);
	pa(ab);
}
