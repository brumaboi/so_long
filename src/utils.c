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

static void check_rows(t_solong *ptr)
{
    size_t i;

    i = 0;
    while (i < ptr->map.rows)
    {
        if (ptr->map.map[i][0] != WALL || ptr->map.map[i][ptr->map.columns - 1] != WALL)
            error("map is not surrounded by walls\n");
        i++;
    }
}

static void check_columns(t_solong *ptr)
{
    size_t i;

    i=0;
    while(i < ptr->map.columns)
    {
        if (ptr->map.map[0][i] != WALL || ptr->map.map[ptr->map.rows - 1][i] != WALL)
            error("map is not surrounded by walls\n");
        i++;
    }
}

void check_walls(t_solong *ptr)
{
    check_rows(ptr);
    check_columns(ptr);
}