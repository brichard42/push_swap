/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:49:07 by brichard          #+#    #+#             */
/*   Updated: 2019/05/16 17:23:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_parsing.h"

static int		check_double(t_stack to_check)
{
	size_t	i;
	size_t	j;

	if (to_check.size < 2)
		return (1);
	i = 1;
	while (i < to_check.size)
	{
		j = 0;
		while (j < i)
			if (to_check.stack[j++] == to_check.stack[i])
				return (0);
		++i;
	}
	return (1);
}

int		parse_arg(t_env *env, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && !(ft_isdigit(av[i][j])))
				return (0);
			if (ft_isdigit(av[i][j]))
			{
				if (!(ft_int_realloc(&(env->a.stack), &(env->a.size), ft_atoi(av[i] + j))))
					ft_exit_malloc();
				while (av[i][j] && ft_isdigit(av[i][j]))
					++j;
				--j;
			}
			++j;
		}
		++i;
	}
	return (check_double(env->a));
}
