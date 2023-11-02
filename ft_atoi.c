/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:20:46 by joakoeni          #+#    #+#             */
/*   Updated: 2023/03/14 16:59:32 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	long long int	result;
	int				sign;

	sign = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\v'))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (*str < '0' || *str > '9')
			return (result);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (sign < 0)
		result *= -1;
	return (result);
}
