/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:10:08 by brichard          #+#    #+#             */
/*   Updated: 2019/05/06 17:51:59 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_list   *get_a_stack

static void     checker_pars(char **av, int *a_stack, t_list *inst)
{
    (void)a_stack;
    (void)inst;
}

int             main(int ac, char **av)
{
    int *a_stack;

    if (ac != 2)
        return_error(-1);
    if (!(a_stack = checker_pars(fd)))
        exit(-1);
    return (0);
}
