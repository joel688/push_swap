/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:26:22 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 13:23:39 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	on_a(t_pile_ab *ab)
{
	int	move;
	int	target;

	target = find_target(ab);
	move = best_move(ab->a, target);
	while (ab->a->rank != target)
	{
		if (move == 0)
			ra(ab);
		else
			rra(ab);
	}
	pa(ab);
}

static void	on_b(t_pile_ab *ab)
{
	int	move;
	int	target;

	target = find_target_b_no_error(ab);
	move = best_move(ab->b, target);
	while (ab->b->rank != target && target != 0)
	{
		if (move == 0)
			rb(ab);
		else
			rrb(ab);
	}
	pa(ab);
}

static void	all_back_a(t_pile_ab *ab)
{
	int	target;
	int	i;
	int	stack_choice;

	i = 0;
	while (ab->b != NULL)
	{
		stack_choice = cost(ab);
		if (stack_choice == 0 && ab->b != NULL)
			on_a(ab);
		else
			on_b(ab);
	}
}

static void	push_half(t_pile_ab *ab, int i, int j, int k)
{
	int	move;

	k = lst_len(ab->a);
	i = k / 4;
	j = 5;
	while (lst_len(ab->a) != 5)
	{
		move = best_to_move(ab->a, j, i);
		while (ab->a->rank < j || ab->a->rank > i)
		{
			if (move == 1)
				ra(ab);
			else
				rra(ab);
		}
		pb(ab);
		if (lst_len(ab->b) == i - 4)
		{
			j = i + 1;
			i += k / 4;
		}
		if (i >= k)
			i = k - 1;
	}
}

void	sort_hundred(t_pile_ab *ab)
{
	int	move;
	int	i;
	int	j;
	int	k;

	push_half(ab, i, j, k);
	sort_five_bis(ab);
	while (ab->b != NULL)
		all_back_a(ab);
	move = best_move(ab->a, 1);
	while (ab->a->rank != 1)
	{
		if (move == 0)
			ra(ab);
		else
			rra(ab);
	}
}
