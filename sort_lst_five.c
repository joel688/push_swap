/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:48:26 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:35:09 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_lst_five(t_pile_ab *ab)
{
	while (lst_len(ab->b) != 2)
	{
		if (ab->a->rank == 1 || ab->a->rank == 2)
			pb(ab);
		else
			ra(ab);
	}
	if (ab->b->rank < ab->b->next->rank)
		sb(ab);
	sort_lst_three(ab);
	pa(ab);
	pa(ab);
}
