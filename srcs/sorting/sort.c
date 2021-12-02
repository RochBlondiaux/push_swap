/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:52:31 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/02 10:45:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_element **stack_a, t_element **stack_b)
{

}

void	sort_5(t_element **stack_a, t_element **stack_b)
{

}

void	sort_100(t_element **stack_a, t_element **stack_b)
{

}

void	sort_500(t_element **stack_a, t_element **stack_b)
{

}

void	sort(t_element **stack_a, t_element **stack_b)
{
	size_t	length;

	length = element_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (length <= 3)
		sort_3(stack_a, stack_b);
	else if (length <= 5)
		sort_5(stack_a, stack_b);
	else if (length <= 100)
		sort_100(stack_a, stack_b);
	else if (length <= 500)
		sort_500(stack_a, stack_b);
}
