/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:15:59 by llion             #+#    #+#             */
/*   Updated: 2023/03/01 16:08:18 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(t_pile *a)
{
	t_pile	*tmp;
	int		max;

	tmp = a;
	if (tmp)
		max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_first_index(t_piles *p, int target)
{
	t_pile *tmp;
	int i;

	i = 0;
	tmp = p->a;
	while (tmp)
	{
		if (tmp->value <= target)
			return (i);
		tmp = tmp->next;
		i++;	
	}
	return (0);
}

int	get_last_index(t_piles *p, int target)
{
	t_pile *tmp;
	int index;
	int i;

	i = 0;
	index = 0;
	tmp = p->a;
	while (tmp)
	{
		if (tmp->value <= target)
			index = i;
		i++;	
		tmp = tmp->next;
	}
	return (index);
}

int	get_index_max(t_pile *p)
{
	int	i;
	int max;
	t_pile *tmp;

	tmp = p;
	i = 0;
	max = get_max(p);
	while (tmp)
	{
		if (tmp->value == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	rotate_or_reverse_rotate(int len, t_piles *p, int target)
{
	int	last_index;
	int	first_index;
	//int	len;
	int	i;

	i = 0;
	//len = pilesize(p->a);
	last_index = len - get_last_index(p, target);
	first_index = get_first_index(p, target);
	if (first_index < last_index)
	{
		while (i < first_index)
		{
			ra(p);
			i++;
		}
	}
	else
	{
		while (i < last_index)
		{
			rra(p);
			i++;
		}
	}
	pb(p);
}

void	rotate_or_reverse_rotate_max(t_piles *p)
{
	int	index;
	int	len;
	int	i;

	i = 0;
	len = pilesize(p->b);
	index = get_index_max(p->b);
	if (index < len / 2)
	{
		while (i < index)
		{
			rb(p);
			i++;
		}
	}
	else
	{
		while (i < len - index)
		{
			rrb(p);
			i++;
		}
	}
	pa(p);
}

void	pre_sort(t_piles *p)
{
	int i = 0;
	int j = 1;
	int	div = 11;
	int	target;
	int	len;
	int *tab; 

	len = pilesize(p->a);
	tab = put_in_tab(p->a);
	while (j <= (div + 1))
	{
		sort_tab(tab);
		i = 0;
		target = tab[((len / div) * j) - 1];
		while (i < len / div)
		{
			rotate_or_reverse_rotate(len, p, target);
			i++;
		}
		//ft_printf("len: %d\ndiv: %d\ntarget: %d\n", len, div, target);
		j++;
	}
}

void	sort(t_piles *p)
{
	int	max;

	while (p->b)
	{
		max = get_max(p->b);
		rotate_or_reverse_rotate_max(p);
	}
}

int	main(int argc, char *argv[])
{
	t_piles	*p;

	p = malloc(sizeof(t_piles));
	init_piles(p);
	if (argc > 1)
	{
		valid_args(argv, p);
		if (is_sort(p->a) || p->a == NULL || !duplicates(p->a))
			ft_error();
	}
	else
		return (0);
	pre_sort(p);
	sort(p);
	//print_ps(p);
	free_pile(p->a);
	free_pile(p->b);
	free(p);
	return (0);
}

