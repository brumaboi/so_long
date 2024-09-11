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
    ptr->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", 0);
    if (!ptr->mlx)
        error("mlx_init failed\n");
    ptr->win = mlx_new_image(ptr->mlx, ptr->map.columns * 32, ptr->map.rows * 32);
    if (!ptr->win)
        error("mlx_new_window failed\n");
}

t_image    ft_new_img(void *mlx, char *path)
{
    t_image img;

    img.xmp_ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
    if (!img.xmp_ptr)
        error("mlx_xpm_file_to_image failed\n");
    return (img);
}

void init_img(t_solong *ptr)
{
    void *mlx;

    mlx = ptr->mlx;
    ptr->wall = ft_new_img(mlx, "path");
    ptr->floor = ft_new_img(mlx, "path");
    ptr->player = ft_new_img(mlx, "path");
    ptr->collectible = ft_new_img(mlx, "path");
    ptr->exit = ft_new_img(mlx, "path");
    ptr->open_exit = ft_new_img(mlx, "path");
}