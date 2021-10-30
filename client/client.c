#include<fcntl.h>
//#include<sys/mode.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main(void)
{
    	int descW;
	char prenom[20];

	/* On demande le nom du client, qui est tu ?*/
	printf("Bonjour bienvenu de le jeu Qui est-ce ?\n");
	printf("Quel est votre Prenom?\n");
	scanf("%s", prenom);
	
	
    	descW=open("../server/main",O_WRONLY); // on ouvre le pipe main en ecriture
    	write(descW,prenom,20); // on ecrit le nom du nouveau client
    
	close(descW); // on ferme le descripteur

	while(1); 
	/* pour l'instant on fait rien on attend la suite c.à.d. se mettre à 
	 * l'ecoute du pipe créer avec notre prenom */
}
