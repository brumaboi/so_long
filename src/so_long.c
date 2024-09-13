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

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
    t_solong ptr;

    if (argc != 2)
        error("Usage: ./so_long [map.ber]\n");
    else
    {   
        init_map(&ptr, argv[1]);
        init_variables(&ptr);
        check_map(&ptr);
        init_mlx(&ptr);
        init_img(&ptr);
        map_render(&ptr);        
        mlx_key_hook(ptr.mlx, key_hook, &ptr);
        mlx_loop(ptr.mlx);
        free_map(ptr.map.map);
        return(0);
    }
}
