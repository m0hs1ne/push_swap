/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:09:04 by mel-hada          #+#    #+#             */
/*   Updated: 2022/03/19 12:04:42 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include <stdlib.h>

void	checker(t_stacks *stack)
{
	char		*opt;

	opt = get_next_line(0);
	while (opt != NULL)
	{
		if (!check_opt(opt, stack))
		{
			free(stack->a);
			free(stack->b);
			return ;
		}
		ft_opt(stack, opt);
		free(opt);
		opt = get_next_line(0);
	}
	if (check_sorted(stack->a, stack->size_a, ASCENDING)
		&& stack->size_b == 0)
		ft_printf("\033[0;32mOK\n");
	else
		ft_printf("\033[0;31mK0\n");
	free(stack->a);
	free(stack->b);
	exit (1);
}

int	*check_errors(char **argv)
{
	int	*a;
	int	size;
	int	i;

	i = -1;
	size = ps_strlen(argv);
	a = malloc(size * sizeof(int));
	if (!a)
		return (0);
	while (++i < size)
		a[i] = ps_atoi(argv[i]);
	check_repeat(a, size);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		stack.a = check_errors(argv);
		stack.size_a = ps_strlen(argv);
		stack.b = malloc(stack.size_a * sizeof(int));
		if (!stack.b)
		{
			free(stack.a);
			return (0);
		}
		stack.size_b = 0;
		checker(&stack);
	}
	return (0);
}
