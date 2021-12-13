/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 12:51:27 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_element	*get_by_index(t_element *stack, int index)
{
	while (stack)
	{
		if (stack->index >= 0 && stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_element	*get_by_value(t_element *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_indexes(t_element *stack)
{
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}

void	pre_sort(t_element **stack)
{
	t_element		*tmp;

	init_indexes(*stack);
	get_lowest(*stack)->index = 0;
	tmp = *stack;
	give_index(tmp, stack);
	tmp = *stack;
	while (tmp)
	{
		tmp->value = tmp->index;
		tmp = tmp->next;
	}
}
