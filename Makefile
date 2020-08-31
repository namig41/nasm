SRC_NAME = \
	  		main


SRCS 	= $(addsuffix .asm, $(SRC_NAME))
OBJS 	= $(addsuffix .o, $(SRC_NAME))

NAME 	= learn_nasm
CC 		= nasm
FLAGS 	= -f elf
LINK 	= ld


all: $(NAME)

obj: 
	@$(CC) $(FLAGS) $(SRCS)

$(NAME): obj
	@$(LINK) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

compile: re clean
	@./$(NAME)
	

