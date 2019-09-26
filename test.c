#include<stdlib.h>
#include<stdio.h>

struct node{
	int value;
	struct node* next;
};

struct node* head = NULL;
void insert(int value);
void delete(int value);
void print_list();

void print_list(){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d --> ", temp->value);
		temp = temp->next;
	}	
	printf("\n");

}


void insert(int value){
	struct node* temp = malloc(sizeof(struct node)); //making space for a node
	temp->value = value;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
	} else{
		struct node* ptr = head;
		struct node* prev = NULL;
		while(ptr != NULL){
			if(ptr->value > temp->value){
				/*if we find a node that has 
					a greater value then break
				*/
				break;
			}
			//Just iterating
			prev = ptr;
			ptr = ptr->next;
		}
		if(prev == NULL){
			temp->next = ptr;
			head = temp;
		}else{
			prev->next = temp;
			temp->next = ptr;			
		}

	}

	//temp->next = head;
	//head = temp;

	/*
		IN JAVA
		private void insert(int value){

			
			Node n = new Node(5, null);
			Node ptr = head;
			while(ptr.next != null){
				ptr = ptr.next;
			}

			if (head == null){
				head = temp;
			}

			ptr.next = n;

		}

	*/
}

void delete(int value){
	struct node* ptr = head;
	struct node* prev = NULL;

	while(ptr != NULL){
		if(ptr->value == value){
			prev->next = ptr->next;
		}else{
			prev = ptr;
		}
		ptr = ptr->next;
	}
}

int main(int argc, char** argv){
	
	if(argc != 2){
		printf("insufficient arguments\n");
		exit(0);
	}
	
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("file does not exist\n");
		exit(0);
	}


	int num;
	char c;
	//int count = 0;
	while(fscanf(fp, "%c\t%d\n", &c, &num) > 0){
		//printf("Inserting: %d\n", num);
		printf("This is the read character: %c\n",c);
		if(c == 'i'){
			insert(num);
		}
		if(c == 'd'){
			delete(num);
		}
		//count = count + 1;
	}

	//printf("This is the number of items: %d\n", count);

	fclose(fp);
	
	print_list();

	return 0;
}
