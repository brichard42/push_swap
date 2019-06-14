/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:36:18 by brichard          #+#    #+#             */
/*   Updated: 2019/06/14 13:22:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCT_H
# define PS_STRUCT_H

# include <stdlib.h>

typedef struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

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
	t_dlist *inst;
}				t_env;

#endif
