/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:57:49 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 23:57:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void img_render(t_solong *ptr, t_image img, int i, int j)
{
    mlx_image_to_window(ptr->mlx, img.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
}

void what_img(t_solong *ptr, int i, int j)
{
    char elem;

    elem = ptr->map.map[i][j];
    if(elem == FLOOR)
        img_render(ptr, ptr->floor, i, j);
    else if(elem == WALL)
        img_render(ptr, ptr->wall, i, j);
    else if(elem == COLLECT)
        img_render(ptr, ptr->collectible, i, j);
    else if(elem == EXIT)
    {
        if(ptr->map.collectible == 0)
            img_render(ptr, ptr->open_exit, i, j);
        else
            img_render(ptr, ptr->exit, i, j);
    }
    else if(elem == PLAYER)
        img_render(ptr, ptr->player, i, j);
}

void map_render(t_solong *ptr)
{
    int i;
    int j;

    i=0;
    while (i < ptr->map.rows)
    {
        j=0;
        while(j < ptr->map.columns)
        {
            what_img(ptr, i, j);
            j++;
        }
        i++;
    }
}
