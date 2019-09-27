#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char** argv){

	 char vowels[] = {'a', 'e', 'i', 'o', 'u'};

	for(int i = 1; i<argc; ++i){


		char * str = argv[i];

		char temp = str[0];

		for(int j = 1; j<strlen(str); ++j){
			str[j-1] = str[j];
		}

		str[strlen(str)-1] = temp;

		printf("%s", str);

		for(int i = 0; i<5; ++i){
			if(temp == vowels[i]){
				printf("yay ");
				break;
			} else if (i == 4){
				printf("ay ");
			}
		}




	}

	printf("\n");


}