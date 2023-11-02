/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_nothing_one_less_arg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:28:03 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 17:58:58 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_nothing_one_or_no_arg(t_pile_ab *ab)
{
	if (lst_len(ab->a) >= 2)
		return (1);
	return (0);
}
