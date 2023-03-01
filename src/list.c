/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:34:29 by llion             #+#    #+#             */
/*   Updated: 2023/02/01 19:25:01 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*pilenew(int value)
{
	t_pile	*el;

	el = malloc(sizeof(t_pile));
	if (el == NULL)
		return (0);
	el->value = value;
	el->next = NULL;
	return (el);
}

t_pile	*pilelast(t_pile *pile)
{
	if (pile)
	{
		while (pile->next)
			pile = pile->next;
	}
	return (pile);
}

void	pileadd_back(t_pile **pile, t_pile *new)
{
	t_pile	*current;

	if (*pile == 0)
		*pile = new;
	else
	{
		current = pilelast(*pile);
		current->next = new;
	}
}

void	put_list(t_piles *p, int arg_num, char **numbers)
{
	int		i;
	int		num;
	t_pile	*new;

	i = 0;
	while (i < arg_num)
	{
		num = ft_atoi(numbers[i]);
		new = pilenew(num);
		pileadd_back(&p->a, new);
		i++;
	}
}

int	pilesize(t_pile *p)
{
	int	i;

	i = 0;
	if (p)
	{
		i++;
		while (p->next != 0)
		{
			p = p->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}

