/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:23:57 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 18:04:45 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(t_pile *z)
{
	int	i;

	i = 1;
	if (z == NULL)
		return (0);
	while (z->next != NULL)
	{
		z = z->next;
		i++;
	}
	while (z->previous != NULL)
		z = z->previous;
	return (i);
}
