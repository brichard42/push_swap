/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:03:44 by brichard          #+#    #+#             */
/*   Updated: 2019/05/16 17:48:49 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
int			main(int ac, char **av)
{
	t_env	env;
	t_op	op_tab[11];

	if (ac < 2)
		return (usage());
	ft_bzero((void*)&env, sizeof(t_env));
	if (!(parse_arg(&env, ac, av)))
		return (usage());
	print_stack('a', env.a);
	ps_init_op_tab(op_tab);
	return (0);
}
