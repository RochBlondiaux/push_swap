/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:36:38 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/06 18:36:38 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_element *stack)
{
	int	last;

	last = stack->value;
	while (stack->next)
	{
		if (stack->value > stack->next->value
			|| last > stack->value)
			return (0);
		last = stack->value;
		stack = stack->next;
	}
	return (1);
}

void	nicest_5sort(t_element **stack_a, t_element **stack_b)
{
	if ((get_top(*stack_b) > get_top(*stack_a))
		&& get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (get_top(*stack_b) > get_top(*stack_a))
			rotate(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	if ((get_top(*stack_b) < get_top(*stack_a))
		&& get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (!is_sorted(*stack_a))
			reverse_rotate(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	if ((get_top(*stack_b) < get_top(*stack_a))
		&& get_top(*stack_b) > get_bottom(*stack_a))
	{
		push(stack_b, stack_a, 'a');
		while (!is_sorted(*stack_a))
			reverse_rotate(stack_a, 'a');
	}
	if (get_top(*stack_a) > get_element(*stack_a, 1)->value)
		swap(stack_a, 'a');
}
