CC = gcc
CFLAGS = -Wall -lm
SRCS_ENC := $(wildcard **/*.c **/*/*.c)
NOT_SRC = $(wildcard **/test*.c **/*/test*.c)
SRCS_ENC := $(filter-out $(NOT_SRC), $(SRCS_ENC))

run:
	${CC} ${CFLAGS} ${SRCS_ENC} -o dstest && ./dstest

clean:
	rm *.o; rm dstest
