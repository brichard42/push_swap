/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:23:43 by brichard          #+#    #+#             */
/*   Updated: 2019/09/02 16:54:31 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <unistd.h>

void		ps_delstacks(t_env *env)
{
	ft_memdel((void*)&env->a.stack);
	ft_memdel((void*)&env->b.stack);
}

int			usage(t_env *env)
{
	ft_putendl_fd("Error", 2);
	ft_memdel((void*)&env->a.stack);
	ft_memdel((void*)&env->b.stack);
	return (0);
}

/*
**void		print_stack(t_stack a, t_stack b)
**{
**	size_t i;
**
**	i = 0;
**	ft_putstr("\e[1;1H\e[2J");
**	ft_printf("\tA\t|\tB\t\n   ----------------------------\n");
**	while (i < a.size || i < b.size)
**	{
**		if (i < a.size && i < b.size)
**			ft_printf("%d |\t%d\t\t%d\t\n", i, a.stack[i], b.stack[i]);
**		else if (i < a.size && i >= b.size)
**			ft_printf("%d |\t%d\n", i, a.stack[i]);
**		else
**			ft_printf("%d |\t \t\t%d\t\n", i, b.stack[i]);
**		++i;
**	}
**}
*/
