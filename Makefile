CC = gcc
CFLAGS = -I $(CURDIR)/include/ -lm -lpthread -lrt
OUT = ./lib/libDSPlib.a
SRC = ./src
DEP = $(INC)/signal.h
OBJ = ./src/signal.o ./src/time_domain.o ./src/plot_time.o ./src/plot_freq.o ./src/util.o ./src/frequency_domain.o ./src/FFT_Threaded.o

all: $(OUT)

$(OUT): $(OBJ) 
	ar -rcs $(OUT) $(OBJ)

$(SRC)/%.o: $(SRC)/%.c  $(DEP)
	$(CC) -c -o $@ $^ $(CFLAGS) 

clean:
	rm $(SRC)/*.o

