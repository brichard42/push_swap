/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:49:07 by brichard          #+#    #+#             */
/*   Updated: 2019/09/02 19:11:19 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_parsing.h"

static int			check_double(t_stack to_check)
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

static int			ps_valid_sign(char *arg)
{
	if (*arg && (*arg == '-' || *arg == '+'))
	{
		if (arg[1] && ft_isdigit(arg[1]))
			return (1);
		else
			return (0);
	}
	return (0);
}

static long long	ps_atoi(const char *str)
{
	long long	neg;
	long long	num;

	neg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0') * neg;
		if ((num > 0 && neg == -1) || (num < 0 && neg == 1))
			return (LONG_MAX);
		++str;
	}
	return (num);
}

static int8_t		ps_get_num(t_env *env, char *arg, int *j)
{
	int8_t	ret;

	ret = 1;
	if (ps_atoi(&arg[*j]) > INT_MAX)
		ret = 0;
	if (!(ft_int_realloc(&(env->a.stack), &(env->a.size), ps_atoi(&arg[*j]))))
		ret = 0;
	if (arg[*j] == '-' || arg[*j] == '+')
		++*j;
	while (arg[*j] && ft_isdigit(arg[*j]))
		++*j;
	return (ret);
}

int					parse_arg(t_env *env, int ac, char **av)
{
	int	i;
	int	j;
	int ret;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				++j;
			if (ft_isdigit(av[i][j]) || ps_valid_sign(&av[i][j]))
				ret = ps_get_num(env, av[i], &j);
			if (av[i][j] == '\0')
				break ;
			if (av[i][j] != ' ' || ft_isdigit(av[i][j]))
				return (0);
		}
		++i;
	}
	env->size = env->a.size;
	if (ret == 0 || !(env->b.stack = ft_memalloc(sizeof(int) * env->size)))
		return (0);
	return (check_double(env->a));
}
