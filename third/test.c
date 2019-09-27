//third project

#include<stdlib.h>
#include<stdio.h>

int hashfunction(int);

struct node* arr[10];

//ListNode[] x = new 

struct node{
	int value;
	struct node* next;
};

int hashfunction(int value){

	return value%10;
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

	int num;
	char c;

	while(fscanf(fp, "%c\t%d\n", &c, &num) > 0){
		printf("Values: %c\t%d\t hashcode: %d\n", c, num, hashfunction(num));
		int hc = hashfunction(num);

		arr[hc]->next = struct node 
	}

	//int x = 14;

	//printf("%d\n", hashfunction(x));

	return 0;

}