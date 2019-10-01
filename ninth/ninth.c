#include <stdlib.h>
#include <stdio.h>

struct treenode* allocate_treenode(int );
void print_tree(struct treenode*);
int search(struct treenode*, int, int);
int insert(int value);
int delete(int value);

struct treenode* root = NULL;

struct treenode
{
	int value;
	int height;
	struct treenode* right;
	struct treenode* left;
	
};

int insert(int value){
	struct treenode* temp = allocate_treenode(value);

	struct treenode* prev = NULL;
	struct treenode* ptr = root;
	int height = 1;

	while(ptr != NULL){
		/*running binary search*/
		height = height + 1;
		if(ptr->value == value){
			//printf("duplicate");
			return -1;
		}
		prev = ptr;
		if(value < ptr->value){
			ptr = ptr->left;
		}else{
			ptr = ptr->right;
		}
	}

	if(prev == NULL){
		root = temp;
		return height;
	}
	if(value < prev->value){
		prev->left = temp;
		return height;
	} else {
		prev->right = temp;
		return height;
	}

}

int search(struct treenode* root, int value, int height){
	if(root == NULL){
		return -1;
	}
	if(value == root->value){
		return height;
	}
	if(value<root->value){
		return search(root->left, value, height+1);
	} else{
		return search(root->right, value, height+1);
	}

}

int delete(int value){

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
//READING FILE TO COMPLETION
	while(fscanf(fp, "%c\t%d\n", &c, &num) > 0){
		if(c == 'i'){
			int height = insert(num);
			if(height > 0){
				printf("inserted %d\n", height);
			} else{
				printf("duplicate\n");
			}
		}
		if(c == 's'){
			int height = search(root, num, 1);
			if( height > 0){
				printf("present %d\n", height);
			} else{
				printf("absent\n");
			}
		}

		if(c == 'd'){

		}


	}
	fclose(fp);

	free_tree(root);

}

//In PREORDER TRAVERSAL, so it should go lowest to highest
void print_tree(struct treenode* root){
  if(root == NULL) return;
  print_tree(root->left);
  printf(" value: %d\n", root->value);
  print_tree(root->right);
}

void free_tree(struct treenode* root){

	if(root == NULL){
		return;
	}

	free_tree(root->left);
	free_tree(root->right);
	free(root);

}

struct treenode* allocate_treenode(int value){

	struct treenode* temp = malloc(sizeof(struct treenode));
	temp->value = value;
	temp->height = 1;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}