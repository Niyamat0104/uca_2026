#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}
void reverse_string(char *str) {
	int left = 0;
	int right = my_strlen(str) - 1;
	while( left <  right) {
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left ++;
		right --;
	}
}
int main(){
	char str[100];
	scanf("%99s",str);
	reverse_string(str);
	printf("Reversed String : %s\n",str);
	return 0;
}

