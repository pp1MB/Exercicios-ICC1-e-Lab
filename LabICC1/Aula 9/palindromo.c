#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, verif;
	char str[10000];
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", str);
		for(verif=0;verif<strlen(str)/2;verif++){
			if(str[verif]!=str[strlen(str)-verif-1]){ 
				printf("%s nao eh um palindromo\n", str);
				break;
			}
		}
		if(str[verif]==str[strlen(str)-verif-1]) printf("%s eh um palindromo\n", str);
	}
	
	return 0;
}