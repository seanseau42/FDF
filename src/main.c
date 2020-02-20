/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:06:56 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/16 16:04:24 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	refresh_window(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->size.x, mlx->size.y);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
			&mlx->img.s_l, &mlx->img.endian);
	projection(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	print_info(mlx);
}

int		checkvalidmap(char *file)
{
	int		fd;

	errno = 0;
	fd = open(file, O_RDWR);
	if (fd < 0)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

void	init(t_mlx *mlx)
{
	mlx->size.x = 1024;
	mlx->size.y = 768;
	mlx->proj.zoom = 1;
	mlx->proj.moved = 0;
	mlx->proj.angle = 0;
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	init(&mlx);
	if (ac == 2 && checkvalidmap(av[1]) == 1)
	{
		ft_read(&mlx, av[1]);
		mlx.ptr = mlx_init();
		mlx.win = mlx_new_window(mlx.ptr, mlx.size.x, mlx.size.y, "FDF");
		mlx.img.ptr = mlx_new_image(mlx.ptr, mlx.size.x, mlx.size.y);
		mlx.img.data = (int *)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp,
				&mlx.img.s_l, &mlx.img.endian);
		set_projection(&mlx, 2);
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
		print_info(&mlx);
		mlx_hook(mlx.win, 2, 0, key_press, &mlx);
		mlx_loop(mlx.ptr);
	}
	ft_putstr("Usage : ./fdf <filename>\n");
	return (0);
}
