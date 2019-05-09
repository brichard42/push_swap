/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:27:56 by brichard          #+#    #+#             */
/*   Updated: 2019/05/09 17:05:33 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	down_slide(int *stack, size_t size)
{
	if (size > 1)
	{
		stack[size - 1] = stack[size - 2];
		down_slide(stack, size - 1);
	}
}

void	up_slide(int *stack, size_t size)
{
	if (size > 1)
	{
		down_slide(stack, size - 1);
		stack[size - 2] = stack[size - 1];
	}
}
