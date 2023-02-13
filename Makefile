# Constants
NAME		=	so_long
CFLAGS		=	-Wall -Wextra -Werror

# Directories path
DIR_SRCS	=	src/
DIR_HEADERS	=	header/
DIR_LIBFT	=	libft/
LIBFT		=	$(DIR_LIBFT)libft.a
DIR_MLX		=	mlx/

# Files path
HEADERS	=	$(DIR_HEADERS)so_long.h \
			$(DIR_HEADERS)structure.h \
			$(DIR_LIBFT)libft.h

SRCS	=	$(DIR_SRCS)so_long.c \
			$(DIR_SRCS)utils.c \
			$(DIR_SRCS)error.c \
			$(DIR_SRCS)create_map.c \
			$(DIR_SRCS)check_path.c \
			$(DIR_SRCS)hook.c \
			$(DIR_SRCS)print_map.c \
			$(DIR_SRCS)move.c \
			$(DIR_SRCS)collision.c

OBJS	=	$(SRCS:.c=.o)

# Rules
.PHONY :	all clean fclean re mlx libft

%.o: %.c	$(HEADERS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

all:		$(NAME)

${NAME}:	$(LIBFT) ${OBJS}
			$(MAKE) -C $(DIR_MLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -lX11 -lXext -L$(DIR_MLX) -o $(NAME)

$(LIBFT):		FORCE
			$(MAKE) -C $(DIR_LIBFT)

clean:
			${RM} ${OBJS}
			$(MAKE) clean -C $(DIR_LIBFT)

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C $(DIR_LIBFT)

re :		fclean all

FORCE :