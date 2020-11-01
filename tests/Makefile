CC = gcc
CFLAGS = -I $(CURDIR)/../include/ -lm 
LDFLAGS = 
OBJ = $(CURDIR)/../src/*.o
OUT = test


all: $(OUT)

$(OUT): $(OUT).c $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS)