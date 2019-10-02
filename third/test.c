//third project
#include<stdlib.h>
#include<stdio.h>

int hashfunction(int);
void insert(int,int);
int search(int);

struct node* arr[1000];

struct node{
	int value;
	struct node* next;
};

int hashfunction(int value){
	int temp = value;

	if(value<0){
		temp = temp * -1;
	}

	return temp%1000;
}

//INSERT METHOD
void insert(int value, int hc){

	//checking if value already exists
	if(search(value) == 0){
		printf("duplicate\n");
		return;
	}
	//printf("value: %d\thashcode: %d\n", value, hc);

	struct node* temp = malloc(sizeof(struct node)); //making space for node
	temp->value = value;
	temp->next = NULL;

	if(arr[hc] == NULL){
		arr[hc] = temp;
		printf("inserted\n");
		return;
	}

	struct node* ptr = arr[hc];

	while(ptr->next != NULL){
		ptr = ptr->next;
	}

	ptr->next = temp;


	//printf("%d--->inserting into %d\n", arr[hc]->value, hc);

	printf("inserted\n");

}

int search(int value){
	int hc = hashfunction(value);

	struct node* ptr = arr[hc];

	//printf("%d--->searching for in this index %d\n", ptvalue, hc);

	while(ptr != NULL){
		//printf("search route: %d ", ptr->value);

		if(ptr->value == value){
			return 0;
		}
		ptr = ptr->next;
	}
	//printf("\n");
	return -1;
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
	int hc;

	while(fscanf(fp, "%c\t%d\n", &c, &num) > 0){
		// printf("Values: %c\t%d\t hashcode: %d\n", c, num, hashfunction(num));
		hc = hashfunction(num);
		if(c == 'i'){
			insert(num, hc);
		}
		if(c == 's'){
			if(search(num) == 0)
				printf("present\n");
			else{
				printf("absent\n");
			}
		}
	}

	fclose(fp);

	//int x = 14;

	//printf("%d\n", hashfunction(x));

	return 0;

}