/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:02:56 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 15:09:52 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	create_empty(t_element **lst, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		*lst = new_element(0, *lst);
		size--;
	}
}
