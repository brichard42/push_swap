/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_t_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:19:24 by brichard          #+#    #+#             */
/*   Updated: 2019/05/16 18:04:32 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_T_OP_H
# define PS_T_OP_H

# include "ps_struct.h"
# include <stdlib.h>

typedef void	(*t_op)(t_env *env);

void			down_slide(int *stack, size_t size);
void			up_slide(int *stack, size_t size);

void			pa(t_env *env);
void			pb(t_env *env);
void			sa(t_env *env);
void			sb(t_env *env);
void			ss(t_env *env);
void			ra(t_env *env);
void			rb(t_env *env);
void			rr(t_env *env);
void			rra(t_env *env);
void			rrb(t_env *env);
void			rrr(t_env *env);

void			ps_init_op_tab(t_op *op_tab);
int				ps_hach(char *op);

#endif
