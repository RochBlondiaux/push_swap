/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 12:45:20 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	print_stacks(t_element *stack_a, t_element *stack_b)
{
	int	i;

	if (!DEBUG)
		return ;
	i = 0;
	while (stack_a || stack_b)
	{
		if (stack_a)
			ft_putnbr_fd(stack_a->value, 1);
		else
			ft_putstr_fd("  ", 1);
		ft_putstr_fd("  ", 1);
		if (stack_b)
			ft_putnbr_fd(stack_b->value, 2);
		else
			ft_putstr_fd("  ", 1);
		ft_putchar_fd('\n', 1);
		i++;
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	ft_putstr_fd("_  _\na  b\n", 1);
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

void	get_lowest_top(t_element **a, int index, int i)
{
	if (index == 0)
		return ;
	else if (index == 1)
	{
		rotate(a, 'a');
		return ;
	}
	else if (index == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
		return ;
	}
	else if (index == 3 - i)
	{
		reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
		return ;
	}
	if (index == 4 - i)
	{
		reverse_rotate(a, 'a');
		return ;
	}
}
