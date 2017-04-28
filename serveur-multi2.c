#include "serveur.h"

void serveur() {
	int sock, client, conn;
	socklen_t clientsize;
	char buffer[100];
	struct sockaddr_in adr, cli_adr;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&adr, sizeof(adr));
	
	adr.sin_family = AF_INET;
	adr.sin_addr.s_addr = htons(INADDR_ANY);
	adr.sin_port = htons(7777);

	bind(sock,(struct sockaddr*) &adr, sizeof(adr));


	// listen(sock, 2);
	listen(sock, 10);
	
	printf("%lu\n",sizeof(adr));
	fflush(stdout);
	clientsize = sizeof(adr);
	
	
	int x = 0;
	int all_socket[50];
	fd_set rdfs;
	int sockmax=sock+1;
	

	while(1){
		
		// vide tous les sockets qu'on veut ecouter
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

		//gestion de la fermeture
		// TODO use shotdown(fd, howto) // mettre flag 
	}
	printf("Adfter While");
	fflush(stdout);
	
}