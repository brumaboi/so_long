/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:36:14 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 22:36:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_format(char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (extension)
	{
		if (!ft_strncmp(extension, ".ber", 4))
			return (1);
	}
	return (0);
}

void check_empty_lines(t_map *map)
{
    size_t i;
    size_t rows;

    i = 0;
    rows = map->rows;
    if (map->map[0][0] == '\n')
        error("empty line\n");
    if (map->map[rows - 1][0] == '\n')
        error("empty line\n");
    while (i < rows - 1)
    {
        if (map->map[i][0] == '\n' && map->map[i + 1][0] == '\n')
            error("empty line\n");
        i++;
    }
}

char *ft_join(char *tmp, char *line)
{
    char *new_tmp;

    new_tmp = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(line) + 1));
    if (!new_tmp)
        error("Memory allocation failed\n");
    ft_strcpy(new_tmp, tmp);
    ft_strcat(new_tmp, line);
    free(tmp);
    return (new_tmp);
}
void read_map(int fd, char ***map, t_solong *ptr)
{
    char *tmp;
    char *line;

    tmp = ft_strdup("");
    if (!tmp)
        error("Memory allocation for tmp failed\n");
    ptr->map.rows = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        tmp = ft_join(tmp, line);
        free(line);
        line = get_next_line(fd);
        ptr->map.rows++;
    }
    *map = ft_split(tmp, '\n');
    if (*map == NULL)
        error("Map splitting failed\n");
    free(tmp);
}

void   init_map(t_solong *ptr, char *path)
{
    int fd;

    if (!check_format(path))
        error("Invalid file format\n");
    fd = open(path, O_RDONLY);
    if (fd < 0)
        error("Failed to open file\n");
    read_map(fd, &ptr->map.map, ptr);
    close(fd);
    check_empty_lines(&ptr->map);
}
