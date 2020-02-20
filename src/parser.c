/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 14:21:43 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 14:16:46 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	freesplit(char **split, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i != mlx->map.size_x)
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
}

int		checkvalidsplit(char **split, t_mlx *mlx)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	if (i < mlx->map.size_x)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		ft_putstr("Usage : ./fdf <filename>\n");
		close_window(mlx);
	}
	return (1);
}

void	filltab(t_mlx *mlx, char *file)
{
	char	*line;
	char	**split;

	mlx->map.fd = open(file, O_RDWR);
	mlx->map.y = -1;
	while (++mlx->map.y != mlx->map.size_y)
	{
		get_next_line(mlx->map.fd, &line);
		split = ft_strsplit(line, ' ');
		if (checkvalidsplit(split, mlx) == -1)
			return ;
		mlx->map.x = -1;
		while (++mlx->map.x != mlx->map.size_x)
		{
			if (ft_atoi(split[mlx->map.x]) != 0)
				mlx->map.tab[mlx->map.y][mlx->map.x] = ft_atoi(split
						[mlx->map.x]);
			else
				mlx->map.tab[mlx->map.y][mlx->map.x] = 0;
		}
		ft_strdel(&line);
		freesplit(split, mlx);
	}
	close(mlx->map.fd);
}

int		**malloctab(t_mlx *mlx)
{
	int		**tab;
	int		i;

	if (!(tab = (int **)malloc(sizeof(int *) * (mlx->map.size_y))))
		return (0);
	i = 0;
	while (i < mlx->map.size_y)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * (mlx->map.size_x))))
			return (0);
		i++;
	}
	return (tab);
}

void	ft_read(t_mlx *mlx, char *file)
{
	char	*line;
	int		i;

	i = -1;
	mlx->map.fd = open(file, O_RDWR);
	mlx->map.size_y = 0;
	while (get_next_line(mlx->map.fd, &line))
	{
		mlx->map.size_y++;
		ft_strdel(&line);
	}
	close(mlx->map.fd);
	mlx->map.fd = open(file, O_RDWR);
	get_next_line(mlx->map.fd, &line);
	close(mlx->map.fd);
	mlx->map.size_x = ft_countwords(line, ' ');
	ft_strdel(&line);
	mlx->map.tab = malloctab(mlx);
	filltab(mlx, file);
	if (mlx->map.size_x > 100 || mlx->map.size_y > 100)
		mlx->proj.zoom = 10;
}
