#ifndef __CUB3D_H

# define __CUB3D_H
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>
# include "const.h"
# include <float.h>
# include <fcntl.h>
# include <unistd.h>
# define TO_RADIAN(x) (((M_PI) / (180)) * (x))
# define TWO_POINT_DISTANCE(x1, y1, x2, y2) (sqrt(((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2))))
# define X_SIDE 1
# define Y_SIDE 0

typedef struct	s_img {
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_player
{
	double		cur_x;
	double		cur_y;
	double		rot_angle;
	double		rot_speed;
	int			move_speed;
}				t_player;

typedef	struct	s_line
{
	int			color;
	double		origin_x;
	double		origin_y;
	double		target_x;
	double		target_y;
}				t_line;

typedef struct	s_window
{
	int			width;
	int			height;
}				t_window;

typedef	struct	s_flag
{
	int			debug;
	int			save;
}				t_flag;

typedef struct	s_debug
{
	char		*map_str;
	char		*x_str;
	char		*y_str;
	char		*rot_angle_str;
}				t_debug; //TODO : 끝날 때 free 해 주어야 함.

typedef	struct	s_wall
{
	double		x;
	double		y;
	double		angle;
	double		distance;
	int			is_x_or_y;
	int			cardinal;
}				t_wall;

typedef struct	s_ray
{
	double		vertx;
	double		verty;
	double		horzx;
	double		horzy;
	double		xintercept;
	double		yintercept;
	double		xstep;
	double		ystep;
	double		nexthorztouchx;
	double		nexthorztouchy;
	double		nextverttouchx;
	double		nextverttouchy;
	int			foundhorzwallhit;
	int			foundvertwallhit;
	int			up_facing;
	int			down_facing;
	int			left_facing;
	int			right_facing;
}				t_ray;

typedef struct	s_map
{
	int			xlength;
	int			ylength;
	int			fd;
	char		*name;
}				t_map;

typedef struct	s_tex
{
	int			texture[4][TEX_WIDTH * TEX_HEIGHT];
	int			**cart;
}				t_tex;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	win;
	t_img		img;
	t_player	player;
	t_line		line;
	t_flag		flags;
	t_debug		debug;
	t_wall		wall;
	t_ray		ray;
	t_map		map;
	t_tex		tex;
	int			seek_angle;
	int			seek_distance;
	double		tile_xsize;
	double		tile_ysize;
	int			key_check[300];
}				t_game;

int		my_map[11][15];

/*
int		my_map[11][11] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
*/

void			make_2d(t_game *game);
void			make_rader(t_game *game);
void			make_rader_line(t_game *game);
void			make_3d(t_game *game);
void			make_player(t_game *game);
void			make_line(t_game *game); // TODO: line 매개변수로 넣을지 game 단에서 처리할지 결정
void			make_view(t_game *game);
void			make_tile(t_game *game, int i, int j, int color);

int				key_press_callback(int keycode, t_game *game);
int				key_release_callback(int keycode, t_game *game);

int				get_wall_distance(t_game *game);
double			get_wall_x_y(t_game *game);
int				mini_check_wall(t_game *game, double x, double y);
int				check_wall(t_game *game, double x, double y);

int				hook_action(t_game *game);
void			key_matching(t_game *game);

void			init(t_game *game);
void			win_init(t_game *game);
void			game_init(t_game *game);
void			player_init(t_game *game);
void			ray_init(t_game *game);
void			wall_init(t_game *game);
void			flag_init(t_game *game);
void			cart_init(t_game *game);

void			move_w_a(t_game *game);
void			move_w_d(t_game *game);
void			move_w(t_game *game);
void			move_s_a(t_game *game);
void			move_s_d(t_game *game);
void			move_s(t_game *game);
void			move_a(t_game *game);
void			move_d(t_game *game);
int				to_coord(t_game *game, double x, double y);

void			debug_process(t_game *game);
void			arg_parse(t_game *game, int argc, char **argv);
void			free_process(t_game *game);

double			raycasting_vert(t_game *game);
double			raycasting_horz(t_game *game);
#endif