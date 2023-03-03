/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:36:26 by llion             #+#    #+#             */
/*   Updated: 2023/03/03 15:14:50 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	verif_int(long int number, int sign, t_piles *p)
{
	if (number > 2147483647 || number < -2147483648)
	{
		ft_error(p->a, p);
		exit(0);
	}
	else
	{
		if (sign > 0)
			return (number);
		else
			return (-number);
	}
}

static void	verif_letters(const char *str, int i, t_piles *p)
{
	if (!(str[i] >= '0' && str[i] <= '9')
		&& (str[i] != '-' && str[i] != '+'))
		ft_error(p->a, p);
	if ((str[i] == '-' || str[i] == '+') && str[i]
		&& (!(str[i + 1] >= '0' && str[i + 1] <= '9')))
		ft_error(p->a, p);
}

int	ft_atoi_ps(const char *str, t_piles *p)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\v'))
		i++;
	verif_letters(str, i, p);
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (verif_int(number, sign, p));
}
