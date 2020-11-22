CC = gcc
CFLAGS = -I $(CURDIR)/include/ -lm -lpthread -lrt
OUT = ./lib/libDSPlib.a
SRC = ./src
LIB = ./lib
INC = ./include
DEP = $(INC)/signal.h
OBJ = ./lib/signal.o ./lib/time_domain.o ./lib/plot_time.o ./lib/plot_freq.o ./lib/util.o ./lib/frequency_domain.o ./lib/FFT_Threaded.o

all: $(OUT)

$(OUT): $(OBJ) 
	ar -rcs $(OUT) $(OBJ)

$(LIB)/%.o: $(SRC)/%.c  $(DEP)
	$(CC) -c $< -o $@ $(CFLAGS) 

clean:
	rm $(LIB)/*.o

