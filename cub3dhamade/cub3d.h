#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include <errno.h>
# include "mlx.h"
# include "./src/get_next_line.h"
# include "./src/libftt/libft.h"

# define CUB 64

typedef struct		s_rayfacing
{
	int			up;
	int			down;
	int			right;
	int			left;
}					t_rayfacing;

typedef struct		s_sprite
{
	int			x;
	int			y;
	int			width;
	int			height;
	double		size;
	double		angle;
	double		it_x;
	double		it_y;
	double		distance;
}					t_sprite;

typedef struct		s_rgb
{
	double		r;
	double		g;
	double		b;
	int			was_here;
}					t_rgb;

typedef struct		s_texture
{
	int			tx_width;
	int			tx_height;
	void		*tx_xpm_ptr[5];
	int			*tx_ptr[5];
	char		*texture_ptah[4];
}					t_texture;

typedef struct		s_bitmap
{
	int				width;
	int				height;
	int				bitcount;
	int				width_in_bytes;
	int				imagesize;
	int				bisize;
	int				bfofbits;
	int				filesize;
	int				biplanes;
	unsigned char	header[54];
	int				fd;
}					t_bitmap;

t_bitmap			g_bitmap;
t_rayfacing			g_rayfacing;
t_sprite			g_sprite[100];
t_texture			g_texture;
t_rgb				g_rgb[2];
char				*g_sprite_path;
int					g_win_width;
int					g_win_height;
char				g_map[2000][2000];
void				*g_mlx_ptr;
void				*g_win_ptr;
void				*g_img_ptr;
void				*g_img_ptr2d;
void				*g_xpm_ptr;
int					*g_tx_ptr;
int					*g_pxl_ptr2d;
int					*g_pxl_ptr;
double				g_int_col[20000];
float				g_xplayer;
float				g_yplayer;
int					g_up;
int					g_down;
int					g_left;
int					g_right;
int					g_nleft;
int					g_nright;
double				g_vision_player;
double				g_slice_height;
double				g_distance_to_p;
int					g_wall_to_p;
int					g_a;
float				g_x;
float				g_y;
int					g_k;
int					g_nbr_sprite;
int					g_i;
int					g_j[2000];
int					g_fov;
int					g_save;
int					g_d;
int					g_l;

float				horizontal_intersections(double angle);
float				vertical_intersections(double angle);
float				find_distance(float x1, float x2, float y1, float y2);
void				rayfacing(double angle);
double				normalize_angle(double angle);
void				bitmapp(void);
t_rgb				colorconverter(int hexvalue);
int					r_collect(char *str);
int					nswe_collect(char *str, int nb);
int					fc_collect(char *str, int i);
int					map_error_norminette(int i, int j);
void				cub3d(void);
void				cheack_map(char *map_name);
void				draw_sprite(int i);
void				raycasting(void);
void				draw_sky(int color);
void				draw_floor(int color);
void				drawing_wall(int offset, double angle, double hor_dis,
					double radius);
void				findwall(void);
void				init_globale_variable(void);
void				calcul_sprite(void);
void				drawcub(int x, int y, int color, int width);
void				ft_exit(void);
void				bitmapp(void);
int					ft_cheack_element(void);
int					ft_printf(const char *str, ...);
int					wish_texture(double angle, double hor_dis, double radius);

#endif

