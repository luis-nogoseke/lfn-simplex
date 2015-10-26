CC=clang++
CC_FLAGS=-std=c++11
SOURCES=$(wildcard */*.cc)
OBJECTS = $(SOURCES:.cc=.o)
EXEC = lfnsimplex
INCLUDES = include/


all: $(OBJECTS)
	$(CC) -g -I$(INCLUDES) $(OBJECTS) -o $(EXEC)


%.o: %.cc
	$(CC) -c -g -I$(INCLUDES) $(CC_FLAGS) $< -o $@ 
 
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)