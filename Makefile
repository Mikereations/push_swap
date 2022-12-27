NAME = push_swap

SOURCES = ./error.c ./ft_isnumeric.c ./p_r_utils.c ./push_swap.c ./r_utils.c ./s_utils.c ./short_hands.c ./sorting_utils.c ./sorting.c ./stack_utils.c ./locators.c ./splitter.c ./dispay.c push_swap_utils.c

OBJECTS = $(SOURCES:.c=.o);

CFLAGS = -Wall -Werror -Wall -g

CC = gcc

libft =  ./libft/libft.a

printf = ./printf/libftprintf.a

${NAME} : $(SOURCES)
	$(MAKE) -C ./libft
	$(MAKE) -C ./printf
	${CC} ${CFLAGS} -o push_swap $(SOURCES) $(libft) $(printf)

all : ${NAME}

clean :
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./printf

fclean :
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./printf
	rm -f ${NAME}

re : fclean all
