#include <stdio.h>
#include <string.h>

void main() {
    char str1[6], str2[6] = "Shakil";
    strcpy(str1, "Mehedi_Hasan");
    printf("%s\n%s\n", str1, str2);
    printf("%p\n%p\n%p\n", str1, str1+6, str2);
}