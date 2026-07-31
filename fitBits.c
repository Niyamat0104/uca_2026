#include <stdio.h>
#include <stdlib.h>

int fitBits(int x , int k){
	int shift = 32 + (~k + 1);
	return !(((x << shift) >> shift) ^ x);
}

int main() {
	int x = 5;
	int k =3;
        int result = fitBits(x,k);
	printf("%d\n",result);
}
