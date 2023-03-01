/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:16:40 by llion             #+#    #+#             */
/*   Updated: 2023/02/15 13:53:15 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct	s_pile
{
	int				value;
	int				len;
	struct s_pile	*next;
}					t_pile;

typedef struct	s_piles
{
	t_pile			*a;
	t_pile			*b;
}					t_piles;


/* ------------------- UTILS ------------------*/

void	print_ps(t_piles *p);
int		tab_len(char **tab);
void	ft_error();
void	valid_args(char **argv, t_piles *p);
int		duplicates(t_pile *p);
int		is_sort(t_pile *p);
int		ft_lstmax(t_pile *pp);

/* ------------------- FREE ------------------*/

void	free_pile(t_pile *p);
void	free_tab(char **tab);

/* ------------------- PILES ------------------*/

t_pile	*pilenew(int value);
t_pile	*pilelast(t_pile *pile);
int		pilesize(t_pile *p);
void	pileadd_back(t_pile **pile, t_pile *nouv);
void	put_list(t_piles *p, int arg_num, char **numbers);

/* ------------------- SORT IN TAB ------------------*/

int		*put_in_tab(t_pile *p);
void	sort_tab(int *tab);
int		get_div_value(int *tab, int index, int len, int div);

/* ------------------- SORTS ------------------*/

void	init_piles(t_piles *piles);
void	swap(t_pile **pile);
void	push(t_pile **pile_a, t_pile **pile_b);
void	rotate(t_pile **pile);
void	reverse_rotate(t_pile **pile);
void	sa(t_piles *piles);
void	sb(t_piles *piles);
void	ss(t_piles *piles);
void	pa(t_piles *p);
void	pb(t_piles *p);
void	ra(t_piles *piles);
void	rb(t_piles *piles);
void	rr(t_piles *piles);
void	rra(t_piles *piles);
void	rrb(t_piles *piles);
void	rrr(t_piles *piles);

#endif
