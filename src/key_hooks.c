/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:36:21 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 22:36:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error(char *message)
{
	ft_putstr(message);
	exit(1);
}

void free_map(char **split)
{
    int i;
    
    i = 0;
    while (split[i] != NULL)
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void ft_victory(t_solong *ptr)
{
    ptr->steps++;
    ft_printf("Steps: %d\n", ptr->steps);
    ft_printf("Victory!\n");
    mlx_close_window(ptr->mlx);
    return ;
}

void map_render_tile(t_solong *ptr, int x, int y, char tile)
{
    if (tile == FLOOR)
        mlx_image_to_window(ptr->mlx, ptr->floor.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
    else if (tile == WALL)
        mlx_image_to_window(ptr->mlx, ptr->wall.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
    else if (tile == COLLECT)
        mlx_image_to_window(ptr->mlx, ptr->collectible.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
    else if (tile == EXIT)
    {
        if (ptr->map.collectible == 0)
            mlx_image_to_window(ptr->mlx, ptr->open_exit.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
        else
            mlx_image_to_window(ptr->mlx, ptr->exit.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
    }
    else if (tile == PLAYER)
        mlx_image_to_window(ptr->mlx, ptr->player.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void player_movement(t_solong *ptr, int current_x, int current_y)
{
    if (current_x < 0 || current_x >= ptr->map.columns || current_y < 0 || current_y >= ptr->map.rows)
        return ;
    if (ptr->map.map[current_y][current_x] == WALL)
        return ;
    if (ptr->map.map[current_y][current_x] == EXIT && ptr->map.collectible > 0)
        return ;
    if (ptr->map.map[current_y][current_x] == COLLECT)
    {
        ptr->map.collectible--;
        ptr->map.map[current_y][current_x] = FLOOR;
        if (ptr->map.collectible == 0)
            map_render_tile(ptr, ptr->map.exit_x, ptr->map.exit_y, EXIT);
    }
    if (ptr->map.map[current_y][current_x] == EXIT && ptr->map.collectible == 0)
    {
        ft_victory(ptr);
        return ;
    }
    map_render_tile(ptr, ptr->map.player_pos.x, ptr->map.player_pos.y, FLOOR);
    ptr->map.player_pos.x = current_x;
    ptr->map.player_pos.y = current_y;
    ptr->map.map[current_y][current_x] = PLAYER;
    map_render_tile(ptr, current_x, current_y, PLAYER);
    ptr->steps++;
    ft_printf("Steps: %d\n", ptr->steps);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
    t_solong *ptr;

    ptr = (t_solong *)param;
    if (keydata.action != MLX_PRESS)
    {
        return ;
    }
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ptr->mlx);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
        player_movement(ptr, ptr->map.player_pos.x, ptr->map.player_pos.y - 1);
    else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
        player_movement(ptr, ptr->map.player_pos.x, ptr->map.player_pos.y + 1);
    else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
        player_movement(ptr, ptr->map.player_pos.x - 1, ptr->map.player_pos.y);
    else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
        player_movement(ptr, ptr->map.player_pos.x + 1, ptr->map.player_pos.y);
    return ;
}
