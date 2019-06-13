/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:03:44 by brichard          #+#    #+#             */
/*   Updated: 2019/06/13 13:25:05 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define OP_SIZE 650

static void	ps_check_sort(t_env *env)
{
	size_t	i;
	int		grind;

	if (env->b.size != 0)
		return (ft_putendl("KO"));
	if (env->a.size < 2)
		return (ft_putendl("OK"));
	grind = INT_MIN;
	i = 1;
	while (i < env->a.size)
	{
		if (env->a.stack[i] < grind)
			return (ft_putendl("KO"));
		else
			grind = env->a.stack[i];
		++i;
	}
	return (ft_putendl("OK"));
}

int			main(int ac, char **av)
{
	t_env	env;
	t_op	op_tab[OP_SIZE];
	char	*line;

	if (ac < 2)
		return (0);
	ft_bzero((void*)&env, sizeof(t_env));
	if (!(parse_arg(&env, ac, av)))
	{
		ft_memdel((void*)&env.a.stack);
		ft_memdel((void*)&env.b.stack);
		return (usage());
	}
	print_stack(env.a, env.b);
	ps_init_op_tab(op_tab, OP_SIZE);
	while (get_next_line(0, &line, '\n') > 0)
	{
		if (op_tab[ps_hach(line)] != NULL)
			op_tab[ps_hach(line)](&env, NULL);
		else
		{
			ft_strdel(&line);
			ft_memdel((void*)&env.a.stack);
			ft_memdel((void*)&env.b.stack);
			return (usage());
		}
		ft_strdel(&line);
	}
	print_stack(env.a, env.b);
	ps_check_sort(&env);
	ft_memdel((void*)&env.a.stack);
	ft_memdel((void*)&env.b.stack);
	return (0);
}
