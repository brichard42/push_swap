/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:46:16 by brichard          #+#    #+#             */
/*   Updated: 2019/05/19 19:10:55 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_intcpy(const int *src, size_t size)
{
	int		*dst;
	size_t	i;

	if (src == NULL || size <= 0)
		return (NULL);
	if (!(dst = ft_memalloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		++i;
	}
	return (dst);
}

int		get_median(t_stack curr, int low, int high)
{
	int	*cpy;

	if (!(cpy = ft_intcpy(curr.stack, high - low + 1)))
		ft_exit_malloc();
	ft_quicksort(cpy, low, high - low);
	return (cpy[(curr.size - 1) / 2]);
}

int		ps_partition(t_env *env, int low, int high, int id)
{
	int	pivot;
	int	i;
	int	push;

	if (id == 0)
		pivot = get_median(env->a, low, high);
	else
		pivot = get_median(env->b, low, high);
	ft_printf("pivot = %d\n", pivot);
	i = low;
	push = 0;
	while (i <= high)
	{	
		ft_printf("|%d VS %d", *env->a.stack, pivot);
		if (id == 0 && *env->a.stack < pivot)
		{
			++push;
			pb(env);
		}
		else if (id == 1 && *env->b.stack < pivot)
		{
			++push;
			pa(env);
		}
		else if (id == 0 && *env->a.stack >= pivot)
			ra(env);
		else if (id == 1 && *env->b.stack >= pivot)
			rb(env);
		++i;
	}
	return (push);
}
