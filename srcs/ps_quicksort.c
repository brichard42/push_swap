/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:46:16 by brichard          #+#    #+#             */
/*   Updated: 2019/05/20 18:14:33 by brichard         ###   ########.fr       */
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
#include <unistd.h>
int		get_median(t_stack curr, int low, int high)
{
	int	*cpy;
	int	tmp;

	if (!(cpy = ft_intcpy(curr.stack, high + 1)))
		ft_exit_malloc();
	ft_quicksort(cpy, 0, high - 0);
	tmp = cpy[high / 2];
	free (cpy);
	return (tmp);
}

static int	ps_partition(t_env *env, int low, int high, int id)
{
	int	pivot;
	int	i;
	int	push;

	if (id == 0)
		pivot = get_median(env->a, 0, high);
	else
		pivot = get_median(env->b, 0, high);
	ft_printf("pivot = %d\n", pivot);
	ft_printf("HIGH - 0 + 1 %d\n", high - 0 + 1);
	sleep(1);
	i = 0;
	push = 0;
	while (i <= high)
	{	
		if (id == 0 && *env->a.stack <= pivot)
		{
			++push;
			pb(env);
		}
		else if (id == 1 && *env->b.stack >= pivot)
		{
			++push;
			pa(env);
		}
		else if (id == 0 && *env->a.stack > pivot)
			ra(env);
		else if (id == 1 && *env->b.stack < pivot)
			rb(env);
		++i;
	}
	return (push);
}

void		ps_quicksort(t_env *env, int low, int high, int id)
{
	int	p_i;

	if ((high - 0)  < 2)
		return ;
	if (id == 0 && (high - 0) == 2)
	{
		if (env->a.stack[0] > env->a.stack[1])
			sa(env);
		return ;
	}
	else if (id == 1 && (high - 0) == 2)
	{
		if (env->b.stack[0] < env->b.stack[1])
				sb(env);
		return ;
	}
	p_i = ps_partition(env, 0, high, id);
	if (high - 0 > 2)
	{
		ps_quicksort(env, 0, high - p_i, (id == 0 ? 0 : 1));
		ps_quicksort(env, 0, p_i, (id == 0 ? 1 : 0));
	}
	while (p_i)
	{
		if (id == 0)
			pa(env);
		else
			pb(env);
		--p_i;
	}
}
