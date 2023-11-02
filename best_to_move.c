/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_to_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:59:57 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 12:10:36 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_to_move(t_pile *z, int j, int i)
{
	int	beg;
	int	end;

	beg = 0;
	end = 0;
	while ((z->rank < j || z->rank > i) && z->next != NULL)
	{
		z = z->next;
		beg++;
	}
	go_top(&z);
	while (z->next != NULL)
		z = z->next;
	while ((z->rank < j || z->rank > i) && z->previous != NULL)
	{
		z = z->previous;
		end++;
	}
	go_top(&z);
	if (beg > end)
		return (0);
	else
		return (1);
}
