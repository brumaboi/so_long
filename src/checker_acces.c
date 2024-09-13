/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_acces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:11:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/11 10:11:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void init_checked(int **checked, int columns, int rows, int i)
{
    if(i == rows)
        return ;
    checked[i] = malloc(sizeof(int) * columns);
    if (checked[i] == NULL)
        error("Memory allocation failed\n");
    memset(checked[i], 0, sizeof(int) * columns);
    init_checked(checked, columns, rows, i + 1);
}

static void free_checked(int **checked, int rows, int i)
{
    if(i == rows)
        return ;
    free(checked[i]);
    free_checked(checked, rows, i + 1);
}

static void ft_search(t_solong *ptr, int i, int j, int **checked)
{
    if(i < 0 || j < 0 || i >= ptr->map.columns || j >= ptr->map.rows || checked[j][i] == 1)
        return ;
    if (ptr->map.map[j][i] == WALL || (ptr->map.map[j][i] == EXIT && ptr->map.initial_render))
        return ;
    checked[j][i] = 1;
    if(ptr->map.map[j][i] == COLLECT)
        ptr->map.collectible_reachable++;
    if(ptr->map.map[j][i] == EXIT && !ptr->map.exit_reachable && !ptr->map.initial_render)
        ptr->map.exit_reachable = 1;
    ft_search(ptr, i + 1, j, checked);
    ft_search(ptr, i - 1, j, checked);
    ft_search(ptr, i, j + 1, checked);
    ft_search(ptr, i, j - 1, checked);
}

void check_access(t_solong *ptr)
{
    int **checked;

    checked = malloc(sizeof(int *) * ptr->map.rows);
    init_checked(checked, ptr->map.columns, ptr->map.rows, 0);
    ptr->map.exit_reachable = 0;
    ptr->map.collectible_reachable = 0;
    ptr->map.initial_render = 1;
    ft_search(ptr, ptr->map.player_pos.x, ptr->map.player_pos.y, checked);
    if (ptr->map.collectible_reachable != ptr->map.collectible)
        error("collectible unreachable\n");
    free_checked(checked, ptr->map.rows, 0);
    init_checked(checked, ptr->map.columns, ptr->map.rows, 0);
    ptr->map.initial_render = 0;
    ft_search(ptr, ptr->map.player_pos.x, ptr->map.player_pos.y, checked);
    if(!ptr->map.exit_reachable)
        error("exit unreachable\n");
    free_checked(checked, ptr->map.rows, 0);
    free(checked);
}
