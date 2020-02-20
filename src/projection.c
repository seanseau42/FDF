/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   projection.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 16:46:02 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 14:17:26 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	putpixel(int x, int y, int color, t_mlx *mlx)
{
	if (is_in_screen(y * mlx->size.x + x + mlx->proj.pos, mlx) == 1)
		mlx->img.data[y * mlx->size.x + x + mlx->proj.pos] = color;
	if (y * mlx->size.x + x + mlx->proj.pos < mlx->proj.higherpixel)
		mlx->proj.higherpixel = (y * mlx->size.x + x + mlx->proj.pos);
	if (y * mlx->size.x + x + mlx->proj.pos > mlx->proj.lowerpixel)
		mlx->proj.lowerpixel = (y * mlx->size.x + x + mlx->proj.pos);
}

void	draw_line(t_mlx *mlx, t_dot *d1, t_dot *d2)
{
	t_dot		pas;
	t_draw		line;
	int			e2;

	line.sx = d1->x < d2->x ? 1 : -1;
	line.sy = d1->y < d2->y ? 1 : -1;
	pas.x = abs(d2->x - d1->x);
	pas.y = abs(d2->y - d1->y);
	line.err = (pas.x > pas.y ? pas.x : -pas.y) / 2;
	while (d1->x != d2->x || d1->y != d2->y)
	{
		putpixel(d1->x, d1->y, 0xFFFFFF, mlx);
		e2 = line.err;
		if (e2 > -pas.x)
		{
			line.err -= pas.y;
			d1->x += line.sx;
		}
		if (e2 < pas.y)
		{
			line.err += pas.x;
			d1->y += line.sy;
		}
	}
}

void	proj_vert(t_mlx *mlx, int j, int i, int k)
{
	t_dot	d1;
	t_dot	d2;

	mlx->pt.j = j;
	mlx->pt.i = i;
	d1.x = (i * mlx->proj.ix) + (j * mlx->proj.jx) + (k * mlx->proj.kx) + 250;
	d1.y = (i * mlx->proj.iy) + (j * mlx->proj.jy) + (k * mlx->proj.ky) + 250;
	if ((mlx->pt.j + 1) != mlx->map.size_y)
	{
		d2.x = (mlx->pt.i * mlx->proj.ix) + ((mlx->pt.j + 1) * mlx->proj.jx) +
			(mlx->map.tab[mlx->pt.j + 1][mlx->pt.i] * mlx->proj.kx) + 250;
		d2.y = (mlx->pt.i * mlx->proj.iy) + ((mlx->pt.j + 1) * mlx->proj.jy) +
			(mlx->map.tab[mlx->pt.j + 1][mlx->pt.i] * mlx->proj.ky) + 250;
		draw_line(mlx, &d1, &d2);
	}
}

void	proj_horizontal(t_mlx *mlx, int i, int j, int k)
{
	t_dot	d1;
	t_dot	d2;

	mlx->pt.i = i;
	mlx->pt.j = j;
	d1.x = (j * mlx->proj.ix) + (i * mlx->proj.jx) + (k * mlx->proj.kx) + 250;
	d1.y = (j * mlx->proj.iy) + (i * mlx->proj.jy) + (k * mlx->proj.ky) + 250;
	if ((mlx->pt.j + 1) != mlx->map.size_x)
	{
		d2.x = ((mlx->pt.j + 1) * mlx->proj.ix) + (mlx->pt.i * mlx->proj.jx) +
			(mlx->map.tab[mlx->pt.i][mlx->pt.j + 1] * mlx->proj.kx) + 250;
		d2.y = ((mlx->pt.j + 1) * mlx->proj.iy) + (mlx->pt.i * mlx->proj.jy) +
			(mlx->map.tab[mlx->pt.i][mlx->pt.j + 1] * mlx->proj.ky) + 250;
		draw_line(mlx, &d1, &d2);
	}
}

void	projection(t_mlx *mlx)
{
	int i;
	int j;

	i = -1;
	while (++i < mlx->map.size_y)
	{
		j = -1;
		while (++j < mlx->map.size_x)
		{
			proj_horizontal(mlx, i, j, mlx->map.tab[i][j]);
			proj_vert(mlx, i, j, mlx->map.tab[i][j]);
		}
	}
}
