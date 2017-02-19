#include <stdio.h>
#include <string.h>

char a[200];
int main(void)

{
	int i , k=0;
	while(scanf("%s" , a)!=EOF){
	printf("%c" , a[0]);
	for(i=1 ; i<strlen(a)-3 ; i++){
		if(a[i]!='a'&&a[i]!='d'){
			printf("%c" , a[i]);
		}
		else{
			if(a[i]=='a'&&a[i+1]=='t' && k==0){
				printf("%c" , '@');
				i++;
				k=1;
				continue;
			}

				if(a[i+1]!='t' && a[i]=='a'){
					printf("%c" , a[i]);
				}

			else{
				if(a[i]=='d' && a[i+1]=='o'&&a[i+2]=='t'){
					printf("%c" , '.');
					i+=2;
					continue;
				}
				printf("%c" , a[i]);

			}

		}

	}
	printf("%c%c%c" , a[i] , a[i+1] , a[i+2]);
	puts("");
}
	return 0;
}
