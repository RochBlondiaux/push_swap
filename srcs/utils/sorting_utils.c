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

int	nb_of_rotates(t_element *a, int i)
{
	int	moves;

	moves = 0;
	if (i <= (int) element_size(a) / 2)
		return (i);
	if (i > (int) element_size(a) / 2)
		moves = element_size(a) - i;
	return (moves);
}

void	get_closest_to_top(t_element **a, t_element *b, t_hold hold)
{
	int	nb_first_moves;
	int	nb_scd_moves;

	(void) b;
	nb_first_moves = nb_of_rotates(*a, hold.first_hold);
	nb_scd_moves = nb_of_rotates(*a, hold.second_hold);
	if (hold.first_hold == -1 && hold.second_hold == -1)
		return ;
	if (nb_first_moves < nb_scd_moves || hold.second_hold == -1)
	{
		while (nb_first_moves > 0)
		{
			rotate(a, 'a');
			nb_first_moves --;
		}
	}
	else
	{
		while (nb_scd_moves > 0)
		{
			reverse_rotate(a, 'a');
			nb_scd_moves --;
		}
	}
}

int	is_in_chunk(int a, t_chunk chunk)
{
	if (a >= chunk.min && a <= chunk.max)
		return (1);
	return (0);
}

int	get_hold_element(t_element *a, int hold)
{
	int			i;
	t_element	*temp;

	temp = a;
	i = 0;
	while (temp)
	{
		if (temp->value == hold)
			return (i);
		i ++;
		temp = temp->next;
	}
	return (-1);
}
