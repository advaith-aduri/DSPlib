CC = gcc
CFLAGS = -I $(CURDIR)/include/ -lm
OUT = ./lib/libDSPlib.a
SRC = ./src
DEP = $(INC)/signal.h
OBJ = ./src/signal.o ./src/time_domain.o ./src/plot.o ./src/util.o

all: $(OUT)

$(OUT): $(OBJ) 
	ar -rcs $(OUT) $(OBJ)

$(SRC)/%.o: $(SRC)/%.c  $(DEP)
	$(CC) -c -o $@ $^ $(CFLAGS) 

