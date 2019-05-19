/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:14:38 by brichard          #+#    #+#             */
/*   Updated: 2019/05/19 18:59:09 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define OP_SIZE 650

int	main(int ac, char **av)
{
	t_env	env;
	t_op	op_tab[OP_SIZE];

	if (ac < 2)
		return (usage());
	ft_bzero((void*)&env, sizeof(t_env));
	if (!(parse_arg(&env, ac, av)))
	{
		ft_memdel((void*)&env.a.stack);
		ft_memdel((void*)&env.b.stack);
		return (usage());
	}
	ps_init_op_tab(op_tab, OP_SIZE);
	print_stack(env.a, env.b);
	ft_printf("______{%d}______\n", ps_partition(&env, 0, env.size - 1, 0));
	return (0);
}
