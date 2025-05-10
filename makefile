CC = gcc

SRC = $(wildcard* .c)
OBJ = $(SRC: .c=.o)

all: exec

%.o : %.c animal.h
        $(CC) -c $< -o $@
        
exec : $(OBJ)
        $(CC) $^ -o $@ 

clean: 
	rm -f $(OBJ)		