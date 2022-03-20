/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:21:05 by mel-hada          #+#    #+#             */
/*   Updated: 2022/03/19 12:06:03 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

# define ASCENDING 0
# define DESCENDING 1
# define OPT 0
# define STACK 1

void	push_swap(char **argv);
int		ps_strlen(char **argv);
void	ft_error(int n);
int		ps_atoi(char *str);
void	check_repeat(int *stack, int size);
//Operations
void	sa(t_stacks *stack, int print);
void	sb(t_stacks *stack, int print);
void	ss(t_stacks *stack, int print);
void	ra(t_stacks *stack, int print);
void	rb(t_stacks *stack, int print);
void	rr(t_stacks *stack, int print);
void	rra(t_stacks *stack, int print);
void	rrb(t_stacks *stack, int print);
void	rrr(t_stacks *stack, int print);
void	pb(t_stacks *stack, int print);
void	pa(t_stacks *stack, int print);
//Sortage
int		sort(t_stacks *stack, int size);
int		check_sorted(int *pile, int size, int order);
void	sort_three_a(t_stacks *s);
void	sort_tmp(int *tmp_stack, int size);
//Quicksort
int		quicksort_a(t_stacks *stack, int len, int cnt);
int		quicksort_b(t_stacks *stack, int len, int cnt);
void	quicksort_3(t_stacks *stack, int len);
int		sort_small_b(t_stacks *stack, int len);
int		push(t_stacks *stack, int len, int operation);
int		get_mediane(int *pivot, int *stack, int size);
//Bonus
int		*check_errors(char **argv);
char	*get_next_line(int fd);
void	checker(t_stacks *stack);
int		check_opt(char *opt, t_stacks *stack);
void	ft_opt(t_stacks *stack, char *opt);

#endif
