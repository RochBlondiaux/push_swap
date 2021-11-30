/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:19:19 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/30 11:19:20 by rblondia         ###   ########.fr       */
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
