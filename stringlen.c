#include<stdio.h>
#include<stdlib.h>



int my_strlen(const char *str) {
	int length = 0;
	while(str[length] != '\0') {
		length ++;
	}
	return length;
}
	
int main() {
	char str[100];
	scanf("%99s",str);
	printf("Length = %d\n",my_strlen(str));
	return 0;
}
	
