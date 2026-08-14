#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc , char* argv[]){
    if(argc < 2){
        printf("Usage : <filename> <input_File_name>");
        return 0;
    }
    char *file = argv[1];
    struct stat info;
    int result = stat(file,&info);
    if(result == -1){
        printf("Not able to access the given file");
        perror("stat");
        return 0;
    }
    printf("=== File Attrributes for : %s ===\n",file);
    if(S_ISREG(info.st_mode)){
        printf("File Type:         %s\n",    "Regular File");
         
    }
    else if(S_ISDIR(info.st_mode)){
        printf("File Type:         %s\n",    "Directory");
    }
    else if (S_ISLNK(info.st_mode))
    printf("File Type:             Symbolic Link\n");
    else if (S_ISCHR(info.st_mode))
        printf("File Type:         Character Device\n");
    else if (S_ISBLK(info.st_mode))
        printf("File Type:         Block Device\n");
    else if (S_ISFIFO(info.st_mode))
        printf("File Type:         FIFO\n");
    else if (S_ISSOCK(info.st_mode))
        printf("File Type:         Socket\n");
    else
    printf("File Type:            Unknown\n");
    printf("Permissions :        %d\n",info.st_mode & 0777);
    printf("File Size :          %ld bytes\n",info.st_blksize);
    printf("Hard LInk Count :    %ld\n",info.st_nlink);
    printf("Owner (UID) :        %d\n",info.st_uid);
    printf("Group (GID) :        %d\n",info.st_gid);
    printf("Last Access Time :   %s\n",ctime(&info.st_atime));
    printf("Last Modification :  %s\n",ctime(&info.st_mtime));
    printf("Status Change Time : %s\n",ctime(&info.st_ctime));



}
