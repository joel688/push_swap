/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:55:11 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:34:43 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_move(t_pile *z, int tofind)
{
	int	i;
	int	size;

	i = 0;
	size = lst_len(z);
	while (tofind != 0 && z->rank != tofind)
	{
		z = z->next;
		i++;
	}
	if (i > size / 2 && tofind != 2)
	{
		go_top(&z);
		return (1);
	}
	else
	{
		go_top(&z);
		return (0);
	}
}
