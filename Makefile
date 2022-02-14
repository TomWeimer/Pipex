PROG =pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = child_process.c find_path.c ft_split.c parent_process.c ft_pipex.c utils.c
OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o  ${<:.c=.o}

all: ${PROG}

${PROG} : ${OBJS}
	${CC} ${CFLAGS} -o ${PROG} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${PROG}

re: fclean all

.PHONY: all clean fclean re