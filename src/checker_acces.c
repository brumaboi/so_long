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
    if(i < 0 || j < 0 || i >= ptr->map.columns || j >= ptr->map.rows && (checked[j][i] == 1 || ptr->map.map[j][i] == WALL))
        return ;
    checked[j][i] = 1;
    if(ptr->map.map[j][i] == COLLECT)
        ptr->map.collectible--;
    if(ptr->map.map[j][i] == EXIT)
        ptr->exit_reachable = 1;
    ft_search(ptr, i + 1, j, checked);
    ft_search(ptr, i - 1, j, checked);
    ft_search(ptr, i, j + 1, checked);
    ft_search(ptr, i, j - 1, checked);
}

void check_access(t_solong *ptr)
{
    int **checked;

    checked = malloc(sizeof(int *) * ptr->map.rows);
    init_checked(checked, ptr->map.columns, ptr->map.rows);
    ft_search(ptr, ptr->map.player_pos.x, ptr->map.player_pos.y, checked);
    if(ptr->map.collectible != 0)
        error("collectible unreachable\n");
    if(!ptr->exit_reachable)
        error("exit unreachable\n");
    free_checked(checked, ptr->map.rows);
    free(checked);
}