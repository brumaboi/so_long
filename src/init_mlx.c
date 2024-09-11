/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:36:17 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 22:36:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void init_mlx(t_solong *ptr)
{
    ptr->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", true);
    if (!ptr->mlx)
        error("mlx_init failed\n");
    ptr->win = mlx_new_image(ptr->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!ptr->win)
        error("mlx_new_window failed\n");
}

t_image ft_new_img(void *mlx, char *path)
{
    t_image img;
    mlx_texture_t *texture;

    texture = mlx_load_png(path);
    if (!texture)
        error("Failed to load texture: %s\n");
    img.img_ptr = mlx_texture_to_image(mlx, texture);
    if (!img.img_ptr)
        error("Failed to convert texture to image\n");
    mlx_delete_texture(texture);
    return (img);
}

void init_img(t_solong *ptr)
{
    void *mlx;

    mlx = ptr->mlx;
    ptr->wall = ft_new_img(mlx, "../resources/textusre/wall.png");
    ptr->floor = ft_new_img(mlx, "../resources/textusre/floor.png");
    ptr->player = ft_new_img(mlx, "../resources/textusre/player.png");
    ptr->collectible = ft_new_img(mlx, "../resources/textusre/collectible.png");
    ptr->exit = ft_new_img(mlx, "../resources/textusre/exit.png");
    ptr->open_exit = ft_new_img(mlx, "../resources/textusre/open_exit.png");
}