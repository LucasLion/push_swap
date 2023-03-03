/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:41:56 by llion             #+#    #+#             */
/*   Updated: 2023/03/03 15:34:53 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_pile **pile)
{
	t_pile	*tmp;

	if (*pile && (*pile)->next)
	{
		tmp = *pile;
		*pile = tmp->next;
		tmp->next = tmp->next->next;
		(*pile)->next = tmp;
	}
	else
		return ;
}

void	push(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*head_a;

	head_a = *pile_a;
	if (*pile_b == NULL)
	{
		*pile_a = head_a->next;
		*pile_b = head_a;
		head_a->next = NULL;
	}
	else
	{
		if (*pile_a)
		{
			*pile_a = head_a->next;
			head_a->next = *pile_b;
			*pile_b = head_a;
		}
	}
}

void	rotate(t_pile **pile)
{
	if (*pile && (*pile)->next)
	{
		t_pile	*head;
		t_pile	*last;

		head = *pile;
		*pile = (*pile)->next;
		last = pilelast(*pile);
		last->next = head;
		head->next = NULL;
	}
}

void	reverse_rotate(t_pile **pile)
{
	if (*pile)
	{
		t_pile	*head;
		t_pile	*last;
		t_pile	*second_last;

		head = *pile;
		last = *pile;
		second_last = NULL;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		if (second_last)
		{
			second_last->next = NULL;
			last->next = head;
			*pile = last;
		}
	}
}

void	rrr(t_piles *p)
{
	reverse_rotate(&p->a);
	reverse_rotate(&p->b);
	ft_printf("rrr\n");
}
