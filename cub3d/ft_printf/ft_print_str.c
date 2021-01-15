/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:15:04 by alaafia           #+#    #+#             */
/*   Updated: 2021/01/14 18:20:50 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void	ft_puthex(size_t n, int cap)
{
	int	tmp;

	if (n / 16 > 0)
		ft_puthex(n / 16, cap);
	tmp = n % 16;
	if (tmp >= 0 && tmp <= 9)
		ft_putchar('0' + tmp);
	else
	{
		if (cap)
			ft_putchar(tmp - 10 + 'A');
		else
			ft_putchar(tmp - 10 + 'a');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
