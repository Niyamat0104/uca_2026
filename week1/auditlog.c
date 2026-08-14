#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LOGFILE "audit.log"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Usage:\n");
		printf("./auditlog --add \"message\"\n");
		printf("./auditlog --view\n");
		return 1;
	}

	if(strcmp(argv[1],"--add")==0){
		if(argc<3){
			printf("Error:No message provided.\n");
			return 1;
		}
		int fd=open(LOGFILE,O_WRONLY | O_CREAT | O_APPEND,0644);
		if(fd<0){
			perror("open");
			return 1;
		}
		write(fd,argv[2],strlen(argv[2]));
		write(fd,"\n",1);
		close(fd);
	}
	else if(strcmp(argv[1], "--view")==0){
		int fd=open(LOGFILE , O_RDONLY);
		if(fd<0){
			perror("open");
			return 1;
		}
		char buffer[BUFFER_SIZE];
		int bytesRead;
		int line=1;
		printf("%d: ",line);
		while((bytesRead = read(fd,buffer,sizeof(buffer)))>0){
			for(int i=0;i<bytesRead;i++){
				write(STDOUT_FILENO, &buffer[i],1);
				if(buffer[i]=='\n'){
					line++;
					if(i!=bytesRead - 1){
						printf("%d: ",line);
					}
				}
			}
		}
		close(fd);
	}
	else{
		printf("Inavlid option. \n");
	}
	return 0;
}

		
