#include <stdio.h>
#include <stdlib.h>

int bitXor(int x , int y){
	return ~(~(x & ~y) & ~(~x & y));
}

int main() {
	int x = 4;
	int y = 5;
	int ans = bitXor(x,y);
	printf("%d\n",ans);
}

