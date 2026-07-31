#include <stdio.h>
#include <stdlib.h>

int bang(int x){
	return ((x | (~x+1))>>31)+1;
}

int main() {
	int x = 3;
	int result  = bang(3);
	printf("%d\n",result);
}
