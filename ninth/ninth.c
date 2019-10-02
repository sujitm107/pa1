#include <stdlib.h>
#include <stdio.h>

struct treenode* allocate_treenode(int );
void print_tree(struct treenode*);
int search(struct treenode*, int, int);
int insert(int );
int delete(int);
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

int search(struct treenode* root, int value, int height){
	if(root == NULL){
		// if we cannot find the value
		return -1;
	}
	if(value == root->value){
		//printf("this is the node's height: %d\n", root->height);
		return height;
	}
	if(value<root->value){
		return search(root->left, value, height+1);
	} else{
		return search(root->right, value, height+1);
	}

}

int delete(int value){

	//getting element, if it exists
	int deleteElement = search(root, value, 1);

	//if element does not exist
	if(deleteElement < 0){
		return -1;
	}
	struct treenode* ptr = root;
	struct treenode* parent = NULL;



	while(ptr != NULL){ 
	/*should never really go to null because we already checked
		if the element exists */
		if(value == ptr->value){ //we found the element so we can stop looping
			//printf("entering here\n");
			break;
		}
		parent = ptr;
		//storing parent, will not have parent if value is the root

		if(value < ptr->value){
			ptr = ptr->left;
		} else {
			ptr = ptr->right;
		}
	}

	//printf("value of pointer:---------------> %d\n", ptr->value);
	//printf("value of deleteElement: %d\n", deleteElement->value);

	struct treenode* temp = ptr;
	//temp is set to element that is set to be deleted

	//printf("Value of parent: %d\n", parent->value);

//CASE 3
	if(ptr->left != NULL && ptr->right != NULL){
		//TWO CHILDREN
		parent = ptr;
		ptr = ptr->right;

		while(ptr->left != NULL){
			parent = ptr;
			ptr = ptr->left;
		}
		temp->value = ptr->value;
		temp = ptr;
		//printf("value we are using to override: %d\n", ptr->value);
	}

	//CASE 2
	if(parent == NULL){

		//printf("should be entering\n");
		if(ptr->left != NULL){
			root = ptr->left;
			return 0;
		} else {
			root = ptr->right;;
			return 0;
		}
	}

	//CASE 2 only one child
	if(parent->left == ptr){
		if(ptr->left != NULL){
			parent->left = ptr->left;
		} else{
			parent->left = ptr->right;
		}
	} else { //parent->right == ptr
		if(ptr->left != NULL){
			parent->right = ptr->left;
		} else {
			parent->right = ptr->right;
		}
	}

	//printf("Sending back");

	if(search(root, value, 1) < 0){
		return 0;
	} else{
		return -1;
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
		if(c == 'i'){
			int height = insert(num);
			if(height > 0){
				printf("inserted %d\n", height);
				//printf("This is the root: %d\n", root->value);
			} else{
				printf("duplicate\n");
			}
		}
		if(c == 's'){
			int searchedElementHeight = search(root, num, 1);
			if( searchedElementHeight > 0){
				printf("present %d\n", searchedElementHeight);
			} else{
				printf("absent\n");
			}
		}
		if(c == 'd'){
			if(delete(num) == 0){
				printf("success\n");
			} else {
				printf("fail\n");
			}
		}

	}
	fclose(fp);

	//print_tree(root);

	// if(root != NULL){
	// 	printf("%d\n", root->value);
	// }

	free_tree(root);

	//printf("breaking in free tree\n");

}

//In PREORDER TRAVERSAL, so it should go lowest to highest
void print_tree(struct treenode* root){
  if(root == NULL) return;
  print_tree(root->left);
  printf(" value: %d\n", root->value);
  print_tree(root->right);
}

//USING POST-ORDER TRAVERSAL
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