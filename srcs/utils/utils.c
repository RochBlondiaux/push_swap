/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:10:50 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/30 13:00:05 by rblondia         ###   ########.fr       */
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
