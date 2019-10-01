#include<stdlib.h>
#include<stdio.h>
#include<string.h>


/*

Hello and welcome to Computer Architecture
elloHay andyay elcomeway otay omputerCay Architectureyay
This is just a test to make sure your program is running correctly
isThay isyay ustjay ayay esttay otay akemay uresay ouryay ogrampray isyay unningray orrectlycay
a
ayay
bye
ebyay

*/

char* shift(char*);

char* shift(char* str){

	char temp = str[0];

	for(int j = 1; j<strlen(str); ++j){
		str[j-1] = str[j];
	}
	str[strlen(str)-1] = temp;

	//printf("%s ---> right before sending back\n", str);

	return str;

}

int main(int argc, char** argv){

	char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	for(int i = 1; i<argc; ++i){


		char * str = argv[i];
		char temp = str[0];
		int count = 0;

		for(int i = 0; i<10; ++i){
			if(count == strlen(str)){
				break; //will break if we fully traverse a word, this means there are no vowels
			}
			if(str[0] == vowels[i]){
				break;
			}else if(i == 9){
				//here: it means that the first letter is not a vowel
				str = shift(str);
				count = count + 1;
				/* we just shifted but we don't know 
					if the first letter is a vowel, so restart
				*/

				i = -1;
			}
		}


		printf("%s", str);

		for(int i = 0; i<10; ++i){
			if(temp == vowels[i]){
				printf("yay");
				if(i != (argc-1)){
					printf(" ");
				}
				break;
			} else if (i == 9){
				printf("ay");
				if(i != (argc-1)){
					printf(" ");
				}
			}
		}

	}

	printf("\n");


}