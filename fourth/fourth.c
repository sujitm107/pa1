#include<stdlib.h>
#include<stdio.h>

/*Can only multiply: the number of cols in the first matrix must equal 
the number of rows inthe second matrix

	Answer Matrix: the number rows of the first 
	matrix by the number of cols in the second matrix

*/
void printArray(int** arr, int rows, int cols);
int** allocate_array(int, int);
int** multiply(int**, int**, int, int, int, int);

int** allocate_array(int rows, int cols){
	int** arr = malloc(rows * sizeof(int*));
	for(int i = 0; i<rows; i++){
		arr[i] = malloc(cols * sizeof(int));
	}

	return arr;

}

int** multiply(int** aOne, int** aTwo, int colsOne, int rowsTwo, int colsTwo, int rowsOne){

	int** product = allocate_array(rowsOne, colsTwo);

	if(colsOne != rowsTwo){
		printf("bad-matrix\n");
		return NULL;
	}
	//if past here colsOne == rowsTwo, so you can use them interchangbly

	for(int i = 0; i<rowsOne; ++i){
		for(int j = 0; j<colsTwo; ++j){
			int sum = 0;
			for(int k = 0; k<colsOne; ++k){
				//printf("%d\n", aOne[i][j] * aTwo[j][i]);
				sum = sum + (aOne[i][k] * aTwo[k][j]);
			}
		//printf("%d\n", sum);
		product[i][j] = sum;
		}
	}

	return product;
}



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

	int rowsOne = 0;
	int colsOne = 0;
	int num = 0;

	if(fscanf(fp, "%d\t%d\n", &rowsOne, &colsOne) > 0){
		//printf("%d ", rowsOne);
		//printf("%d\n", colsOne);
	}

	//creating space for the array

	int** aOne;
	aOne = allocate_array(rowsOne, colsOne);
	for(int r = 0; r<rowsOne; r++){
		for(int c = 0; c<colsOne; c++){
			if(fscanf(fp, "%d", &num) > 0){
				aOne[r][c] = num;
			}
		}
	}

	//printArray(aOne, rowsOne, colsOne);

	int rowsTwo = 0;
	int colsTwo = 0;

	if(fscanf(fp, "%d\t%d\n", &rowsTwo, &colsTwo) > 0){
		//printf("%d ", rowsTwo);
		//printf("%d\n", colsTwo);
	}

	int** aTwo;
	aTwo = allocate_array(rowsTwo, colsTwo);
	for(int r = 0; r<rowsTwo; r++){
		for(int c = 0; c<colsTwo; c++){
			if(fscanf(fp, "%d", &num) > 0){
				aTwo[r][c] = num;
			}
		}
	}

	fclose(fp);

	//printArray(aTwo, rowsTwo, colsTwo);

	int** product;

	product = multiply(aOne, aTwo, colsOne, rowsTwo, colsTwo, rowsOne);

	printArray(product, rowsOne, colsTwo);

	return 0;
}


void printArray(int** arr, int rows, int cols){
	for(int i = 0; i<rows; ++i){
		for(int j = 0; j<cols; ++j){
			if(j != cols-1){
				printf("%d\t", arr[i][j]);
			} else{
				printf("%d\n", arr[i][j]);
			}
		}
	}
}