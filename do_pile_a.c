/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pile_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:28:34 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 13:18:25 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*new_node(char *number)
{
	t_pile	*cell;

	cell = malloc(sizeof(t_pile));
	if (cell == NULL)
		return (NULL);
	cell->number = (int)ft_atoi(number);
	cell->next = NULL;
	cell->rank = 0;
	return (cell);
}

static t_pile	*add_back(t_pile *a, char *content)
{
	a->next = new_node(content);
	return (a->next);
}

static t_pile	*add_previous(t_pile *first_node)
{
	int			j;
	static int	i = 2;

	j = 0;
	while (j != (i - 2))
	{
		first_node = first_node->next;
		j++;
	}
	i++;
	return (first_node);
}

t_pile_ab	*do_pile_a(int argc, char **argv)
{
	int			i;
	t_pile		*first_node;
	t_pile_ab	*ab;

	ab = malloc(sizeof(t_pile_ab));
	if (ab == NULL)
		return (NULL);
	ab->b = NULL;
	i = 1;
	ab->a = new_node(argv[i]);
	ab->a->previous = NULL;
	first_node = ab->a;
	i++;
	while (i < argc)
	{
		ab->a = add_back(ab->a, argv[i]);
		ab->a->previous = add_previous(first_node);
		i++;
	}
	while (ab->a->previous != NULL)
		ab->a = ab->a->previous;
	return (ab);
}
