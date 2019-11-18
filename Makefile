# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 15:46:39 by lcarmelo          #+#    #+#              #
#    Updated: 2019/11/18 17:00:02 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRC_DIR = ./src/
INC_DIR = ./includes/
LIB_DIR = ./libft/
MLIB_DIR = ./minilibx_macos/

SRC_NAME = main \
		   get_next_line \
		   parse_file \
		   geometry \

LIB_NAME = libft

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAME)))
OBJS = $(addsuffix .o, $(SRC_NAME))
LIBS = $(addprefix $(LIB_DIR), $(addsuffix .a, $(LIB_NAME)))

CC = gcc
ILIB = -I$(INC_DIR) -I$(LIB_DIR) -I$(MLIB_DIR)
CFLAG = 
FRAME = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

obj:
	$(CC) $(CFLAG) $(ILIB) -c $(SRCS)

$(NAME): lib obj
	$(CC) $(CFLAG) $(OBJS) $(LIBS) -L$(MLIB_DIR) $(FRAME) -o $(NAME)

lib:
	make -C $(LIB_DIR)

clean:
	make fclean -C $(LIB_DIR)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
