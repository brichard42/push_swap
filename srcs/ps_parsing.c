/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:49:07 by brichard          #+#    #+#             */
/*   Updated: 2019/05/17 16:02:18 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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

static int		ps_valid_sign(char *arg)
{
	if (*arg && (*arg == '-' || *arg == '+'))
		if ((arg[1] && !(ft_isdigit(arg[1]))) || !(arg[1]))
			return (0);
	if (*arg == ' ')
		return (0);
	return (1);
}

int				parse_arg(t_env *env, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			ft_printf("%c\n", av[i][j]);
			if (av[i][j] != ' ' && !(ft_isdigit(av[i][j])) && !(ps_valid_sign(av[i] + j)))
				return (0);
			if (ft_isdigit(av[i][j]) || ps_valid_sign(av[i] + j))
			{
				if (!(ft_int_realloc(&(env->a.stack), &(env->a.size)\
								, ft_atoi(av[i] + j))))
					ft_exit_malloc();
				if (av[i][j] == '-' || av[i][j] == '+')
					++j;
				while (av[i][j] && ft_isdigit(av[i][j]))
					++j;
				if (av[i][j] == '\0')
					--j;
			}
			++j;
		}
		++i;
	}
	env->size = env->a.size;
	if (!(env->b.stack = ft_memalloc(sizeof(int) * env->size)))
		ft_exit_malloc();
	return (check_double(env->a));
}
