/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:23:10 by sbruma            #+#    #+#             */
/*   Updated: 2024/09/11 00:44:40 by marvin           ###   ########.fr       */
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


typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct s_image
{
    void *xmp_ptr;
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
}   t_map;

typedef struct s_solong
{
    void    *mlx;
    void    *win;
    int     steps;
    t_map   map;
    t_image wall;
    t_image player;
    t_image exit;
    t_image collectible;
    t_image floor;
}   t_solong;


void	error(char *message);
void	init_map(t_solong *ptr, char *path);
void	init_variables(t_solong *ptr);
void	map_checker(t_solong *ptr);
void	init_mlx(t_solong *ptr);
void    check_for_empty_line(const char *map);
void    read_map(int fd, char ***map, t_solong *ptr);


#endif