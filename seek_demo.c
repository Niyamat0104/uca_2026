#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char *argv[]){
	size_t len;
	off_t offset;
	int fd;
	char *buf;
	size_t numRead, numWritten;

	if(argc < 3) {
		printf("Usage: %s <file> {r<length> | w<string> s<offset>...}\n",argv[0]);
		exit(-1);
	}

	fd = open(argv[1],O_RDWR | O_CREAT, S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if(fd == -1){
		printf("Failed to open file\n");
		exit(-1);
	}
	for(int i = 2 ; i<argc ; i++) {
		switch(argv[i][0]){
			case 'w':
				numWritten = write(fd, &argv[i][1], strlen(&argv[i][1]));
				printf("\nNUmber of bytes written %ld\n",numWritten);
				break;
			case 'r':
				len = atoi(&argv[i][1]);
				buf = malloc(len);
				numRead = read(fd, buf, len);

				if(numRead == 0){
					free(buf);
					printf("we have reached at the end of the file\n");
					exit(-1);
				}
				for(int j = 0 ; j<numRead ; j++){
					printf("%c",(unsigned char)buf[j]);
				}

				printf("\n");
				free(buf);
				break;
			case 's':
				offset = atoi(&argv[i][1]);
				if(lseek(fd,offset,SEEK_CUR)==-1){
					printf("seek failed\n");
					exit(-1);
				}
				printf("seek succeeded\n");
				break;
			defualt:
				printf("Argument must be one of [wsr]\n");
				exit(-1);
		}
	}
	close(fd);
	return 0;
}




