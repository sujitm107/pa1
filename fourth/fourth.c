#include<stdlib.h>
#include<stdio.h>

/*Can only multiply: the number of cols in the first matrix must equal 
the number of rows inthe second matrix

	Answer Matrix: the number rows of the first 
	matrix by the number of cols in the second matrix

*/



int main(int argc, char** argv){
	if(argc != 2){
		printf("insufficient arguments\n");
		exit(0);
	}

	//r means read
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("error\n");
		exit(0);
	}

	int rows = 0;
	int cols = 0;
	int num = 0;

	if(fscanf(fp, "%d\t%d\n", &rows, &cols) > 0){
		printf("%d ", rows);
		printf("%d\n", cols);
	}

	//creating space for the array
	int* arr[rows];
	for(int i = 0; i<rows; i++){
		arr[i] = malloc(cols * sizeof(int));
	}

	for(int r = 0; r<rows; r++){
		for(int c = 0; c<cols; c++){
			if(fscanf(fp, "%d", &num) > 0){
				arr[r][c] = num;
			}
		}
	}

	printf("%d--> value from array\n", arr[1][2]);


	return 0;
}