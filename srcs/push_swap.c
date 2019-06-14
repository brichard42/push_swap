/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:14:38 by brichard          #+#    #+#             */
/*   Updated: 2019/06/14 16:02:35 by brichard         ###   ########.fr       */
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

static void	ps_replace_ss(t_dlist *inst)
{
	t_dlist	*tmp;

	tmp = inst->next;
	inst->next = inst->next->next;
	if (inst->next->next)
		inst->next->next->prev = inst;
	free(tmp->content); //FAUT FOUTRE LA MEM A ZERO GROS PORC
	free(tmp); //FAUT FOUTRE LA MEM A ZERO GROS PORC
	ft_strcpy((char*)inst->content, "ss");
}

static void	ps_check_inst(t_dlist **inst)
{
	if (!inst || !(*inst))
		return ;
	if ((*inst)->next)
	{
		if (ft_strequ("sa", (char*)(*inst)->content) && ft_strequ("sb", (char*)(*inst)->next->content))
			ps_replace_ss(*inst);
		else if (ft_strequ("sb", (char*)(*inst)->content) && ft_strequ("sa", (char*)(*inst)->next->content))
			ps_replace_ss(*inst);
		ps_check_inst(&(*inst)->next);
	}
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
	ps_quicksort(&env, env.size - 1, 0);
	ps_check_inst(&env.inst);
	print_inst(env.inst);
	system("leaks push_swap");
	return (0);
}
