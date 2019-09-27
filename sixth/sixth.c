#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char** argv){

	 //char vowels[] = {'a', 'e', 'i', 'o', 'u'};

	// for(int i = 0; i<argc; ++i){
	// 	printf("%lu ", strlen(argv[i]));
	// 	printf("%s\n", argv[i]);
	// }

	// for(int i = 0; i<5; ++i){
	// 	printf("%c\t", vowels[i]);
	// }

	// printf("\n");

	
	for(int i = 1; i<argc; ++i){
		char* x = malloc(1*sizeof(char));
		x = argv[i];

		//printf("%s----> current string\n", x);

		int swv = -1;

		// for(int i = 0; i<strlen(x); ++i){
		// 	if(x[0] == vowels[i]){
		// 		swv = 0;
		// 		break;
		// 	}
		// }

		printf("%d", swv);

		// if(swv == 0){
		// 	strcat(x, "yay");
		// } else{
		strcat(x, "ay");

		printf("%s\n", x);
	}

	printf("\n");



}