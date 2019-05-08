/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:10:08 by brichard          #+#    #+#             */
/*   Updated: 2019/05/08 17:20:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define ERROR_STR "Oups, something went wrong .. Check ernum for more infos.\nErnum: {%d}\n"

void    return_error(int ernum)
{
    ft_printf(ERROR_STR, ernum);
    exit(ernum);
}
static int      get_stack_size(char *av)
{
    int count;
    int bol;

    count = 0;
    while (*av)
    {
        bol = 0;
        if (ft_isdigit(*av))
        {
            while (ft_isdigit(*av))
                ++av;
            ++count;
            bol = 1;
        }
        if ((*av == ' ' || *av == '\n') && bol == 1)
            ++av;
        else if (bol != 1)
            return_error(-1);
    }
    return (count);
}

static int      *get_a_stack(char *av)
{
   int  size_stack;

   size_stack = get_stack_size(av);
   ft_printf("%d\n", size_stack);
   return (0);
}

static void     checker_pars(char *av)
{
    int *a_stack;

    if (!(a_stack = get_a_stack(av)))
        return ;
}

int             main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putendl("Error: Wrong input format.");
        return (0);
    }
    checker_pars(av[1]);
    return (0);
}
