/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:12:32 by llion             #+#    #+#             */
/*   Updated: 2023/03/03 15:34:58 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*put_in_tab(t_pile *p)
{
	t_pile *tmp;
	int		*tab;
	int		i;
	int		len;

	i = 0;
	tmp = p;
	len = pilesize(p);
	tab = malloc(sizeof(int) * len);
	while (i < len)
	{
		tab[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}

void	sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_div_value(int *tab, int index, int len, int div)
{
	int	target;
	int	flag;

	(void)index;
	flag =  len / div;
	target = tab[flag];
	return (target);	
}
