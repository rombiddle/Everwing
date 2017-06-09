#include "serveur.h"

void serveurTest(int sockM) {
	int sock = sockM, client, conn;
	socklen_t clientsize;
	char buffer[100];
	struct sockaddr_in cli_adr;

	// sock = socket(AF_INET, SOCK_STREAM, 0);

	// bzero(&adr, sizeof(adr));
	
	// adr.sin_family = AF_INET;
	// adr.sin_addr.s_addr = htons(INADDR_ANY);
	// adr.sin_port = htons(7777);

	// bind(sock,(struct sockaddr*) &adr, sizeof(adr));


	// //listen(sock, 2);
	// listen(sock, 10);
	
	// // printf("%lu\n",sizeof(adr));
	// // fflush(stdout);

	// clientsize = sizeof(adr);
	
	
	int x = 0;
	int all_socket[50];
	fd_set rdfs;
	int sockmax=sock+1;

	printf("Nouveau serveur \n");
	fflush(stdout);

	while(1){
		
		// vide tous les sockets qu'on veut ecouter
		FD_ZERO(& rdfs);
		FD_SET(sock, &rdfs);
		// rajoute connection de all_socket vers rdfs
		printf("After FD_ZERO\n");
		fflush(stdout);
		for(int i = 0; i < x; i++){
			FD_SET(all_socket[i], &rdfs);
		}
		

		// attends pour nouvelle connexion ou qu'il se passe quelquechose sur une connexion actuelle
		printf("Before Select\n");
		fflush(stdout);
		if(select(sockmax, &rdfs, NULL, NULL, NULL) == -1){
			printf("error select");
			fflush(stdout);
		}
		printf("After Select and Before Ajout Client.\n");
		fflush(stdout);
		// ajoute connexion
		if(FD_ISSET(sock, &rdfs)){
			printf("isset entered\n");
			fflush(stdout);
			client = accept(sock, (struct sockaddr*) &cli_adr, &clientsize);
			all_socket[x] = client;
			sockmax = conn + 1;
			printf("New Client Connected. \n");
			fflush(stdout);
			x++;
		}
		printf("After Ajout Client And Before traitement\n");
		fflush(stdout);
		// traitement
		for(int i = 0; i < x; i++){
			// == connfd modification lecture
			conn = read(client, buffer, 100);		
			printf("message récupérer : %s\n ",buffer);
			fflush(stdout);
			write(client,buffer,100);
			
		}

		printf("After traitement\n");
		fflush(stdout);

		//gestion de la fermeture
		// TODO use shotdown(fd, howto) // mettre flag 
	}
	printf("Adfter While \n");
	fflush(stdout);
	
}