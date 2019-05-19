/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:16:25 by brichard          #+#    #+#             */
/*   Updated: 2019/05/19 18:37:25 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_parsing.h"
# include "ps_t_op.h"
# include "print.h"//to delete

int		ps_partition(t_env *env, int low, int high, int id);

#endif
