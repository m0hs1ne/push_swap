/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:53:42 by mel-hada          #+#    #+#             */
/*   Updated: 2022/03/19 12:15:52 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"
#include <stdlib.h>

void	check_valid(char str, unsigned long int num, int neg, int valid)
{
	if (str || !valid)
		ft_error(1);
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		ft_error(1);
}

int	ps_atoi(char *str)
{
	unsigned int		i;
	int					neg;
	unsigned long int	num;
	int					valid;

	valid = 0;
	i = 0;
	num = 0;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		valid = 1;
		i++;
	}
	check_valid(str[i], num, neg, valid);
	return (num * neg);
}

int	ps_strlen(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}

int	check_sorted(int *stack, int size, int order)
{
	int	i;

	if (order == ASCENDING)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	check_repeat(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				ft_error(1);
			j++;
		}
		i++;
		j = i + 1;
	}
}
