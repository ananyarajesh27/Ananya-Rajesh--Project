CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c student.c grades.c display.c
OBJS = $(SRCS:.c=.o)
EXEC = grade_card

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJS)
