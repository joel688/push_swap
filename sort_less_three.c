/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:18:46 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 13:37:20 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_lst_four(t_pile_ab *ab)
{
	while (lst_len(ab->b) != 1)
	{
		if (ab->a->rank == 1)
			pb(ab);
		else
			ra(ab);
	}
	sort_lst_three(ab);
	pa(ab);
}

void	sort_less_three(t_pile_ab *ab)
{
	if (lst_len(ab->a) == 1)
		return ;
	if (lst_len(ab->a) == 4)
		sort_lst_four(ab);
	else if (ab->a->rank > ab->a->next->rank)
		sa(ab);
}
