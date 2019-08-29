/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:03:44 by brichard          #+#    #+#             */
/*   Updated: 2019/08/29 16:38:21 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define OP_SIZE 650

static void		ps_check_sort(t_env *env)
{
	size_t	i;
	int		grind;

	if (env->b.size != 0)
		return (ft_putendl("KO"));
	if (env->a.size < 2)
		return (ft_putendl("OK"));
	grind = INT_MIN;
	i = 0;
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

static int8_t	get_next_op(char *line)
{
	char	buffer[2];
	int8_t	ret;

	while ((ret = read(0, buffer, 1)) > 0)
	{
		buffer[1] = '\0';
		if (buffer[0] == '\n')
			break ;
		ft_strcat(line, buffer);
	}
	if (buffer[0] != '\0' && ret == 0)
		return (-1);
	return (ret);
}

int				main(int ac, char **av)
{
	t_env	env;
	t_op	op_tab[OP_SIZE];
	char	line[4];
	int		ret;

	if (ac < 2)
		return (0);
	ft_bzero((void*)&env, sizeof(t_env));
	if (!(parse_arg(&env, ac, av)))
		return (usage(&env));
	ps_init_op_tab(op_tab, OP_SIZE);
	while ((ret = get_next_op(line)) > 0)
	{
		if (op_tab[ps_hach(line)] != NULL)
			op_tab[ps_hach(line)](&env, NULL);
		else
			return (usage(&env));
		ft_bzero((void*)&line, 4);
	}
	if (ret == -1)
		return (usage(&env));
	ps_check_sort(&env);
	ps_delstacks(&env);
	return (0);
}
