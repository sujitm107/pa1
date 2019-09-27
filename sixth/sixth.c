#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char* shift(char*);

char* shift(char* str){

	char temp = str[0];

	for(int j = 1; j<strlen(str); ++j){
		str[j-1] = str[j];
	}
	str[strlen(str)-1] = temp;

	return str;

}

int main(int argc, char** argv){

	char vowels[] = {'a', 'e', 'i', 'o', 'u'};

	for(int i = 1; i<argc; ++i){


		char * str = argv[i];
		char temp = str[0];

		for(int i = 0; i<5; ++i){
			if(str[0] == vowels[i]){
				break;
			}else if(i == 4){
				//here: it means that the first letter is not a vowel
				str = shift(str);
				/* we just shifted but we don't know 
					if the first letter is a vowel, so restart
				*/
				i = 0;
			}
		}


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