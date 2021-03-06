SRCS	= $(addprefix srcs/, main.c \
							parsing/init_parsing.c \
							parsing/parsing_utils.c \
							utils/get_next_line.c \
							utils/get_next_line_utils.c \
							utils/error.c \
							game/game.c \
							game/move.c \
							game/game_utils.c)

OBJS	= ${SRCS:.c=.o}

NAME 	= so_long

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o ${<:.c=.o}

# pour mac
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

#pour mac
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re