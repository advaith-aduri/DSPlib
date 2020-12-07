CC = gcc
CFLAGS = -I $(CURDIR)/../include/ -std=gnu99 -lm -lpthread -lrt
LDFLAGS = 
OBJ = $(CURDIR)/../lib/*.o
OUT = F_op


all: $(OUT)

$(OUT): $(OUT).c $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS)