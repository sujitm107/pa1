#include <stdlib.h>
#include <stdio.h>

struct treenode* allocate_treenode(int );
void print_tree(struct treenode*);
struct treenode* search(struct treenode*, int);
int insert(int value);
void free_tree(struct treenode*);

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

	while(ptr != NULL){
		/*running binary search*/
		temp->height = temp->height + 1;
		if(ptr->value == value){
			//printf("duplicate");
			free(temp);
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
		return temp->height;
	}
	if(value < prev->value){
		prev->left = temp;
		return temp->height;
	} else {
		prev->right = temp;
		return temp->height;
	}

}

struct treenode* search(struct treenode* root, int value){
	if(root == NULL){
		// if we cannot find the value
		return NULL;
	}

	if(value == root->value){
		//printf("this is the node's height: %d\n", root->height);
		return root;
	}

	if(value<root->value){
		return search(root->left, value);
	} else{
		return search(root->right, value);
	}

}

void free_tree(struct treenode* root){

	if(root == NULL){
		return;
	}

	free_tree(root->left);
	free_tree(root->right);
	free(root);

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
			int height = insert(num);
			if(height > 0){
				printf("inserted %d\n", height);
			} else{
				printf("duplicate\n");
			}
		}
		if(c == 's'){
			struct treenode* searchedElement = search(root, num);
			if( searchedElement != NULL){
				printf("present %d\n", searchedElement->height);
			} else{
				printf("absent\n");
			}
		}


	}
	fclose(fp);

	free_tree(root);

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
	temp->height = 1;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}