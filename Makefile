# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cter-maa <cter-maa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/20 11:46:11 by cter-maa      #+#    #+#                  #
#    Updated: 2023/04/25 17:23:13 by cter-maa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 	= pipex
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS += -g
endif
RM 		= rm -f
SANITIZE = -fsanitize=address

# INCLUDES
INCLUDES	= -I ./libft -I ./libft/ft_printf

# LIBRARIES
PRINTF = ./libft/ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

# SOURCES
SRC =	SRC/main.c \
		SRC/commands.c \
		SRC/initialize.c \
		SRC/utils.c \
			
# OBJECTS
OBJ			= $(SRC:.c=.o)

# COLORS
DEF_COLOR 	= \033[0;39m	
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# RULES
$(NAME): $(OBJ)
#	$(MAKE) -C ./libft
#	$(MAKE) -C ./libft/ft_printf
	$(CC) $(OBJ) $(INCLUDES) $(LIBFT) $(PRINTF) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)pipex compiled $(DEF_COLOR)"

# RECIPES
all: $(NAME)

make comp: all clean
	@echo "$(GREEN)run that shit! $(DEF_COLOR)"
	 
debug:
	$(MAKE) DEBUG=1

rebug: fclean
	$(MAKE) debug
	
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./libft/ft_printf	
	$(RM) $(OBJ)
	@echo "$(YELLOW)pipex object files are removed $(DEF_COLOR)"

fclean: clean
	# $(MAKE) fclean -C ./libft
	# $(MAKE) fclean -C ./libft/ft_printf
	$(RM) $(NAME)
	@echo "$(YELLOW)pipex executable is removed $(DEF_COLOR)"
	
re: fclean all

