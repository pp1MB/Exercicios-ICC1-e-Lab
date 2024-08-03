#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	char str[26], *p;
	scanf("%[^\n]s", str);
	p = &str;

	while(*p!='\0'){
        printf("%c\n", *p);
        p++;
	}
    return 0;

}
