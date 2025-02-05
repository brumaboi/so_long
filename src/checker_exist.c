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

static void	check_rows(t_solong *ptr)
{
	int		i;
	size_t	row_len;

	i = 0;
	while (i < ptr->map.rows)
	{
		row_len = ft_strlen(ptr->map.map[i]);
		if (ptr->map.map[i][0] != WALL || ptr->map.map[i][row_len - 1] != WALL)
			error("map is not surrounded by walls\n");
		i++;
	}
}

static void	check_columns(t_solong *ptr)
{
	int		i;
	char	top;
	char	bottom;

	i = 0;
	while (i < ptr->map.columns)
	{
		top = ptr->map.map[0][i];
		bottom = ptr->map.map[ptr->map.rows - 1][i];
		if (top != WALL || bottom != WALL)
			error("map is not surrounded by walls\n");
		i++;
	}
}

void	check_walls(t_solong *ptr)
{
	check_rows(ptr);
	check_columns(ptr);
}

void	count_elements(t_solong *ptr)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ptr->map.rows)
	{
		j = -1;
		while (++j < ptr->map.columns)
		{
			if (ptr->map.map[i][j] == PLAYER)
			{
				ptr->map.player++;
				ptr->map.player_pos.x = j;
				ptr->map.player_pos.y = i;
			}
			if (ptr->map.map[i][j] == COLLECT)
				ptr->map.collectible++;
			if (ptr->map.map[i][j] == EXIT)
			{
				ptr->map.exit++;
				ptr->map.exit_x = j;
				ptr->map.exit_y = i;
			}
		}
	}
}

void	check_elements(t_solong *ptr)
{
	int		i;
	int		j;
	char	element;

	i = 0;
	while (i < ptr->map.rows)
	{
		j = 0;
		while (j < ptr->map.columns)
		{
			element = ptr->map.map[i][j];
			if (element != FLOOR && element != WALL && element != PLAYER
				&& element != EXIT && element != COLLECT)
				error("Invalid element\n");
			j++;
		}
		i++;
	}
	count_elements(ptr);
	if (ptr->map.collectible < 1 || ptr->map.exit != 1 || ptr->map.player != 1)
		error("missing elements\n");
}
