/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:13 by llion             #+#    #+#             */
/*   Updated: 2023/02/01 17:54:37 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_piles *p)
{
	rotate(&p->a);
	ft_printf("ra\n");
}

void	rb(t_piles *p)
{
	rotate(&p->b);
	ft_printf("rb\n");
}

void	rr(t_piles *p)
{
	rotate(&p->a);
	rotate(&p->b);
	ft_printf("rr\n");
}

void	rra(t_piles *p)
{
	reverse_rotate(&p->a);
	ft_printf("rra\n");
}

void	rrb(t_piles *p)
{
	reverse_rotate(&p->b);
	ft_printf("rrb\n");
}
