#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
	printf("00\n");
	fflush(stdout);
	double a;
	int b;
	int sock, client, conn;
	socklen_t clientsize;
	char buffer[100];
	struct sockaddr_in adr, cli_adr;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&adr, sizeof(adr));
	printf("10");
	fflush(stdout);
	//b = scanf("%lf", &a);
	adr.sin_family = AF_INET;
	adr.sin_addr.s_addr = htons(INADDR_ANY);
	adr.sin_port = htons(7777);

	bind(sock,(struct sockaddr*) &adr, sizeof(adr));

	listen(sock, 2);
	printf("After Listen\n");
	fflush(stdout);
	printf("%lu\n",sizeof(adr));
	fflush(stdout);
	printf("Adter ClientSize");
	fflush(stdout);
	int x = 0;
	int all_socket[50];
	fd_set rdfs;
	int sockmax=sock+1;
	printf("Just Before While");
	fflush(stdout);

	while(1){
		
		// vide tous les sockets qu'on veut ecouter
		printf("Before FD_ZERO");
		fflush(stdout);

		FD_ZERO(& rdfs);
		FD_SET(sock, &rdfs);
		// rajoute connection de all_socket vers rdfs
		printf("After FD_ZERO");
		fflush(stdout);
		for(int i = 0; i < x; i++){
			FD_SET(all_socket[i], &rdfs);
		}

		// attends pour nouvelle connexion ou qu'il se passe quelquechose sur une connexion actuelle
		printf("Before Select");
		fflush(stdout);
		if(select(sockmax, &rdfs, NULL, NULL, NULL) == -1){
			printf("error select");
			fflush(stdout);
		}
		printf("After Select");
		fflush(stdout);
		// ajoute connexion
		if(FD_ISSET(all_socket[0], &rdfs)){
			client = accept(sock, (struct sockaddr*) &cli_adr, &clientsize);
			all_socket[x] = client;
			sockmax = conn + 1;
			printf("New Client Connected.");
			fflush(stdout);
			x++;
		}

		// traitement
		for(int i = 1; i < x; i++){
			// == connfd modification lecture
			conn = read(client, buffer, 100);		
			printf("message récupérer : %s\n ",buffer);
			fflush(stdout);
			write(client,buffer,100);
		}
	}
	printf("Adfter While");
	fflush(stdout);
	
}