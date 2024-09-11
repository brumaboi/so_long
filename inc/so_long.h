/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:23:10 by sbruma            #+#    #+#             */
/*   Updated: 2024/09/11 19:15:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define FLOOR   '0'
# define WALL    '1'
# define PLAYER  'P'
# define EXIT    'E'
# define COLLECT 'C'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ESC			65307

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
    t_image front;
    t_image back;
    t_image left;
    t_image right;
    t_image open_exit;
}   t_solong;


/////
void check_access(t_solong *ptr);
void check_elements(t_solong *ptr);
void check_walls(t_solong *ptr);
void check_map(t_solong *ptr);
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

#endif