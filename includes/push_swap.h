/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:16:25 by brichard          #+#    #+#             */
/*   Updated: 2019/06/17 13:59:35 by brichard         ###   ########.fr       */
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
void	ps_check_inst(t_dlist **inst);

void	end(void) __attribute__ ((destructor));//todelete

void		ps_del(void *content);
void		ft_dlstdelone(t_dlist **alst, void (*del)(void*));
void		ft_dlstdel(t_dlist **alst, void (*del)(void*));
void		ft_dlstadd(t_dlist **alst, t_dlist *new);
t_dlist		*ft_dlstnew(void const *content, size_t content_size);

#endif
