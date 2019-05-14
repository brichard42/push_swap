/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:10:08 by brichard          #+#    #+#             */
/*   Updated: 2019/05/14 17:56:44 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	exit_malloc(void)
{
	ft_putendl("Oups, a malloc just crashed ..");
	exit(-1);
}

int	usage(void)
{
	ft_putendl("Format Error. Usage: ./checker [num1 num2 num3 ..]");
	return (0);
}

void	init_op_tab(t_op *op_tab)
{
	op_tab[0] = pa; 
	op_tab[1] = pb; 
	op_tab[2] = sa; 
	op_tab[3] = sb; 
	op_tab[4] = ss; 
	op_tab[5] = ra; 
	op_tab[6] = rb; 
	op_tab[7] = rr; 
	op_tab[8] = rra;
	op_tab[9] = rrb;
	op_tab[10] = rrr;
}

void	print_stack(char name, t_stack stack)
{
	size_t i;
	
	i = 0;
	while (i < stack.size)
	{
		ft_printf("%c_stack[%d] = %d\n", name, i, stack.stack[i]);
		++i;
	}
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
			if (ft_isdigit(av[i][j]))
			{
				if (!(ft_int_realloc(&(env->a.stack), &(env->a.size), ft_atoi(av[i] + j))))
					exit_malloc();
				while (av[i][j] && ft_isdigit(av[i][j]))
					++j;
				--j;
			}
			else if (av[i][j] != ' ' || av[i][j] != '\0')
				return (usage());
			++j;
		}
		++i;
	}
	print_stack('a', env->a);
	return (1);
}

int	main(int ac, char **av)
{
	t_env	env;
	t_op	op_tab[11];

	env.a.stack = NULL;
	env.b.stack = NULL;
	env.a.size = 0;
	env.b.size = 0;
	env.size = 0;
	if (ac < 2)
		return (usage());
	if (!(parse_arg(&env, ac, av)))
		return (0);
	init_op_tab(op_tab);
	return (0);
}
