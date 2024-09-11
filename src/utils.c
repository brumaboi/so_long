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

void	key_hook(mlx_key_data_t keydata, t_solong *ptr)
{
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
    return(0);
}