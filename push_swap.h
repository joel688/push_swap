/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:15:21 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/15 11:41:43 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_pile
{
	int				number;
	int				rank;
	struct t_pile	*next;
	struct t_pile	*previous;
}					t_pile;

typedef struct t_pile_ab
{
	struct t_pile	*a;
	struct t_pile	*b;
}					t_pile_ab;

int					is_error(int argc, char **argv);
size_t				ft_strlen(const char *s);
long int			ft_atoi(const char *str);
t_pile_ab			*do_pile_a(int argc, char **argv);
void				sa(t_pile_ab *ab);
int					do_nothing_one_or_no_arg(t_pile_ab *ab);
void				ra(t_pile_ab *ab);
void				rra(t_pile_ab *ab);
void				pb(t_pile_ab *ab);
void				sb(t_pile_ab *ab);
void				rb(t_pile_ab *ab);
void				pa(t_pile_ab *ab);
void				rrb(t_pile_ab *ab);
void				ss(t_pile_ab *ab);
void				rr(t_pile_ab *ab);
void				rrr(t_pile_ab *ab);
void				find_mediane(t_pile_ab *ab);
void				*push_swap(int argc, char **argv);
int					lst_len(t_pile *a);
void				sort(t_pile_ab *ab);
void				go_top(t_pile **z);
void				find_med_b(t_pile_ab *ab);
void				sort_lst_three(t_pile_ab *ab);
void				sort_lst_five(t_pile_ab *ab);
void				sort_three_b(t_pile_ab *ab);
int					best_move(t_pile *z, int tofind);
int					best_to_move(t_pile *z, int j, int i);
int					cost(t_pile_ab *ab);
int					find_target(t_pile_ab *ab);
int					find_target_b_no_error(t_pile_ab *ab);
int					find_target_b(t_pile_ab *ab);
void				sort_five_bis(t_pile_ab *ab);
void				sort_hundred(t_pile_ab *ab);
void				sort_less_fifty(t_pile_ab *ab);
void				sort_less_three(t_pile_ab *ab);
void				freelst(t_pile_ab *ab);

#endif
