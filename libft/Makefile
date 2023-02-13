.PHONY 	= 	all clean fclean re

NAME 	= 	libft.a

CFLAGS 	= 	-Wall -Werror -Wextra

SRCS 	= 	ft_check_args.c\
		  	ft_print_char.c\
		  	ft_print_nbr.c\
		  	ft_printf.c\
		  	get_next_line.c\
		  	get_next_line_utils.c\
			ft_itoa.c


OBJS 	= 	$(SRCS:.c=.o)

RM 		= 	rm -f

HEADER 	=	libft.h 

all: 		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o : 		%.c $(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -I.

clean :
			$(RM) $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re : 		fclean $(NAME)