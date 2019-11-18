/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:29:55 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/18 17:19:02 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "geometry.h"

int		main(int argc, char **argv)
{
	int 		fd;
	void 		*mlx_ptr;
	void 		*win_ptr;
	t_coord 	**coord;
	t_map_size 	*map_size;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Fdf_Window");
	t_point p11 = {50, 50};
	t_point p12 = {100, 100};
	t_point p21 = {30, 30};
	t_point p22 = {80, 80};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			draw_cube(mlx_ptr, win_ptr, p11, p12, p21, p22);
			p11.x += 50;
			p12.x += 50;
			p21.x += 50;
			p22.x += 50;
		}
			p11.y += 50;
			p12.y += 50;
			p21.y += 50;
			p22.y += 50;

			p11.x = 50;
			p12.x = 100;
			p21.x = 30;
			p22.x = 80;
	}
	mlx_loop(mlx_ptr);
}
