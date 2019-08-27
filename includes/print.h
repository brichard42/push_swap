/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:25:25 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 15:18:30 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdlib.h>
# include "ps_struct.h"
# include "../libft/includes/libft.h"

int			usage(t_env *env);
void		print_stack(t_stack a, t_stack b);
void		ps_delstacks(t_env *env);

#endif
