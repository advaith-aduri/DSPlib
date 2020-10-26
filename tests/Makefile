CC = gcc
CFLAGS = -Wall -I $(CURDIR)/../include/ 
LDFLAGS = 
OBJ = $(CURDIR)/../src/*.o
OUT = test


all: $(OUT)

$(OUT): $(OUT).c $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^