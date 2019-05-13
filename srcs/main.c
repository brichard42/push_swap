/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:10:08 by brichard          #+#    #+#             */
/*   Updated: 2019/05/13 15:09:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

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

void	print_stack(char name, t_stack *stack)
{
	size_t i;
	
	i = 0;
	while (i < stack->size)
	{
		ft_printf("%c_stack[%d] = %d\n", name, i, stack->stack[i]);
		++i;
	}
}
int	main(int ac, char **av)
{
	t_env	env;
	t_op	op_tab[11];

	init_op_tab(op_tab);
	if (ac < 2)
		return (usage());
	(void)av;
	env.size = 5;
	env.a.size = 5;
	env.b.size = 0;
	if (!(env.a.stack = ft_memalloc(sizeof(int) * env.size)))
		exit (0);
	if (!(env.b.stack = ft_memalloc(sizeof(int) * env.size)))
		exit (0);
	env.a.stack[0] = 5;
	env.a.stack[1] = 4;
	env.a.stack[2] = 3;
	env.a.stack[3] = 2;
	env.a.stack[4] = 1;
	ft_printf("-------\n");
	print_stack('a', &env.a);
	print_stack('b', &env.b);
	pb(&env);
	ft_printf("-------\n");
	print_stack('a', &env.a);
	print_stack('b', &env.b);
	pb(&env);
	ft_printf("-------\n");
	print_stack('a', &env.a);
	print_stack('b', &env.b);
	pb(&env);
	ft_printf("-------\n");
	print_stack('a', &env.a);
	print_stack('b', &env.b);
	rb(&env);
	ft_printf("-------\n");
	print_stack('a', &env.a);
	print_stack('b', &env.b);
	rrb(&env);
	ft_printf("-------\n");
	print_stack('a', &env.a);
	print_stack('b', &env.b);
	return (0);
}
