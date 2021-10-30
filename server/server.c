#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	int pid,descR,nb ;
    	char buf[80];
    	unlink("main");
    	mkfifo("main",0666); // creation du pipe
    
    	descR=open("main",O_RDONLY); //ouverture du pipe
    	nb=read(descR,buf,80); // Ecoute sur le pipe main par bloc de 80 max
    
    	/*post traitement de ce q'uon recoit dans le pipe à ajouter ici*/
    	buf[nb]='\0';
    	printf("message: %s\n",buf);
    	
	/****************Gestion processus***********************/
	/* on cree un processus des qu'il y a un nouveau client */
    	//pid=fork();
	
    	//if(pid == 0)
	
        	//execv("ici la modularite", NULL);
		
    	//wait(NULL); // on attende la fin du processus fils
	
	/**************Fin gestion processus*********************/

    	close(descR); // fermeture du descripteur lecture
    
    	exit(0);
}
