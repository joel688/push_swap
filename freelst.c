/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:18:25 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:02:53 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freelst(t_pile_ab *ab)
{
	t_pile	*z;

	z = ab->a;
	while (ab->a != NULL)
	{
		z = ab->a->next;
		free(ab->a);
		ab->a = z;
	}
	free(ab);
}
