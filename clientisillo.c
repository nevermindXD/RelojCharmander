 #include <stdlib.h>
 #include <strings.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <netinet/in.h>
 #include <netdb.h> 
 #include <unistd.h>
 #include <signal.h>

#define MAX_BUF 1024
int bb=1;
int aa=1;
int sockfd;
int a, b, c, d, e;


void sleep (unsigned int secs) 
{
  int retTime = time(0) + secs;    
  while (time(0) < retTime);    
}
 

  void error(char *msg)
 {
     perror(msg);
     exit(0);
 }
 

void sen_cerrar_socket(int signo)
{
  if (signo == SIGINT)
  {
    printf("senial SIGINT recibida\n");
    close(sockfd);
    exit(1);
    bb++;aa++;
  }
}


 int main(int argc, char *argv[])
 {
   
    char * mander_pipe = "/tmp/mander_pipe";
    mkfifo(mander_pipe, 0666);
    char buf[MAX_BUF];
     int portno, n;
    int key;
     struct sockaddr_in serv_addr;
     struct hostent *server;
 
     char buffer[256];
     if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
     }
     portno = atoi(argv[2]);
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
         error("Socket no abierto");
     server = gethostbyname(argv[1]);
     if (server == NULL) {
         fprintf(stderr,"No hay host\n");
         exit(0);
     }
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
     serv_addr.sin_port = htons(portno);
     if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
         error("Sin conexion");


     char* charmilion_list[] = {
        "display",
        "0.png",
        NULL      
      };

     int init = 0;    
     pid_t hijo_id;
     hijo_id = fork ();
     int a = (int) getpid ();
     if (hijo_id == 0){ 
     		int b = (int) getpid ();

     		execvp("display", charmilion_list); 
        }
     else 
        {
         int c = (int) getpid ();

         hijo_id = fork ();
         if(hijo_id==0){
         	int d = (int) getpid ();
            	int b =0;
                do{ 
                    bzero(buffer,256);
                    n = read(sockfd,buffer,255);
                    key = open(mander_pipe, O_WRONLY);
                    
                    switch(buffer[0]){
                        case '0':
                        	if(b>1){
                            write(key, "0", sizeof("0"));
                        	}else{b++;}
                        break;
                        case '1':
                        	if(b>1){
                            write(key, "1", sizeof("1"));
                            }else{b++;}
                        break;
                        case '2':
                        	if(b>1){
                            write(key, "2", sizeof("2"));
                            }else{b++;}
                        break;
                        case '3':
                        	if(b>1){
                            write(key, "3", sizeof("3"));
                            }else{b++;}
                        break;
                        case '4':
                        	if(b>1){
                            write(key, "4", sizeof("4"));
                            }else{b++;}
                        break;
                        case '5':
                        	if(b>1){
                            	write(key, "5", sizeof("5"));
                            }else{b++;}
                        break;
                        case '6':
                        	if(b>1){
                            	write(key, "6", sizeof("6"));
                            }else{b++;}
                        break;
                        case '7':
                        	if(b>1){
                            	write(key, "7", sizeof("7"));
                            }else{b++;}
                        break;
                        case '8':
                        	if(b>1){
                            	write(key, "8", sizeof("8"));
                            }else{b++;}
                        break;
                        case '9':
                        	if(b>1){
                            write(key, "9", sizeof("9"));
                            }else{b++;}
                        break;
                    }
                    close(key);
                    if (signal(SIGINT, sen_cerrar_socket) == SIG_ERR){
	  					printf("\nSin senial\n");
                    }
                    }while (bb==1);   
            }else{
            	int e = (int) getpid ();
            	int a=0;
             	do{ 
                    key = open(mander_pipe, O_RDONLY);
                    read(key, buf, MAX_BUF);
                    char a = buf[0];
                    switch(a){
                        case '0':
                        	if(a>1){
                            	system("display -remote 0.png");
                            }else{a++;}
                            break;
                        case '1':
                        	if(a>1){
                            	system("display -remote 1.png");
                            }else{a++;}
                            break;
                        case '2':
                        	if(a>1){
	                            system("display -remote 2.png");
                            }else{a++;}
                            break;
                        case '3':
                        	if(a>1){
                            	system("display -remote 3.png");
                            }else{a++;}
                            break;
                        case '4':
                        	if(a>1){
                            	system("display -remote 4.png");
                            }else{a++;}
                            break;
                        case '5':
                        	if(a>1){
                            	system("display -remote 5.png");
                            }else{a++;}
                            break;
                        case '6':
                        	if(a>1){
                            	system("display -remote 6.png");
                            }else{a++;}
                            break;
                        case '7':
                        	if(a>1){
                            	system("display -remote 7.png");
                            }else{a++;}
                            break;
                        case '8':
                        	if(a>1){
	                            system("display -remote 8.png");
                            }else{a++;}
                            break;
                        case '9':
                        	if(a>1){
                            	system("display -remote 9.png");
                            }else{a++;}
                            break;
                    }
                    close(key);
                    if (signal(SIGINT, sen_cerrar_socket) == SIG_ERR){
	  					printf("\nCan't catch signal\n");
                    }
                    }while (aa==1);
            }
        }
 }