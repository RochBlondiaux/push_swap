/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 17:08:53 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_silently(t_element **stack)
{
	int	t;

	if (element_size(*stack) < 2)
		return ;
	t = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = t;
}

void	swap(t_element **stack, char stack_char)
{
	swap_silently(stack);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack_char, 1);
	ft_putchar_fd('\n', 1);
}

void	swap_both(t_element **stack_a, t_element **stack_b)
{
	swap_silently(stack_a);
	swap_silently(stack_b);
	ft_putstr_fd("ss\n", 1);
}
