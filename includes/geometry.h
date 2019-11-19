/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:07:26 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/18 17:33:27 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GEOMETRY_H
# define GEOMETRY_H
# define EPS 0.1f
# include <stdlib.h>
# include <math.h>

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_polygon
{
	t_point		*p;
	int			size;
}				t_polygon;

t_polygon	init_rectangle(t_point p1, t_point p2);
void		draw_line(void *mlx_ptr, void *win_prt, t_point p1, t_point p2);
void		draw_rectangle(void *mlx_ptr, void *win_prt, t_point p1, t_point p2);
void		draw_circle(void *mlx_ptr, void *win_prt, t_point center, int r);
void		draw_cube(void *mlx_ptr, void *win_prt, t_point p11, t_point p12, t_point p21, t_point p22);
void		draw_polygon2d(void *mlx_ptr, void *win_prt, t_point* arr, int len);
void		draw_polygon3d(void *mlx_ptr, void *win_prt, t_point *p, int len);
void		iso(t_point *p, int z, int len);


# endif
