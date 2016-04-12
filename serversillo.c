#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>


void sleep (unsigned int secs) 
{
  int retTime = time(0) + secs;    
  while (time(0) < retTime);    
}

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int a = 0;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int sockfd, puerto, clilen;
     int n,n2,n3,n4;
     int socektN, socektN2, socektN3, socektN4;
     if (argc < 2) {
         fprintf(stderr,"Sin puerto\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("Socket no abierto");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     puerto = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(puerto);

     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     while(a<1){
        if(a==0){
            socektN = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (socektN < 0){
                error("NO aceptado");
            }else{a=1;printf("%d\n", a);}
        }
        /*if(a==1){
            socektN2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (socektN2 < 0){
                error("ERROR on accept");
            }else{a++;printf("%d\n", a);}
        }
        if(a==2){
            socektN3 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (socektN3 < 0){
                error("ERROR on accept");
            }else{a++;printf("%d\n", a);}
        }
        if(a==3){
            socektN4 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (socektN4 < 0){
                error("ERROR on accept");
            }else{a++;printf("%d\n", a);}
        }*/
     }
     if (a==1){
     do{
        time_t fecha;
        struct tm *temp;
        struct tm fecha_tm;

        temp = localtime(&fecha);
        memcpy(&fecha_tm, temp, sizeof fecha_tm);

        int hord=fecha_tm.tm_hour/10;
        int horu=fecha_tm.tm_hour%10;
        int mind=fecha_tm.tm_min/10;
        int minu=fecha_tm.tm_min%10;
        int segd= fecha_tm.tm_sec/10;
        int segu= fecha_tm.tm_sec%10;

        char dhora[] = {hord+48};
        char dmin[] = {mind+48};
        char dseg[]  = {segd+48};
        char uhora[] = {horu+48};
        char umin[] = {minu+48};
        char useg[]  = {segu+48};
        
        nmind = write(socektN,dmin,1);
        /*
        nminu = write(socektN2,umin,1);
        nsegd = write(socektN3,dseg,1);
        nsegu = write(socektN4,useg,1);*/
        sleep(1);
     }while(1==1);
    }
}
