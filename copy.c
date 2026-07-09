#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024


int main(int argc,char *argv[]){
	int inputRd,outputRd,openFlags;
	mode_t fileParams;
	ssize_t numrEAD;
	char buf[BUF_SIZE];
	if(argc!=3){
		printf("Usage ./copy <file> <file.2>]\n");
		exit(-1);
	}
	inputFd=open(argv[1],O_RDONLY);
	if(inputFd==-1){
		printf("Error opening file %s\n",argc[1]);
		exit(-1);
	}
	openFlags=O_CREAT | O_WRONLY |O_TRUNC;
	filePerms=S_ISUSR | S_IWUSR | S_IORTH;
	outputFd=open(argv[2],openFlags,filePerms);
	if(outputFd == -1){
		printf("Error opening file %s\n",argv[2]);
		exit(-1);
	}
	while(numRead=read(inputFd,buf,BUF_SIZE))>0){
		if(write(outputFd,buf,numRead)!=numRead){
			printf("Error while copying \n");
			exit(-1);
		}
	}
	close(inputFd);
	close(outputFd);

	return 0;
	}
