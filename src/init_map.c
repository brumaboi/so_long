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

void check_empty_lines(const char **map)
{
    size_t i;
    size_t len;

    i = 0;
    len = strlen(map[0]);
    if (map[0][0] == '\n')
        error("empty line\n");
    if (map[len - 1][0] == '\n')
        error("empty line\n");
    while (i < len - 1)
    {
        if (map[i][0] == '\n' && map[i + 1] && map[i + 1][0] == '\n')
            error("empty line\n");
        i++;
    }
}

void read_map(int fd, char ***map, t_solong *ptr)
{
    char *tmp;
    char *line;
    char *new_tmp;

    
    tmp = ft_strdup("");
    ptr->map.rows = 0;
    line = get_next_line(fd);
    while(line != NULL)
    {
        new_tmp = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(line) + 2));
        strcpy(new_tmp, tmp);
        strcat(new_tmp, line);
        strcat(new_tmp, "\n");
        free(tmp);
        tmp = new_tmp;
        free(line);
        line = get_next_line(fd);
        ptr->map.rows++;
    }
    *map = ft_split(tmp, '\n');
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
    check_empty_lines((const char **)ptr->map.map);
}