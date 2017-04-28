#include "serveur.h"

int main(void)
{

	// TODO init listen et bind
	// dans le serveur faire le while

	pid_t pid;
	pid = getpid();
	for (int i = 0; i < 9; ++i)
	{
		if(pid==-1){
			printf(">> Erreur: echec du fork()\n");
		}else if(pid > 0){
			//pere
			pid = fork();
		}
	}
	serveur();
    
}