
SRCS 	= main.c main1.c main2.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${CC} -o ${NAME} ${OBJS}

all: 		${NAME}

clean: 
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
