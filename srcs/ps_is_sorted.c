/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:02:38 by brichard          #+#    #+#             */
/*   Updated: 2019/07/19 15:40:47 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_is_sorted(t_stack cur, int high)
{
	int		i;
	int		grind;

	if (high < 1)
		return (1);
	grind = INT_MIN;
	i = 0;
	while (i <= high)
	{
		if (cur.stack[i] < grind)
			return (0);
		else
			grind = cur.stack[i];
		++i;
	}
	return (1);
}

int			ps_is_back_sorted(t_stack cur, int high)
{
	int		grind;

	if (high < 1)
		return (1);
	grind = INT_MIN;
	while (0 <= high)
	{
		if (cur.stack[high] < grind)
			return (0);
		else
			grind = cur.stack[high];
		--high;
	}
	return (1);
}
