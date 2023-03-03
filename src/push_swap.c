/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:15:59 by llion             #+#    #+#             */
/*   Updated: 2023/03/03 15:42:05 by llion            ###   ########.fr       */
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

void	rotate_or_reverse_rotate(t_piles *p, int target)
{
	int	last_index;
	int	first_index;
	int	pilelen;
	int	i;

	i = 0;
	pilelen = pilesize(p->a);
	last_index = pilelen - get_last_index(p, target);
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

void	pre_sort(t_piles *p, int len)
{
	int i = 0;
	int j = 1;
	int	div;
	int	target;
	int *tab; 

	if (len > 5 && len <= 100)
		div = 7;
	else if (len > 100)
		div = 14;
	else 
		div = 5;
	tab = put_in_tab(p->a);
	while (j <= (div + 1))
	{
		sort_tab(tab, len);
		i = 0;
		target = tab[((len / div) * j) - 1];
		while (i < (len / div))
		{
			rotate_or_reverse_rotate(p, target);
			i++;
		}
		j++;
	}
	free(tab);
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

void	sort2(t_piles *p)
{
	if (p->a->value > p->a->next->value)
		ra(p);
}

// TODO CAS PARTICULIERS

int	main(int argc, char *argv[])
{
	t_piles	*p;
	int		len;

	p = malloc(sizeof(t_piles));
	init_piles(p);
	if (argc > 1)
	{
		valid_args(argv, p);
		if (is_sort(p->a))
			return (0);
		if (p->a == NULL || !duplicates(p->a, p))
			ft_error(p->a, p);
	}
	else
		return (0);
	len = pilesize(p->a);
	if (len == 2)
	{
		sort2(p);
		return (0);
	}
	if (len == 3)
		return (0);
	pre_sort(p, len);
	sort(p);
	free_pile(p->a);
	free_pile(p->b);
	if (p)
		free(p);
	return (0);
}

