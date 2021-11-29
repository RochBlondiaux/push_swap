/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:45:32 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 15:58:52 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	clear_elements(t_element **stack_a, t_element **stack_b)
{
	t_element	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}	
	}
	if (*stack_b)
	{
		tmp = *stack_b;
		if (!tmp)
			return ;
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}	
	}
}