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
}
