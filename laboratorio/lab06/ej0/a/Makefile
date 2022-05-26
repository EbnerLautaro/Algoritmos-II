CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = main.c queue_helpers.c queue.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = executable
VALGRIND = valgrind --leack-check=full

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)
	$(RM) $(OBJECTS)	#elimina todos los .o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)



