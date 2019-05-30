/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:46:16 by brichard          #+#    #+#             */
/*   Updated: 2019/05/30 11:58:58 by brichard         ###   ########.fr       */
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

int		get_median(t_stack curr, int high)
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
//#include <unistd.h>
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
//	ft_printf("pivot = %d\n", pivot);
//	ft_printf("Nelem %d\n", high + 1);
	//sleep(2);
	i = 0;
	push = 0;
	max_push =  ((high + 1) % 2 == 0 ? 0 : 1) + (high + 1) / 2;
	while (i <= high && push < max_push)
	{	
		if (id == 0 && *env->a.stack <= pivot && ++push)
			pb(env);
		else if (id == 1 && *env->b.stack > pivot && ++push)
			pa(env);
		else if (id == 0 && *env->a.stack > pivot && ++(*rot))
			ra(env);
		else if (id == 1 && *env->b.stack <= pivot && ++(*rot))
			rb(env);
		++i;
	}
	return (push);
}

void		ps_inverse_rotate(t_env *env, int high, int id, int rot)
{
//	ft_printf("rot %d\n", rot);
	//sleep(1);
	(void)high;
	while (rot)
	{
		if (id == 0)
			rra(env);
		else
			rrb(env);
		--rot;
	}
}

void		ps_quicksort(t_env *env, int high, int id)
{
	int	p_i;
	int	rot;

//	if (id == 0)
//		ft_printf("quick A\n");
//	else
//		ft_printf("quick B\n");
	//sleep(1);
	if (high  < 3)
		return (ps_sort_case(env, high, id));
	rot = 0;
	p_i = ps_partition(env, high, id, &rot);
	ps_inverse_rotate(env, high, id, rot);
	ps_quicksort(env, high - p_i, (id == 0 ? 0 : 1));
	ps_quicksort(env, p_i - 1, (id == 0 ? 1 : 0));
//	if (id == 0)
//		ft_printf("roll A\n");
//	else
//		ft_printf("roll B\n");
	//sleep(1);
	while (p_i)
	{
		if (id == 0)
			pa(env);
		else
			pb(env);
		--p_i;
	}
}
