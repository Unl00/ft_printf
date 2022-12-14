SRCS 		= ft_printf.c \
				ft_printchar.c \
				ft_printnbr.c \
				ft_printptr.c \
				ft_printstr.c \
				ft_printnbr_u.c \
				ft_print_x.c
OBJS 		= ${SRCS:.c=.o}
NAME 		= libftprintf.a
GCC 		= gcc
RM 			= rm -f
FLAGS 		= -Wall -Wextra -Werror

all			:	${NAME}

${NAME}		:	${OBJS}
		@ar rcs ${NAME} ${OBJS}

clean		:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean		: clean
	${RM} ${NAME}

re			: fclean ${NAME}

.PHONY		: all clean fclean re bonus