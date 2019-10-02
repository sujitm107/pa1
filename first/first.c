#include<stdlib.h>
#include<stdio.h>


int isRightPrime(int n);

int isPrime(int n){

	if(n == 0 || n == 1){
		return -1;
	}

	//printf("sending %d\n",n);
	int temp = n;
	while(temp > 0){
		for(int i = 2; i<temp;i++){
			if(temp%i == 0){
				//returns -1 if not prime
				return -1;
			}
		}
		temp = temp/10;
	}
	
	return 0;
}

int main(int argc, char** argv){

//	if(argc < 2){
//		printf("insufficient argumnets\n");
//		exit(0);
//	}
//	
//	printf("the provided command line arguments are:\n");

//	for(int i = 0; i<argc; i++){
//		printf("%s\n", argv[i]);
//	}

//	int k = atoi(argv[1]);
//	printf("The entered number was %d\n", k);


	if(argc !=2){
		printf("insufficient arugments\n");
		exit(0);
	}
	//printf("Entered file name is %s\n", argv[1]);

	//opening file
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("file does not exist\n");
		exit(0);
	}

	
	int num = 0;
	/*Now read the first line in the file */
	if (fscanf(fp, "%d\n", &num) == EOF){
		printf("empty file\n");
		exit(0);
	}
	//printf(" the total number of values are %d\n", num);
	

	for(int i = 0; i< num; i++){
		int temp;
		//v what is that line doing
		fscanf(fp, "%d\n", &temp);

		//printf("Receiving %d\n", isPrime(temp));

		if(isPrime(temp) == 0){
			printf("yes\n");
		} else{
			printf("no\n");
		}
	}

	fclose(fp);	
	
	return 0;

}