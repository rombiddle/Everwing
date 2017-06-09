#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
/* ^^ these are the include guards */

/* Prototypes for the functions */
/* Sums two ints */
void serveur(int sock, socklen_t clientsize, char buffer[]);
void serveurTest();

#endif