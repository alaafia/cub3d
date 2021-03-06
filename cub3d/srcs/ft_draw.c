/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:06:13 by alaafia           #+#    #+#             */
/*   Updated: 2021/01/15 15:29:24 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		my_atoi(char **str)
{
	int	num;

	num = 0;
	while (**str >= '0' && **str <= '9')
		num = (num * 10) + (*(*str)++ - '0');
	return (num);
}

void	ft_drawspritelines(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->x = sprite->drawstartx;
	while (sprite->x < sprite->drawendx)
	{
		sprite->tex_x = (int)((sprite->x - (-sprite->spritewidth / 2 +
		sprite->spritescreenx)) * mlx->tex.sp_w / sprite->spritewidth);
		sprite->y = sprite->drawstarty;
		if (sprite->transformy > 0 && sprite->x >= 0 &&
				sprite->x < mlx->win.width && sprite->transformy
					< (float)mlx->zbuffer[sprite->x])
			while (sprite->y < sprite->drawendy)
			{
				sprite->d = (sprite->y) * 256 - mlx->win.height * 128 +
				sprite->spriteheight * 128;
				sprite->tex_y = ((sprite->d * mlx->tex.sp_h) /
				sprite->spriteheight) / 256;
				if (*(mlx->tex.sp_data + sprite->tex_x + sprite->tex_y *
				mlx->tex.sp_sl / 4))
					*(mlx->tex.img_data + sprite->x + sprite->y *
					mlx->tex.size_line / 4) = *(mlx->tex.sp_data +
					sprite->tex_x + sprite->tex_y * mlx->tex.sp_sl / 4);
				sprite->y++;
			}
		sprite->x++;
	}
}

void	ft_checkmap_end(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			if (x != 0 && y != 1 && mlx->worldmap[x][y] != '1'
					&& mlx->worldmap[x][y] != '7')
				checkmap(mlx, x, y);
			y++;
		}
		x++;
	}
}

int		ft_count_sprotes(t_mlx *mlx)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < mlx->max_x)
	{
		j = 0;
		while (j < mlx->max_y)
		{
			if (mlx->worldmap[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		ft_draw(t_mlx *mlx, int x)
{
	long int color;

	color = RGB_RED;
	mlx->wall.lineheight = (int)(mlx->win.height / mlx->ray.perpwalldist);
	mlx->wall.drawstart = -mlx->wall.lineheight / 2 + mlx->win.height / 2;
	if (mlx->wall.drawstart < 0)
		mlx->wall.drawstart = 0;
	mlx->wall.drawend = mlx->wall.lineheight / 2 + mlx->win.height / 2;
	if (mlx->wall.drawend >= mlx->win.height)
		mlx->wall.drawend = mlx->win.height - 1;
	ft_texture(mlx, x);
	return (0);
}
