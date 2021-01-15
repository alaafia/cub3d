/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:44:56 by alaafia           #+#    #+#             */
/*   Updated: 2021/01/14 18:20:41 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_char_flag(t_config *con)
{
	int i;

	i = 0;
	if (con->flag == 0 || con->flag == '0')
	{
		if (con->flag == 0)
			while (i++ < con->width - 1)
			{
				ft_putchar(' ');
				con->ret++;
			}
		else
		{
			if (con->specifier == '%')
				while (i++ < con->width - 1)
				{
					ft_putchar('0');
					con->ret++;
				}
		}
	}
}

void	ft_show_char(t_config *con)
{
	int	i;

	ft_show_char_flag(con);
	if (con->specifier == '%')
		ft_putchar('%');
	else
		ft_putchar(va_arg(*(con->vargs), int));
	i = 0;
	if (con->flag == '-')
		while (i++ < con->width - 1)
		{
			ft_putchar(' ');
			con->ret++;
		}
	con->ret++;
}
