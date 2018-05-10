# Compiler
CC = g++

# Compiling options
CFLAGS = -c -Wall -g
# CFLAGS = -c -g

# Compiling header and libs
HEADER = -I./  # header files

# Compiling rules
# ---------------------------------------------------------
all:
	echo "Make it."

server: server.o udp_client_server.o
	$(CC) server.o udp_client_server.o -o server

client: client.o udp_client_server.o
	$(CC) client.o udp_client_server.o -o client

udp_client_server.o: udp_client_server.cpp
	$(CC) $(CFLAGS) $(HEADER) udp_client_server.cpp

client.o: client.cpp
	$(CC) $(CFLAGS) $(HEADER) client.cpp

server.o: server.cpp
	$(CC) $(CFLAGS) $(HEADER) server.cpp

clean:
	rm *.o
	rm ./server
	rm ./client
# ---------------------------------------------------------
