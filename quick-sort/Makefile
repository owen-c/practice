CC=g++
CFLAGS=-c -Wall -Werror -Wextra -Wshadow -pedantic -std=gnu++98 -ggdb
LDFLAGS=
SOURCES=main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=quick-sort

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.ccp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
