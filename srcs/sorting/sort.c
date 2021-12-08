/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:36:39 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 16:07:33 by rblondia         ###   ########.fr       */
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

void	move_opti_b(t_element **a, t_element **b)
{
	if (!is_sorted(*a) && (get_top(*b) < get_element(*b, 1)->value))
		swap_both(a, b);
	else
		swap(b, 'b');
}

void	sort_5(t_element **stack_a, t_element **stack_b)
{
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if (get_top(*stack_b) < get_bottom(*stack_b))
		move_opti_b(stack_a, stack_b);
	sort_3(stack_a);
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

void	sort_bigger(t_element **stack_a, t_element **stack_b)
{
	size_t		length;
	size_t		i;
	size_t		j;
	int			k;

	length = element_size(*stack_a);
	i = 0;
	while (is_sorted(*stack_a) == 0)
	{
		j = 0;
		while (j < length)
		{
			k = (*stack_a)->value >> i;
			if ((k & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		while ((*stack_b))
			push(stack_b, stack_a, 'a');
		i++;
	}
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
	else
		sort_bigger(stack_a, stack_b);
}
