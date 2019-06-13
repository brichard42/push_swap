/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:16:25 by brichard          #+#    #+#             */
/*   Updated: 2019/06/13 16:07:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_parsing.h"
# include "ps_t_op.h"
# include "print.h"//to delete

void	ps_quicksort(t_env *env, int high, int id);
void	ps_sort_case(t_env *env, int high, int id);
void	ps_save(t_env *env, char *act);

#endif
