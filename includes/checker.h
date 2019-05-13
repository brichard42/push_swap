/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:24:27 by brichard          #+#    #+#             */
/*   Updated: 2019/05/13 14:33:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "stdlib.h"

typedef struct	s_stack
{
	size_t	size;
	int		*stack;
}				t_stack;

typedef struct	s_env
{
	size_t	size;
	t_stack	a;
	t_stack	b;
}				t_env;

typedef void	(*t_op)(t_env *env);

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

void			down_slide(int *stack, size_t size);
void			up_slide(int *stack, size_t size);

#endif
