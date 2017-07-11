#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <stdlib.h>

int const MAX = 1000;
int const MIN = 100;

struct Personnage{
    int vie;
    int attaque;
};

int main(void) {
    Personnage p;
    int random =0;

    srand(time(NULL));
    random = (rand() % ((MAX-MIN +1)+MIN);

    p.vie = random;
    p.attaque = random /10;

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

	// est-il possible de passer un int ?
	sprintf(buffer, "%d", m.attaque);
	write(sock, buffer,100);
		read(sock, buffer,100);
		m.vie -= atoi(buffer);
		printf("reste de vie du client: %d\n", m.vie);
		fflush(stdout);

	// while(1){
	// 	write(sock, "Hello",5);
	// 	read(sock, buffer,100);
	// 	printf("message du serveur : %s\n", buffer);
	// 	fflush(stdout);
	// }

}
