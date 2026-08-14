#include <stdio.h>
#include <stdlib.h>

int getByte(int x , int n){
	return (x>>(n<<3)) & 0xFF;
}
int main(){
	int result = getByte(0x12345678,1);
	printf("%x\n",result);
}


