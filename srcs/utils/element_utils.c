/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:36:39 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 22:21:54 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_top(t_element *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}

int	get_bottom(t_element *stack)
{
	if (!stack)
		return (0);
	return (get_last_element(stack)->value);
}

int	get_bigger(t_element *stack)
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

t_element *get_lowest(t_element *stack)
{
	t_element	*tmp;

	tmp = stack;
	while (stack)
	{
		if (stack->value < tmp->value)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}
