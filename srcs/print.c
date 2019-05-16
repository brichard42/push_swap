/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:23:43 by brichard          #+#    #+#             */
/*   Updated: 2019/05/16 17:27:32 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int			usage(void)
{
	ft_putendl("Format Error. Usage: ./checker [num1 num2 num3 ..]");
	return (0);
}

void		print_stack(char name, t_stack stack)
{
	size_t i;

	i = 0;
	while (i < stack.size)
	{
		ft_printf("%c_stack[%d] = %d\n", name, i, stack.stack[i]);
		++i;
	}
}
