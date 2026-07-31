#include <stdio.h>
#include <stdlib.h>


int sign(int x){
	return ((x>>31) | (!!x));
}
int main(){
	int x = 130;
	int result = sign(x);
	printf("%d\n",result);
}
