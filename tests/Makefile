CC = gcc
CFLAGS = -I $(CURDIR)/../include/ -std=gnu99 -lm -lpthread -lrt
LDFLAGS = 
OBJ = $(CURDIR)/../src/*.o
OUT = test


all: $(OUT)

$(OUT): $(OUT).c $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS)