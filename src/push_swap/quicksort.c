/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:50:45 by mel-hada          #+#    #+#             */
/*   Updated: 2022/03/13 18:48:17 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	quicksort_3(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, OPT);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, OPT);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack, OPT);
			else if (len++)
				pa(stack, OPT);
		}
	}
}

int	sort_small_b(t_stacks *s, int len)
{
	if (len == 1)
		pa(s, OPT);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s, OPT);
		while (len--)
			pa(s, OPT);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				sa(s, OPT);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = push(s, len, 1);
			else
				sb(s, OPT);
		}
	}
	return (0);
}

int	get_mediane(int *pivot, int *stack, int size)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	sort_tmp(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	quicksort_a(t_stacks *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (check_sorted(stack->a, len, ASCENDING) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		quicksort_3(stack, len);
		return (1);
	}
	if (!cnt && !get_mediane(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, OPT);
		else if (++cnt)
			ra(stack, OPT);
	}
	while (items / 2 + items % 2 != stack->size_a && cnt--)
		rra(stack, OPT);
	return (quicksort_a(stack, items / 2 + items % 2, 0)
		&& quicksort_b(stack, items / 2, 0));
	return (1);
}

int	quicksort_b(t_stacks *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (!cnt && check_sorted(stack->b, len, DESCENDING) == 1)
		while (len--)
			pa(stack, OPT);
	if (len <= 3)
	{
		sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!get_mediane(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack, OPT);
		else if (++cnt)
			rb(stack, OPT);
	}
	while (items / 2 != stack->size_b && cnt--)
		rrb(stack, OPT);
	return (quicksort_a(stack, items / 2 + items % 2, 0)
		&& quicksort_b(stack, items / 2, 0));
}
