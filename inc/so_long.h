/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:23:10 by sbruma            #+#    #+#             */
/*   Updated: 2024/09/14 00:14:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define FLOOR   '0'
# define WALL    '1'
# define PLAYER  'P'
# define EXIT    'E'
# define COLLECT 'C'

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TILE_SIZE 32

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct s_image
{
    mlx_image_t *img_ptr;
    int  x;
    int  y;
}   t_image;

typedef struct s_map
{
    char    **map;
    int     rows;
    int     columns;
    int     exit;
    int     collectible;
    int     player;
    t_pos   player_pos;
    int     exit_reachable;
    int     collectible_reachable;
    int     initial_render;
    int     exit_x;
    int     exit_y;
}   t_map;

typedef struct s_solong
{
    mlx_t    *mlx;
    void    *win;
    int     steps;
    t_map   map;
    t_image wall;
    t_image player;
    t_image exit;
    t_image collectible;
    t_image floor;
    t_image open_exit;
}   t_solong;


/////
void check_access(t_solong *ptr);
void check_elements(t_solong *ptr);
void check_walls(t_solong *ptr);
void check_map(t_solong *ptr);
void count_elements(t_solong *ptr);
void init_variables(t_solong *ptr);
/////
void   init_map(t_solong *ptr, char *path);
/////
void init_img(t_solong *ptr);
void init_mlx(t_solong *ptr);
/////
void map_render(t_solong *ptr);
/////
void	key_hook(mlx_key_data_t keydata, void *param);
void	error(char *message);
void free_map(char **split);
void render_loop(void *param);

#endif