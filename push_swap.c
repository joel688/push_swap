/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:40:43 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 13:37:49 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	function_caller(t_pile_ab *ab)
{
	if (lst_len(ab->a) < 3 || lst_len(ab->a) == 4)
	{
		sort_less_three(ab);
		return ;
	}
	if (lst_len(ab->a) == 3)
	{
		sort_lst_three(ab);
		return ;
	}
	if (lst_len(ab->a) <= 5)
	{
		sort_lst_five(ab);
		return ;
	}
	if (lst_len(ab->a) < 50)
	{
		sort_less_fifty(ab);
		return ;
	}
	if (lst_len(ab->a) >= 100 && lst_len(ab->a) < 500)
		sort_hundred(ab);
	else
		sort(ab);
}

void	*push_swap(int argc, char **argv)
{
	int			i;
	t_pile_ab	*ab;

	i = is_error(argc, argv);
	if (i == 0)
		return (0);
	ab = do_pile_a(argc, argv);
	find_mediane(ab);
	go_top(&ab->a);
	function_caller(ab);
	freelst(ab);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	push_swap(argc, argv);
	// system("leaks push_swap");
	return (0);
}
