/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:25:21 by llion             #+#    #+#             */
/*   Updated: 2023/02/13 14:34:09 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_piles *p)
{
	swap(&p->a);
	ft_printf("sa\n");
}

void	sb(t_piles *p)
{
	swap(&p->b);
	ft_printf("sb\n");
}

void	ss(t_piles *p)
{
	swap(&p->a);
	swap(&p->b);
	ft_printf("ss\n");
}

void	pa(t_piles *p)
{
	push(&p->b, &p->a);
	ft_printf("pa\n");
}

void	pb(t_piles *p)
{
	push(&p->a, &p->b);
	ft_printf("pb\n");
}
