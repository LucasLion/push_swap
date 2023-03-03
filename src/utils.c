/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:31:55 by llion             #+#    #+#             */
/*   Updated: 2023/03/03 15:34:56 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_ps(t_piles *p)
{
	ft_printf("\n");
	while (p->a)
	{
		ft_printf("%d\n", p->a->value);
		p->a = p->a->next;
	}
	ft_printf("pile A\n\n");
	while (p->b)
	{
		ft_printf("%d\n", p->b->value);
		p->b = p->b->next;
	}
	ft_printf("pile B\n\n");
}

int		tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_error(t_pile *p, t_piles *pp)
{
	write(2, "Error\n", 6);
	free_pile(p);
	free(pp);
	exit(0);
}

int	is_sort(t_pile *p)
{
	t_pile *head;

	head = p;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	duplicates(t_pile *p, t_piles *pp)
{
	t_pile *tmp1;
	t_pile *tmp2;
	
	tmp1 = p;
	while (tmp1)
	{
		tmp2 = tmp1;
		while (tmp2->next)
		{
			if (tmp1->value == tmp2->next->value)
				ft_error(p, pp);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void	valid_args(char **argv, t_piles *p)
{
	char	**tab;
	int		len;
	int		i;

	i = 1;
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		len = tab_len(tab);
		put_list(p, len, tab);
		free_tab(tab);
		i++;
	}
}

int	ft_lstmax(t_pile *pp)
{
	int	max;
	t_pile *p;

	p = pp;
	max = p->value;
	while (p)
	{
		if (p->value > max)
			max = p->value;
		p = p->next;
	}
	return (max);
}

void	init_piles(t_piles *p)
{
	p->a = NULL;
	p->b = NULL;
}

int	numlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		n = n * -1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
