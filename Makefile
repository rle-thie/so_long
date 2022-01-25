SRCS = main.c \
		

OBJS = ${SRCS:.c=.o}

NAME = so_long.a

CC = gcc

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}:    ${OBJS}
		${CC} ${CFLAGS} srcs/*.o srcs/*/*.o gnl/*.o -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

bonus:	${OBJS_BONUS}
		ar rc ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}