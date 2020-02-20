/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_press.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/09 16:22:59 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 14:10:14 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

int		key_press(int key, t_mlx *mlx)
{
	if (key == 34)
		set_projection(mlx, 2);
	if (key == 35)
		set_projection(mlx, 0);
	if (key == 116 && mlx->proj.type != 1)
		mlx->proj.ky--;
	if (key == 121 && mlx->proj.type != 1)
		mlx->proj.ky++;
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move(mlx, key);
	if (key == 53)
		close_window(mlx);
	refresh_window(mlx);
	return (0);
}
