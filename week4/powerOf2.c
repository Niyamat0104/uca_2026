#include <stdio.h>
#include <stdlib.h>


int powerOf2(int x){
	return !(x & (x+~0)) & !!x & !(x>>31);
}
int main() {
	int x  = 16;
	int result = powerOf2(x);
	printf("Result %d\n",result);
}

