/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:09:08 by mel-hada          #+#    #+#             */
/*   Updated: 2022/03/15 16:28:36 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include <stdlib.h>

int	check_opt(char *opt, t_stacks *stack)
{
	if (ft_strcmp(opt, "sa\n") || ft_strcmp(opt, "sb\n")
		|| ft_strcmp(opt, "ss\n") || ft_strcmp(opt, "ra\n")
		|| ft_strcmp(opt, "rb\n") || ft_strcmp(opt, "rra\n")
		|| ft_strcmp(opt, "rrb\n") || ft_strcmp(opt, "rrr\n")
		|| ft_strcmp(opt, "pa\n") || ft_strcmp(opt, "pb\n")
		|| ft_strcmp(opt, "rr\n"))
		return (1);
	else if (!opt
		&& check_sorted(stack->a, stack->size_a, ASCENDING))
	{		
		ft_printf("\033[0;32mOK\n");
		return (0);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
}

void	ft_opt(t_stacks *stack, char *opt)
{
	if (ft_strcmp(opt, "sa\n"))
		sa(stack, STACK);
	else if (ft_strcmp(opt, "sb\n"))
		sb(stack, STACK);
	else if (ft_strcmp(opt, "ss\n"))
		ss(stack, STACK);
	else if (ft_strcmp(opt, "ra\n"))
		ra(stack, STACK);
	else if (ft_strcmp(opt, "rb\n"))
		rb(stack, STACK);
	else if (ft_strcmp(opt, "rr\n"))
		rr(stack, STACK);
	else if (ft_strcmp(opt, "rra\n"))
		rra(stack, STACK);
	else if (ft_strcmp(opt, "rrb\n"))
		rrb(stack, STACK);
	else if (ft_strcmp(opt, "rrr\n"))
		rrr(stack, STACK);
	else if (ft_strcmp(opt, "pa\n"))
		pa(stack, STACK);
	else if (ft_strcmp(opt, "pb\n"))
		pb(stack, STACK);
}
