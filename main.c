/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:30:40 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 22:30:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/inc/so_long.h"

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct s_image
{
    void *xmp_ptr;
    int  x;
    int  y;
}   t_image;

typedef struct s_map
{
    char    **map;
    int     rows;
    int     columns;
    int     exit;
    int     collectible;
    int     player;
    t_pos   player_pos;
}   t_map;

typedef struct s_solong
{
    void    *mlx;
    void    *win;
    int     steps;
    t_map   map;
    t_image wall;
    t_image player;
    t_image exit;
    t_image collectible;
    t_image floor;
}   t_solong;

void	error(char *message)
{
	ft_putstr(message);
	exit(1);
}

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

void check_for_empty_line(const char *map)
{
    size_t i;
    size_t len;

    i = 0;
    len = strlen(map);
    if (map[0] == '\n')
        error("empty line\n");
    if (map[len - 1] == '\n')
        error("empty line\n");
    while (i < len - 1)
    {
        if (map[i] == '\n' && map[i + 1] == '\n')
            error("empty line\n");
        i++;
    }
}

void read_map(int fd, char **map, t_solong *ptr)
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
        free(line);
        tmp = new_tmp;
        free(line);
        ptr->map.rows++;
    }
    *map = tmp;
}

void   init_map(t_solong *ptr, char *path)
{
    int fd;

    if (!check_format(argv[1]))
        error("Invalid file format\n");
    fd = open(path, O_RDONLY);
    if (fd < 0)
        error("Failed to open file\n");
    read_map(fd, &ptr->map, &ptr->map.rows);
    close(fd);
    check_empty_lines(&solong->map);
}
int main(int argc, char **argv)
{
    t_solong ptr;

    if (argc != 2)
        error("Usage: ./so_long [map.ber]\n");
    else
    {   
        ptr = malloc(sizeof(t_map));
        init_map(&ptr, argv[1]);
        init_mlx(&ptr);
        window_setup(argv, &ptr);
    }
}