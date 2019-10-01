#include <stdlib.h>
#include <stdio.h>

struct treenode* allocate_treenode(int );
void print_tree(struct treenode*);
int search(struct treenode*, int);
int insert(int value);

struct treenode* root = NULL;

struct treenode
{
	int value;
	struct treenode* right;
	struct treenode* left;
	
};

int insert(int value){
	struct treenode* temp = allocate_treenode(value);

	struct treenode* prev = NULL;
	struct treenode* ptr = root;

	while(ptr != NULL){
		/*running binary search*/

		if(ptr->value == value){
			printf("duplicate");
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
		return 0;
	}
	if(value < prev->value){
		prev->left = temp;
		return 0;
	} else {
		prev->right = temp;
		return 0;
	}

}

int search(struct treenode* root, int value){
	if(root == NULL){
		return -1;
	}

	if(value == root->value){
		return 0;
	}

	if(value<root->value){
		return search(root->left, value);
	} else{
		return search(root->right, value);
	}

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
		//printf("%c\t%d\n",c,num);
		if(c == 'i'){
			if(insert(num) == 0){
				printf("inserted %d\n", num);
			} else{
				printf("duplicate %d\n", num);
			}
		}
		if(c == 's'){
			if(search(root, num) == 0){
				printf("present %d\n", num);
			} else{
				printf("absent %d\n", num);
			}
		}


	}
	fclose(fp);

	//printf("this is the value of the root: %d\n", root->value);
	//print_tree(root);

}

//In PREORDER TRAVERSAL, so it should go lowest to highest
void print_tree(struct treenode* root){
  if(root == NULL) return;
  print_tree(root->left);
  printf(" value: %d\n", root->value);
  print_tree(root->right);
}

struct treenode* allocate_treenode(int value){

	struct treenode* temp = malloc(sizeof(struct treenode));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}