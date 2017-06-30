#include "serveur.h"

/*	compile multiple file :
	gcc -Wall main.c serveur-multi2.c -o serveur-multi2
	execute :
	./serveur-multi2

	debugage serveru-multi2
	ps -ef | grep serveur-multi2
	kill -9 PID
*/

int main(void)
{

	//TODO init listen et bind
	int sock;
	socklen_t clientsize;
	struct sockaddr_in adr;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&adr, sizeof(adr));
	
	adr.sin_family = AF_INET;
	adr.sin_addr.s_addr = htons(INADDR_ANY);
	adr.sin_port = htons(7777);

	bind(sock,(struct sockaddr*) &adr, sizeof(adr));


	//listen(sock, 2);
	listen(sock, 10);
	
	// printf("%lu\n",sizeof(adr));
	// fflush(stdout);
	clientsize = sizeof(adr);


	// dans le serveur faire le while

	pid_t pid;
	pid = getpid();
	for (int i = 0; i < 9; ++i)
	{
		if(pid==-1){
			printf(">> Erreur: echec du fork()\n");
			fflush(stdout);
		}else if(pid > 0){
			//pere
			pid = fork();
		}
	}
	//serveur(sock, clientsize, buffer);
	serveurTest(sock);
    
}