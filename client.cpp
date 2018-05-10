/*
 * client.cpp
 */

#include "udp_client_server.h"
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char dst_ip[] = "192.168.1.14";
	int dst_port = 8888;
	udp_client_server::udp_client client = udp_client_server::udp_client(dst_ip, dst_port);

	while (1) {
		const char *msg = "Hello WXF";
		client.send(msg, strlen(msg));
		sleep(1);
	}
	return 0;
}
