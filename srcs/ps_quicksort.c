/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:46:16 by brichard          #+#    #+#             */
/*   Updated: 2019/07/22 17:18:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_intcpy(const int *src, size_t size)
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

static int	get_median(t_stack curr, int high)
{
	int	*cpy;
	int	tmp;

	if (!(cpy = ft_intcpy(curr.stack, high + 1)))
		ft_exit_malloc();
	ft_quicksort(cpy, 0, high);
	tmp = cpy[high / 2];
	free (cpy);
	return (tmp);
}

static int	ps_partition(t_env *env, int high, int id, int *rot)
{
	int	pivot;
	int	i;
	int	push;
	int	max_push;

	if (id == 0)
		pivot = get_median(env->a, high);
	else
		pivot = get_median(env->b, high);
	i = 0;
	push = 0;
	max_push = (high + 1) % 2 + (high + 1) / 2;
	while (i <= high && push < max_push)
	{	
		if (id == 0 && *env->a.stack <= pivot && ++push)
			pb(env, ps_save);
		else if (id == 1 && *env->b.stack > pivot && ++push)
			pa(env, ps_save);
		else if (id == 0 && *env->a.stack > pivot && ++(*rot))
			ra(env, ps_save);
		else if (id == 1 && *env->b.stack <= pivot && ++(*rot))
			rb(env, ps_save);
		++i;
	}
	return (push);
}

static void	ps_inverse_rotate(t_env *env, int id, int rot)
{
	int	lim;

	lim = id ? env->b.size : env->a.size;
	if (rot > lim / 2)
	{
		while (lim - rot++)
		{
			if (id == 0)
				ra(env, ps_save);
			else
				rb(env, ps_save);
		}
	}
	else
	{
		while (rot--)
		{
			if (id == 0)
				rra(env, ps_save);
			else
				rrb(env, ps_save);
		}
	}
}

void		ps_quicksort(t_env *env, int high, int id)
{
	int	p_i;
	int	rot;

	if ((id == 0 && ps_is_sorted(env->a, high))
			|| (id == 1 && ps_is_back_sorted(env->b, high)))
		return ;
	if (high  < 3)
		return (ps_sort_case(env, high, id));
	rot = 0;
	p_i = ps_partition(env, high, id, &rot);
	ps_inverse_rotate(env, id, rot);
	ps_quicksort(env, high - p_i, (id == 0 ? 0 : 1));
	ps_quicksort(env, p_i - 1, (id == 0 ? 1 : 0));
	ps_push_n_elem(env, p_i, id);
}
