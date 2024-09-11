/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:36:24 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 22:36:24 by marvin           ###   ########.fr       */
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

static void count_elements(t_solong *ptr)
{
    size_t i;
    size_t j;

    i = 0;
    while(i < ptr->map.rows)
    {
        j = 0;
        while(j < ptr->map.columns)
        {
            if (ptr->map.map[i][j] == PLAYER)
                ptr->map.player++;
            if (ptr->map.map[i][j] == COLLECT)
                ptr->map.collectible++;
            if (ptr->map.map[i][j] == EXIT)
                ptr->map.exit++;
            j++;
        }
        i++;
    }
}

void check_elements(t_solong *ptr)
{
    count_params(ptr);
    if(ptr->map.collectible != 1 || ptr->map.exit != 1 || ptr->map.player != 1)
        error("missing elements\n");
}