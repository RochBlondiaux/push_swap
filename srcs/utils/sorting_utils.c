/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 12:53:32 by rblondia         ###   ########.fr       */
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
			rotate(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	if ((get_top(*stack_b) < get_top(*stack_a))
		&& get_top(*stack_b) > get_bottom(*stack_a))
	{
		push(stack_b, stack_a, 'a');
		while (!is_sorted(*stack_a))
			rotate(stack_a, 'a');
	}
	if (get_top(*stack_a) > get_element(*stack_a, 1)->value)
		swap(stack_a, 'a');
}

int	find_next_index(t_element **stack, int previous)
{
	t_element	*tmp;
	int			current;

	tmp = *stack;
	current = -200000000;
	while (tmp)
	{
		if (tmp->value > previous
			&& ((current == -200000000 && tmp->value != -200000000)
				|| tmp->value < current))
			current = tmp->value;
		tmp = tmp->next;
	}
	return (current);
}

void	give_index(t_element *tmp, t_element **stack)
{
	int			i;
	int			current;
	int			previous;

	i = 1;
	while (tmp)
	{
		if (!get_by_index(*stack, i - 1))
		{
			tmp = tmp->next;
			continue ;
		}
		previous = get_by_index(*stack, i - 1)->value;
		current = find_next_index(stack, previous);
		if (!get_by_value(*stack, current))
		{
			tmp = tmp->next;
			continue ;
		}
		get_by_value(*stack, current)->index = i;
		tmp = tmp->next;
		i++;
	}
}
