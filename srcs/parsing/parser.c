/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:53:46 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 15:05:13 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_data(t_element *lst)
{
	t_element	*tmp;
	t_element	*tmp1;
	int			count;

	tmp = lst;
	while (tmp)
	{
		count = 0;
		tmp1 = tmp;
		while (tmp1)
		{
			if (tmp1->value == tmp->value)
			{
				count++;
				if (count >= 2)
					exit_error();
			}	
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

void	parse(t_element **lst, char **args, int argc)
{
	int			index;
	int			tmp;

	index = argc - 1;
	while (index > 0)
	{
		tmp = ft_atoi(args[index]);
		if (tmp == 0 && (!args[index] || args[index][0] != '0'))
			exit_error();
		*lst = new_element(tmp, *lst);
		index--;
	}
	check_data(*lst);
}
