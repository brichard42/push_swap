/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:14:38 by brichard          #+#    #+#             */
/*   Updated: 2019/07/19 15:51:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_inst(t_dlist *inst)
{
	if (!inst)
		return ;
	if (inst->next)
		print_inst(inst->next);
	ft_putendl((char*)inst->content);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (0);
	ft_bzero((void*)&env, sizeof(t_env));
	if (!(parse_arg(&env, ac, av)))
	{
		ft_memdel((void*)&env.a.stack);
		ft_memdel((void*)&env.b.stack);
		return (usage());
	}
	//print_stack(env.a, env.b);
	ps_quicksort(&env, env.size - 1, 0);
	print_inst(env.inst);
	ps_check_inst(&env.inst);
	ft_dlstdel(&env.inst, ps_del);
	ft_memdel((void*)&env.a.stack);
	ft_memdel((void*)&env.b.stack);
	return (0);
}

void	end(void)
{
//	ft_printf("in end\n");
//	system("leaks push_swap");
}
