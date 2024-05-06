CC = gcc
CFLAGS = -Wall -Werror -Wextra
VALGRIND = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all
SRCS_ENC := $(wildcard **/*.c **/*/*.c)
NOT_SRC = $(wildcard **/test*.c **/*/test*.c)
SRCS_ENC := $(filter-out $(NOT_SRC), $(SRCS_ENC))

run:
	${CC} ${CFLAGS} ${SRCS_ENC} -o dstest
	./dstest

memcheck:
	${CC} ${CFLAGS} ${SRCS_ENC} -o dstest
	${VALGRIND} ./dstest

clean:
	rm dstest
