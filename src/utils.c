/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 11:52:47 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 14:16:23 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_window(t_mlx *mlx, char *str, int y)
{
	mlx_string_put(mlx->ptr, mlx->win, 0, y, 0xFFFFFF, str);
}

void	print_info(t_mlx *mlx)
{
	put_window(mlx, "Deplacement            [ARROW_KEYS]", 0);
	put_window(mlx, "Projection isometrique [I]", 15);
	put_window(mlx, "Projection parallelle  [P]", 30);
	put_window(mlx, "Fermer la fenetre      [ESC]", 60);
	put_window(mlx, "Changer le relief      [PGUP/PGDWN]", 45);
}

int		close_window(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

void	reset(t_mlx *mlx)
{
	mlx->proj.pos = 0;
	mlx->proj.higherpixel = mlx->size.x * mlx->size.y;
	mlx->proj.lowerpixel = 0;
}

int		is_in_screen(int pos, t_mlx *mlx)
{
	int		pix;

	pix = 511;
	if (!(pos > 0 && pos < (mlx->size.x * mlx->size.y)))
		return (0);
	while (!(pos >= pix - 512 && pos <= pix + 512))
		pix += 1024;
	if (!(pos - mlx->proj.moved > pix - 512 &&
				pos - mlx->proj.moved < pix + 512))
		return (0);
	return (1);
}
