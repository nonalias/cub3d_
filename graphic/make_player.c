#include "../cub3d.h"

void	make_cursor(t_game *game)
{
	game->wall.angle = game->player.rot_angle;
	get_wall_x_y(game);
	game->line.origin_x = game->player.cur_x / MINIMAP_RATIO;
	game->line.origin_y = game->player.cur_y / MINIMAP_RATIO;
	game->line.target_x = game->wall.x / MINIMAP_RATIO;
	game->line.target_y = game->wall.y / MINIMAP_RATIO;
	make_line(game);
}

void	make_player(t_game *game)
{
	int			x;

	/*
	x = -5;
	game->line.origin_y = game->player.cur_y - 5;
	game->line.target_y = game->player.cur_y + 5;
	game->line.color = 0x000000;
	while (x < 5)
	{
		game->line.origin_x = game->player.cur_x + x;
		game->line.target_x = game->player.cur_x + x;
		make_line(game);
		x++;
	}
	*/
	// TODO : 플레이어 위치 표시 박스 구현이 안됨....( 세로줄 한 줄만 나옴)
	/*
	game->line.color = 0xff0000;
	game->line.origin_x = game->player.cur_x / MINIMAP_RATIO;
	game->line.origin_y = game->player.cur_y / MINIMAP_RATIO;
	game->line.target_x = game->player.cur_x / MINIMAP_RATIO + (20 / MINIMAP_RATIO * cos(TO_RADIAN(game->player.rot_angle)));
	game->line.target_y = game->player.cur_y / MINIMAP_RATIO + (20 / MINIMAP_RATIO * sin(TO_RADIAN(game->player.rot_angle)));
	make_line(game);
	*/
//	make_cursor(game);
	game->img.data[to_coord(game, game->player.cur_x / MINIMAP_RATIO, game->player.cur_y / MINIMAP_RATIO)] = 0xff0000;
}