/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:28:24 by fpythago          #+#    #+#             */
/*   Updated: 2019/11/18 17:05:17 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct		s_coord
{
	int 			z;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_map_size
{
	int 			width;
	int				height;
	struct s_map_size	*next;
}					t_map_size;

int		read_map(int fd);

#endif
