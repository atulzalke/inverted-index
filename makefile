SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

inverted_searc.exe : $(OBJ)
	gcc -o $@ $(OBJ) -lm

clear : 
	rm *.o *.exe
