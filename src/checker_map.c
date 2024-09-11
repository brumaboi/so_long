/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:36:19 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 22:36:19 by marvin           ###   ########.fr       */
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

void check_access(t_solong *ptr, int x, int y)
{
    int **checked;

    checked = malloc(sizeof(int *) * ptr->map.rows);
    ft_search();
    if(ptr->map.collectible != 0)
        error("collectible unreachable\n");
    if(ptr->map.exit != 0)
        error("exit unreachable\n");
    free(checked);
}
void check_map(t_solong *ptr)
{
    check_walls(ptr);
    check_elements(ptr);
    check_access(ptr);
}