/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:36:39 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/06 19:19:36 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_element **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = get_top(*stack_a);
	middle = get_element(*stack_a, 1)->value;
	bottom = get_bottom(*stack_a);
	if (top > middle && bottom > middle && top < bottom)
		swap(stack_a, 'a');
	else if (top > middle && middle > bottom && top > bottom)
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (top > middle && bottom > middle && top > bottom)
		rotate(stack_a, 'a');
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (top < middle && middle > bottom && top > bottom)
		reverse_rotate(stack_a, 'a');
}

void	sort_5(t_element **stack_a, t_element **stack_b)
{
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	if (get_top(*stack_b) < get_bottom(*stack_b))
		swap(stack_b, 'b');
	while ((get_top(*stack_b) < get_top(*stack_a)) && *stack_b)
		push(stack_b, stack_a, 'a');
	while (get_top(*stack_b) > get_bottom(*stack_a))
	{
		push(stack_b, stack_a, 'a');
		while (!is_sorted(*stack_a))
			rotate(stack_a, 'a');
	}
	if (*stack_b)
		nicest_5sort(stack_a, stack_b);
}

void	sort_100(t_element **stack_a, t_element **stack_b)
{
	(void) stack_a;
	(void) stack_b;
}

void	sort_500(t_element **stack_a, t_element **stack_b)
{
	(void) stack_a;
	(void) stack_b;
}

void	sort(t_element **stack_a, t_element **stack_b)
{
	size_t	length;

	length = element_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (length <= 3)
		sort_3(stack_a);
	else if (length <= 5)
		sort_5(stack_a, stack_b);
	else if (length <= 100)
		sort_100(stack_a, stack_b);
	else if (length <= 500)
		sort_500(stack_a, stack_b);
}
