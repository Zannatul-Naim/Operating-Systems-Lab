#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	char str1[4], str2[4] = "";
	int i, len;
	
	strcpy(str1, "abcdefgrh");
	printf("%s, %s\n", str1, str2);
	/*len = sizeof(str2);
	for(i = 0; i <len + 1; i++){
		str2[i] = 42;
		printf("%s, %s\n", str1, str2);
	}*/
}
