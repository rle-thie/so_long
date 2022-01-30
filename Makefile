SRCS	= $(addprefix srcs/, main.c parsing/parse_input.c \
			parsing/parse_input_utils.c utils/init_data.c \
			utils/ft_strlen.c utils/get_next_line.c \
			utils/get_next_line_utils.c utils/ft_error.c game/game.c \
			game/move.c game/game_utils.c)

OBJS	= ${SRCS:.c=.o}

NAME = so_long

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re