/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:52:57 by alaafia           #+#    #+#             */
/*   Updated: 2021/01/14 18:49:09 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"

typedef struct	s_config{
	int			i;
	int			ret;
	char		flag;
	int			width;
	int			precision;
	char		specifier;
	int			has_precision;
	long		*nbr;
	int			*sign;
	int			*length;
	int			*n_zeroes;
	va_list		*vargs;
}				t_config;
int				ft_printf(char const *format, ...);
void			ft_parse(char *format, t_config *con);
void			ft_reader(char *format, t_config *con);
void			ft_show(t_config *con);
void			ft_show_pointer(t_config *con);
void			ft_show_string(t_config *con);
void			ft_show_hex(t_config *con);
void			ft_show_nbr(t_config *con);
void			ft_show_char(t_config *con);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_hexlen(size_t n);
void			ft_putnbr(int n);
void			ft_putunbr(unsigned int n);
int				ft_intlen(unsigned int n);
void			ft_puthex(size_t n, int cap);
#endif
