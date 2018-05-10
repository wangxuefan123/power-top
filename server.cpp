/*
 * server.cpp
 */

#include "udp_client_server.h"
#include <string.h>
#include <iostream>

#define RECV_BUFFER_LEN 100

int main(int argc, char *argv[])
{
	char recv_ip[] = "127.0.0.1";
	int  recv_port = 8888;
	udp_client_server::udp_server server = udp_client_server::udp_server(recv_ip, recv_port);

	// Recv UDP packet
	int recv_len;
	char data[RECV_BUFFER_LEN];
	std::cout << "Start recving UDP packets..." << std::endl;
	while (1) {
		recv_len = server.recv(data, RECV_BUFFER_LEN);
                data[recv_len] = '\0';
		// Print message
		std::cout << data << std::endl;
	}

	return 0;
}
