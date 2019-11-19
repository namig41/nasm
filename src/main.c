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
#include <stdio.h>

int		main(int argc, char **argv)
{
	int 		fd;
	void 		*mlx_ptr;
	void 		*win_ptr;
	t_coord 	**coord;
	t_map_size 	*map_size;
	t_polygon	point_arr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Fdf_Window");
	t_point p11 = {50, 50};
	t_point p12 = {100, 100};

	point_arr = init_rectangle(p11, p12);




	for (int i = 0; i < 10; i++)
	{
		point_arr = init_rectangle(p11, p12);
		for (int j = 0; j < 10; j++)
		{
				draw_polygon2d(mlx_ptr, win_ptr, point_arr.p, point_arr.size);
				iso(point_arr.p, 10, 4);
				draw_polygon2d(mlx_ptr, win_ptr, point_arr.p, 4);
		}
	}

	// t_point p21 = {100, 100};
	// t_point p22 = {50, 100};

	// t_point p31 = {25, 25};
	// t_point p32 = {75, 25};
	// t_point p41 = {75, 75};
	// t_point p42 = {25, 75};

	//draw_polygon2d(mlx_ptr, win_ptr, p11, p12, p21, p22);
	//draw_polygon2d(mlx_ptr, win_ptr, p31, p32, p41, p42);
	
	// draw_cube(mlx_ptr, win_ptr, p11, p12, p21, p22);
	
	// p11.x += 200;
	// p12.x += 200;
	// p21.x += 200;
	// p22.x += 200;




	//draw_polygon(mlx_ptr, win_ptr, p11, p12, p21, p22);

	// t_point a[8];

	// a[0] = p11;
	// a[1] = p12;
	// a[2] = p21;
	// a[3] = p22;

	// a[4] = p31;
	// a[5] = p32;
	// a[6] = p41;
	// a[7] = p42;

	// draw_polygon3d(mlx_ptr, win_ptr, a, 8);

	// int i;

	// i = -1;
	// while (++i < 8)
	// {
	// 	a[i].x += 400;
	// 	iso(&a[i].x, &a[i].y, 5);
	// }
	// draw_polygon3d(mlx_ptr, win_ptr, a, 8);



	// draw_cube(mlx_ptr, win_ptr, p11, p12, p21, p22);

	// for (size_t i = 0; i < 20; i++)
	// {
	// 	iso(&p11.x, &p11.y, i);
	// 	iso(&p12.x, &p12.y, i);
	// 	printf("%d %d %d %d\n", p11.x, p11.y, p12.x, p12.y);
	// 	draw_rectangle(mlx_ptr, win_ptr, p11, p12);
	// }
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		draw_cube(mlx_ptr, win_ptr, p11, p12, p21, p22);
	// 		p11.x += 50;
	// 		p12.x += 50;
	// 		p21.x += 50;
	// 		p22.x += 50;
	// 	}
	// 		p11.y += 50;
	// 		p12.y += 50;
	// 		p21.y += 50;
	// 		p22.y += 50;

	// 		p11.x = 50;
	// 		p12.x = 100;
	// 		p21.x = 30;
	// 		p22.x = 80;
	// }
	mlx_loop(mlx_ptr);
}

