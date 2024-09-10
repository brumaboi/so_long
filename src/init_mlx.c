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

void init_variables(t_solong *ptr)
{
    ptr->steps = 0;
    ptr->map.collectible = 0;
    ptr->map.exit = 0;
    ptr->map.player = 0;
    ptr->map.columns = ft_strlen(ptr->map.map[0]) - 1;
}

void init_mlx(t_solong *ptr)
{
    ptr->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", 0);
    if (!ptr->mlx)
        error("mlx_init failed\n");
}
