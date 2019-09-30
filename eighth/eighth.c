#include <stdlib.h>
#include <stdio.h>

struct treenode* allocate_treenode(int );
void print_tree(struct treenode*);

struct treenode
{
	int value;
	struct treenode* right;
	struct treenode* left;
	
};

void insert(int value){
	struct treenode* temp = allocate_treenode(value);

	//struct treenode* ptr = root;
	while(ptr != null){
		
	}

	/*running binary search*/

}

struct treenode* allocate_treenode(int value){

	struct treenode* temp = malloc(sizeof(struct treenode));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}


int main(int argc, char** argv){

	struct treenode* root = NULL;
	
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
		printf("%c\t%d\n",c,num);
		if(root == NULL){
			root = allocate_treenode(num);
		}


	}
	fclose(fp);

	printf("this is the value of the root: %d\n", root->value);


}

void print_tree(struct treenode* root){
  if(root == NULL) return;
  printf(" value: %d\n", root->value);
  print_tree(root->left);
  print_tree(root->right);
}