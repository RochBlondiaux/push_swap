/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:50:47 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 18:00:35 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_element	*stack_a;
	t_element	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	parse(&stack_a, argv, argc);
	print_stacks(stack_a, stack_b);
	sort(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	clear_elements(&stack_a, &stack_b);
	return (0);
}
