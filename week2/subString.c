#include<stdlib.h>
#include<stdio.h>

int find_substring( const char *haystack , const char *needle) {
	const char *h;
	const char *n;
	int index = 0;

	if(*needle == '\0') {
		return 0;
	}

	while(*haystack != '\0') {
		h = haystack ;
		n = needle;

		while(*h != '\0' && *n != '\0' && *h == *n ) {
		       h++;
	               n++;
		}
 		
		if (*n == '\0') {
			return index;
		}

		haystack ++;
		index++;
	}
	return -1;
}

int main() {
	char haystack[] = "Embedded Systems";
	char needle[] = "bed";
	printf("%s starts at index \%d\n",needle,find_substring(haystack,needle));
			
}	

	

