#include "serveur.h"

int const MAX = 10000;
int const MIN = 1000;

struct Monstre{
    int vie;
    int attaque;
    //attaque de zone ?
   // int aoe;

};

void serveurTest(int sockM) {
	int sock = sockM, client, conn;
	printf("sock = %d \n", sock);
	fflush(stdout);
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

	Monstre m;
	int sockmax=sock+1;
	int random =0;

    srand(time(NULL));
    random = (rand() % ((MAX-MIN +1)+MIN);

    m.vie = random;
    m.attaque = random /10;

	printf("Nouveau serveur \n");
	fflush(stdout);

	while(1){

		// vide tous les sockets qu'on veut ecouter
		FD_ZERO(& rdfs);
		FD_SET(sock, &rdfs);
		// rajoute connection de all_socket vers rdfs
		printf("%d After FD_ZERO\n", getpid());
		fflush(stdout);
		for(int i = 0; i < x; i++){
			FD_SET(all_socket[i], &rdfs);
		}


		// attends pour nouvelle connexion ou qu'il se passe quelquechose sur une connexion actuelle
		printf("%d Before Select\n", getpid());
		fflush(stdout);
		if(select(sockmax, &rdfs, NULL, NULL, NULL) == -1){
			printf("error select");
			fflush(stdout);
		}
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
		// traitement
		for(int i = 0; i < x; i++){
			// == connfd modification lecture
			conn = read(client, buffer, 100);
			//convertie le buffer en Int et me soustrait à la vie
			m.vie -= atoi(buffer);

			printf("il reste %d vie au monstre \n",m.vie);
			fflush(stdout);
			//attauque
			sprintf(buffer, "%d", m.attaque);
			write(client,buffer,100);

		}

		printf("%d After traitement\n", getpid());
		fflush(stdout);

		//gestion de la fermeture
		if(shutdown(all_socket[x-1], SHUT_RDWR) == -1){
			printf("error close");
			fflush(stdout);
		}
		// TODO use shotdown(fd, howto) // mettre flag
	}
	printf("Adfter While \n");
	fflush(stdout);

}
