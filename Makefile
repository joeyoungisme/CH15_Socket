CC = gcc
CLIENT = Client
SERVER = Server

OBJ = $(CLIENT).o $(SERVER).o

BINARY = $(CLIENT) $(SERVER)

.SUFFIXES: .o .c

.c.o:
	$(CC) -c $< -o $@

all: $(OBJ)
	$(CC) -o $(CLIENT) $(CLIENT).o
	$(CC) -o $(SERVER) $(SERVER).o

clean:
	rm -f $(BINARY) *.o
