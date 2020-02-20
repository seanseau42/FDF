/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 14:51:14 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 14:10:05 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <string.h>
# include <errno.h>

typedef struct		s_dot
{
	int				x;
	int				y;
}					t_dot;

typedef struct		s_bresenham
{
	int				i;
	int				j;
	int				sx;
	int				sy;
	int				err;
}					t_draw;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_projection
{
	double				ix;
	double				iy;
	double				jx;
	double				jy;
	double				kx;
	double				ky;
	int					pos;
	int					higherpixel;
	int					lowerpixel;
	int					type;
	int					zoom;
	int					moved;
	short				angle;
}					t_proj;

typedef struct		s_int_map
{
	int				fd;
	int				**tab;
	int				size_x;
	int				size_y;
	int				x;
	int				y;
}					t_map;

typedef struct		s_mlx_img
{
	void			*ptr;
	int				*data;
	int				s_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_window_size
{
	int				x;
	int				y;
}					t_win;

typedef struct		s_mlx
{
	void			*win;
	void			*ptr;
	t_img			img;
	t_map			map;
	t_proj			proj;
	t_draw			pt;
	t_dot			dot;
	t_win			size;
}					t_mlx;

void				freesplit(char **split, t_mlx *mlx);
int					checkvalidsplit(char **split, t_mlx *mlx);
void				filltab(t_mlx *mlx, char *file);
int					**malloctab(t_mlx *mlx);
void				ft_read(t_mlx *mlx, char *file);

void				projection(t_mlx *mlx);
void				proj_horizontal(t_mlx *mlx, int i, int j, int k);
void				proj_vert(t_mlx *mlx, int i, int j, int k);
void				draw_line(t_mlx *mlx, t_dot *d1, t_dot *d2);
void				putpixel(int x, int y, int color, t_mlx *mlx);

void				set_projection(t_mlx *mlx, int x);
void				move(t_mlx *mlx, int x);
void				set_projection_bis(t_mlx *mlx, int x);

int					key_press(int key, t_mlx *mlx);

void				put_window(t_mlx *mlx, char *str, int y);
void				print_info(t_mlx *mlx);
int					close_window(t_mlx *mlx);
void				reset(t_mlx *mlx);
int					is_in_screen(int pos, t_mlx *mlx);

void				refresh_window(t_mlx *mlx);
int					checkvalidmap(char *file);

#endif
