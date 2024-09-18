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

void	init_mlx(t_solong *ptr)
{
	int	window_width;
	int	window_height;

	window_width = ptr->map.columns * TILE_SIZE;
	window_height = ptr->map.rows * TILE_SIZE;
	if (window_width > SCREEN_WIDTH || window_height > SCREEN_HEIGHT)
		error("Map is too big for the screen\n");
	ptr->mlx = mlx_init(window_width, window_height, "so_long", false);
	if (!ptr->mlx)
		error("mlx_init failed\n");
	ptr->win = mlx_new_image(ptr->mlx, window_width, window_height);
	if (!ptr->win)
		error("mlx_new_window failed\n");
}

t_image	ft_new_img(void *mlx, char *path)
{
	t_image			img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error("Failed to load texture: %s\n");
	img.img_ptr = mlx_texture_to_image(mlx, texture);
	if (!img.img_ptr)
		error("Failed to convert texture to image\n");
	mlx_resize_image(img.img_ptr, TILE_SIZE, TILE_SIZE);
	mlx_delete_texture(texture);
	return (img);
}

void	init_img(t_solong *ptr)
{
	void	*mlx;

	mlx = ptr->mlx;
	ptr->wall = ft_new_img(mlx, "textures/wall.png");
	ptr->floor = ft_new_img(mlx, "textures/floor.png");
	ptr->player = ft_new_img(mlx, "textures/player.png");
	ptr->collectible = ft_new_img(mlx, "textures/collectible.png");
	ptr->exit = ft_new_img(mlx, "textures/exit.png");
	ptr->open_exit = ft_new_img(mlx, "textures/open_exit.png");
}
