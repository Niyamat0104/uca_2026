#include <stdio.h>
#include <stdlib.h>

int conditional(int x , int y ,int z) {
	int mask = ~!!x + 1;
	return ((mask & y) | (~mask & z));

}

int main() {
	int x = 4;
	int y =5 ;
	int z = 2;
	int result = conditional(x,y,z);


	printf("%d\n",result);
}
