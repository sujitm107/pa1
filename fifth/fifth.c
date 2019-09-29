#include<stdlib.h>
#include<stdio.h>

void printArray(int** arr, int size);

int isMagic(int**, int, int);

int isMagic(int** arr, int size, int magicNum){

	for(int i = 0; i<size; i++){
		int rowSum = 0;
		int colSum = 0;

		for(int j = 0; j<size; j++){
			rowSum = rowSum + arr[i][j];
			colSum = colSum + arr[j][i];
		}
		if(rowSum != magicNum || colSum != magicNum){
			return -1;
		}
	}

	//computing sums for diagonals; diaglr top left to bottom right, diagrl top right to bottom left
	int diaglr = 0;
	int diagrl = 0;
	for(int i = 0; i<size; i++){
		diaglr = diaglr + arr[i][i];
		diagrl = diagrl + arr[0+i][size-(i+1)];
	}

	if(diaglr != magicNum || diagrl != magicNum){
		return -1;
	}



	return 0;
}

int main(int argc, char** argv){

	if(argc != 2){
		printf("insufficient arguments\n");
		exit(0);
	}

	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("error\n");
		exit(0);
	}


	int size = 0;
	if(fscanf(fp, "%d", &size) > 0){
		//printf("%d\n", size);
	}

	int* present = malloc((size*size)*sizeof(int));


	int magicNum = 0;
	for(int i = 0; i<(size*size); ++i){
	/*populating present array with -1
		PLAN: as we fill in the read the file, we will occupy this
		array with 0s to check if every value is present
	*/
		present[i] = -1;

		magicNum = magicNum + (i+1);
	}

	magicNum = magicNum/size;

	//printf("%d\n", magicNum);

	int** arr = malloc(size * sizeof(int*));
	for(int i = 0; i<size; i++){
		arr[i] = malloc(size * sizeof(int));
	}


	int num = 0;
	for(int r = 0; r<size; r++){
		for(int c = 0; c<size; c++){
			if(fscanf(fp, "%d", &num) > 0){
				arr[r][c] = num;
				//printf("failing\n");
				//num-1 bc an array that stores 9 has highest index of 8
				if(num <= (size*size)){
					if(present[num-1] == 0){
						//printf("not-magic\n");
						magicNum = -1;
						r = size;
						break;
					}else{
						present[num-1] = 0;
					}
				} else{
					magicNum = -1;
					r = size;
					break;
				}
			}
		}
	}

	/*
		if magicNum is -1 it means we had a duplicate or a number>size
	*/


	if(magicNum != -1){
		if(isMagic(arr, size, magicNum) == 0){
			printf("magic\n");
		} 
		else{
			printf("not-magic\n");
		}
	} else{
		printf("not-magic\n");
	}

	//printArray(arr, size);


}

void printArray(int** arr, int size){
	for(int i = 0; i<size; ++i){
		for(int j = 0; j<size; ++j){
			if(j != size-1){
				printf("%d\t", arr[i][j]);
			} else{
				printf("%d\n", arr[i][j]);
			}
		}
	}
}