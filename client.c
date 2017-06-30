#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(void) {
	printf("Start Client2\n");
	fflush(stdout);

	int sock, conn;
	char buffer[100];
	struct sockaddr_in adr; 

	sock = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&adr, sizeof(adr));

	adr.sin_family = AF_INET;
	adr.sin_addr.s_addr = htons(INADDR_ANY);
	adr.sin_port = htons(7777);


	conn = connect(sock,(struct sockaddr*) &adr, sizeof(adr));

	write(sock, "Hello",5);
		read(sock, buffer,100);
		printf("message du serveur : %s\n", buffer);
		fflush(stdout);

	// while(1){
	// 	write(sock, "Hello",5);
	// 	read(sock, buffer,100);
	// 	printf("message du serveur : %s\n", buffer);
	// 	fflush(stdout);
	// }

}
