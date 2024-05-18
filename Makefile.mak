CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
OBJS = student.o grades.o display.o main.o
TARGET = student_grades

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

grades.o: grades.c student.h
	$(CC) $(CFLAGS) -c grades.c

display.o: display.c student.h
	$(CC) $(CFLAGS) -c display.c

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)
