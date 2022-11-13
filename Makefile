SRCS 		= ft_printf.c
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