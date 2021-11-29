/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:50:47 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 16:15:04 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_element *stack)
{
	int	i;

	printf("=======[STACK]=======\n");
	i = 0;
	while (stack)
	{
		printf("#%d: %d\n", i, stack->value);
		i++;
		stack = stack->next;
	}
	printf("=======[STACK]=======\n\n");
}

int	main(int argc, char **argv)
{
	t_element	*stack_a;
	t_element	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	parse(&stack_a, argv, argc);
	//create_empty(&stack_b, element_size(stack_a));
	print_stack(stack_a);
	print_stack(stack_b);
	push(&stack_a, &stack_b, 'b');
	print_stack(stack_a);
	print_stack(stack_b);
	clear_elements(&stack_a, &stack_b);
	return (0);
}
