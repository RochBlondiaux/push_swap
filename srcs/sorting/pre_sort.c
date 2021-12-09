/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/09 13:25:28 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_element *get_by_index(t_element *stack, int index)
{
	while (stack)
	{
		if (stack->index >= 0 && stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_element *get_by_value(t_element *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void init_indexes(t_element *stack)
{
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}

void	pre_sort(t_element **stack)
{
	t_element 	*tmp;
	t_element 	*tmp1;
	int			previous;
	int			i;
	int			current;

	init_indexes(*stack);
	get_lowest(*stack)->index = 0;
	tmp = *stack;
	i = 1;
	while (tmp)
	{
		if (!get_by_index(*stack, i - 1))
		{
			tmp = tmp->next;
			continue;
		}
		previous = get_by_index(*stack, i - 1)->value;
		tmp1 = *stack;
		current = -200000000;
		while (tmp1)
		{
			if (tmp1->value > previous && ((current == -200000000 && tmp1->value != -200000000) || tmp1->value < current))
				current = tmp1->value;
			tmp1 = tmp1->next;
		}
		if (!get_by_value(*stack, current))
		{
			tmp = tmp->next;
			continue;
		}
		get_by_value(*stack, current)->index = i;
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;
		//printf("=================================\n\n");
	while (tmp)
	{
		//	printf("Value: %d Index: %d\n", tmp->value, tmp->index);
		tmp->value = tmp->index;
		tmp = tmp->next;
	}
		//printf("=================================\n\n");
}