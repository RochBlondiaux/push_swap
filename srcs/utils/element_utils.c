/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:02:56 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/02 12:15:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_top(t_element *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}

int get_bottom(t_element *stack)
{
	if (!stack)
		return (0);
	return (get_last_element(stack)->value);
}

int get_bigger(t_element *stack)
{
	int	bigger;

	bigger = 0;
	while (stack)
	{
		if (stack->value > bigger)
			bigger = stack->value;
		stack = stack->next;
	}
	return (bigger);
}

int get_lowest(t_element *stack)
{
	int	lowest;

	lowest = 0;
	while (stack)
	{
		if (stack->value < lowest)
			lowest = stack->value;
		stack = stack->next;
	}
	return (lowest);
}