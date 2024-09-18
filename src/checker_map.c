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

void	init_variables(t_solong *ptr)
{
	int		i;
	size_t	max_len;
	size_t	len;

	i = 0;
	max_len = 0;
	ptr->steps = 0;
	ptr->map.collectible = 0;
	ptr->map.exit = 0;
	ptr->map.player = 0;
	while (i < ptr->map.rows)
	{
		len = ft_strlen(ptr->map.map[i]);
		if (ptr->map.map[i][len - 1] == '\n'
			|| ptr->map.map[i][len - 1] == '\r')
		{
			ptr->map.map[i][len - 1] = '\0';
			len--;
		}
		if (len > max_len)
			max_len = len;
		i++;
	}
	ptr->map.columns = max_len;
}

void	check_map(t_solong *ptr)
{
	check_walls(ptr);
	check_elements(ptr);
	check_access(ptr);
}
