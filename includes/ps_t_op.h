/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_t_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:19:24 by brichard          #+#    #+#             */
/*   Updated: 2019/06/13 15:26:20 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_T_OP_H
# define PS_T_OP_H

# include "ps_struct.h"
# include <stdlib.h>

typedef void	(*t_op)(t_env *env, void (*f)(t_env *, char *));

void			down_slide(int *stack, size_t size);
void			up_slide(int *stack, size_t size);

void			pa(t_env *env, void (*f)(t_env *, char *));
void			pb(t_env *env, void (*f)(t_env *, char *));
void			sa(t_env *env, void (*f)(t_env *, char *));
void			sb(t_env *env, void (*f)(t_env *, char *));
void			ss(t_env *env, void (*f)(t_env *, char *));
void			ra(t_env *env, void (*f)(t_env *, char *));
void			rb(t_env *env, void (*f)(t_env *, char *));
void			rr(t_env *env, void (*f)(t_env *, char *));
void			rra(t_env *env, void (*f)(t_env *, char *));
void			rrb(t_env *env, void (*f)(t_env *, char *));
void			rrr(t_env *env, void (*f)(t_env *, char *));

void			ps_init_op_tab(t_op *op_tab, size_t size);
int				ps_hach(char *op);

#endif
