#include <stdio.h>
#include <stdlib.h>

int bitAnd(int x , int y){
	return ~(~x | ~y);
}
int main(){
	int a = 6;
	int b = 5;
	int ans = bitAnd(a,b);
	printf("%d",ans);
}

