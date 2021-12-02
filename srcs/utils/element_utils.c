/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:02:56 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/02 11:08:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_top(t_element *stack)
{
	if (!stack)
		return (0);
	return	(stack->value);
}

int get_bottom(t_element *stack)
{
	if (!stack)
		return (0);
	return (get_last_element(stack)->value);
}