#include <stdlib.h>
#include <stdio.h>

struct treenode* allocate_treenode(int );
void print_tree(struct treenode*);

struct treenode
{
	int value;
	node* right;
	node* left;
	
};

struct

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

	}
	fclose(fp);


}

void print_tree(struct treenode* root){
  if(root == NULL) return;
  printf(" value: %d\n", root->value);
  print_tree(root->left);
  print_tree(root->right);
}