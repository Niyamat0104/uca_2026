#include <stdio.h>
#include <stdlib.h>

int logicalShift(int x , int n) {
	int mask = ~(((1<<31)>>n)<<1);
	return (x>>n) & mask;
}
int main() {
	int x = 0x87654321;
	int result = logicalShift(x, 4);
	printf("%x\n",result);
}


