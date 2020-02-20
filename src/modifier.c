/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modifier.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/09 16:00:26 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 14:22:30 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move(t_mlx *mlx, int x)
{
	if (x == 123)
	{
		mlx->proj.moved += -8;
		mlx->proj.pos += -8;
		mlx->proj.lowerpixel += -8;
	}
	if (x == 124)
	{
		mlx->proj.moved += 8;
		mlx->proj.pos += 8;
		mlx->proj.lowerpixel += 8;
	}
	if (x == 125)
	{
		mlx->proj.pos += 4096;
		mlx->proj.lowerpixel += 4096;
		mlx->proj.higherpixel += 4096;
	}
	if (x == 126)
	{
		mlx->proj.pos += -4096;
		mlx->proj.lowerpixel += -4096;
	}
}

void	set_projection_bis(t_mlx *mlx, int x)
{
	if (x == 2)
	{
		mlx->proj.ix = 30 / mlx->proj.zoom;
		mlx->proj.iy = 10 / mlx->proj.zoom;
		mlx->proj.jx = -20 / mlx->proj.zoom;
		mlx->proj.jy = 15 / mlx->proj.zoom;
	}
	mlx->proj.type = 0;
	mlx->proj.kx = 0;
	mlx->proj.ky = -2;
}

void	set_projection(t_mlx *mlx, int x)
{
	if (x != 0)
		set_projection_bis(mlx, x);
	else
	{
		mlx->proj.type = 1;
		mlx->proj.ix = 10 / mlx->proj.zoom;
		mlx->proj.iy = 0;
		mlx->proj.jx = 0;
		mlx->proj.jy = 10 / mlx->proj.zoom;
		mlx->proj.kx = 0;
		mlx->proj.ky = 0;
	}
	mlx->proj.pos = 0;
	mlx->proj.moved = 0;
	mlx->proj.higherpixel = mlx->size.x * mlx->size.y;
	mlx->proj.lowerpixel = 0;
	mlx->proj.angle = 0;
	projection(mlx);
}
