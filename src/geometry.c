/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:20:13 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/18 17:33:04 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <stdio.h>
# define eps 1e-1f

void draw_line(void *mlx_ptr, void *win_prt, t_point p1, t_point p2) {
    const int deltaX = abs(p2.x - p1.x);
    const int deltaY = abs(p2.y - p1.y);
    const int signX = p1.x < p2.x ? 1 : -1;
    const int signY = p1.y < p2.y ? 1 : -1;
    int error = deltaX - deltaY;
    mlx_pixel_put(mlx_ptr, win_prt, p2.x, p2.y, 0x228B22);
    while(p1.x != p2.x || p1.y != p2.y) 
   {
		mlx_pixel_put(mlx_ptr, win_prt, p1.x, p1.y, 0x228B22);
        const int error2 = error * 2;
        if (error2 > -deltaY) 
        {
            error -= deltaY;
            p1.x += signX;
        }
        if (error2 < deltaX) 
        {
            error += deltaX;
            p1.y += signY;
        }
    }

}

void	draw_rectangle(void *mlx_ptr, void *win_prt, t_point p1, t_point p2)
{
	t_point tp1;
	t_point tp2;

	tp1.x = p2.x;
	tp1.y = p1.y;
	tp2.x = p1.x;
	tp2.y = p2.y;
	draw_line(mlx_ptr, win_prt, p1, tp1);
	draw_line(mlx_ptr, win_prt, p1, tp2);
	draw_line(mlx_ptr, win_prt, tp1, p2);
	draw_line(mlx_ptr, win_prt, tp2, p2);
}

void	draw_circle(void *mlx_ptr, void *win_prt, t_point center, int r)
{
	
}

void	draw_cube(void *mlx_ptr, void *win_prt, t_point p11, t_point p12, t_point p21, t_point p22)
{
	t_point tp11;
	t_point tp12;
	t_point tp21;
	t_point tp22;

	tp11.x = p11.x;
	tp11.y = p12.y;
	
	tp12.x = p12.x;
	tp12.y = p11.y;

	tp21.x = p21.x;
	tp21.y = p22.y;

	tp22.x = p22.x;
	tp22.y = p21.y;
	draw_rectangle(mlx_ptr, win_prt, p11, p12);
	draw_rectangle(mlx_ptr, win_prt, p21, p22);
	draw_line(mlx_ptr, win_prt, p11, p21);
	draw_line(mlx_ptr, win_prt, p12, p22);
	draw_line(mlx_ptr, win_prt, tp12, tp22);
	draw_line(mlx_ptr, win_prt, tp11, tp21);
}