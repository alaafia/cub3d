/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:21:56 by alaafia           #+#    #+#             */
/*   Updated: 2021/01/15 15:17:00 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_hexlen(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	unsigned int	tmp;

	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		ft_putchar('-');
	}
	if (tmp / 10 > 0)
		ft_putnbr(tmp / 10);
	ft_putchar('0' + tmp % 10);
}

void	ft_putunbr(unsigned int n)
{
	if (n / 10 > 0)
		ft_putunbr(n / 10);
	ft_putchar('0' + n % 10);
}
