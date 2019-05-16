/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:01:21 by brichard          #+#    #+#             */
/*   Updated: 2019/05/16 17:14:23 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PARSING_H
# define PS_PARSING_H

# include "../libft/includes/libft.h"
# include "ps_struct.h"
# include <stdlib.h>

int		parse_arg(t_env *env, int ac, char **av);

#endif
