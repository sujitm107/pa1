#include <stdlib.h>
#include <stdio.h>

struct treenode* allocate_treenode(int );
void print_tree(struct treenode*);
struct treenode* search(struct treenode*, int);
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

int delete(int value){

	struct treenode* deleteElement = search(root, value);
	if(deleteElement == NULL){
		return -1;
	}

	struct treenode* ptr = deleteElement;
	struct treenode* parent = NULL;

	if(deleteElement->left == NULL && deleteElement->right == NULL){
		//TWO CHILDREN
		parent = ptr;
		ptr = ptr->right;

		while(ptr->left != NULL){
			parent = ptr;
			ptr = ptr->left;
		}
		deleteElement->value = ptr->value;
		deleteElement = ptr;
	}
	//parent->left = NULL;

	if(parent == NULL){
		if(deleteElement->left != NULL){
			root = deleteElement->left;
		} else{
			root = deleteElement->right;
		}
	}

	if(deleteElement == parent->right){
		if(deleteElement->left != NULL){
			parent->right = deleteElement->left;
		} else{
			parent->right = deleteElement->right;
		}
	} else {
		if(deleteElement->left != NULL){
			parent->left = deleteElement->left;
		} else{
			parent->left = deleteElement->right;
		}

	}

	if(search(root, value) == NULL){
		return 0;
	} else{
		return -1;
	}

	/*
		T temp = x.data; // to be returned at end of method
		// Case 3
		if (x.left != null && x.right != null) {
			// find inorder predecessor of x
			BSTNode<T> y = x.left;  // left turn
			p = x;
			// right turns until dead end
			while (y.right != null) {
				p = y;
				y = y.right;
			}
			x.data = y.data;  // copy y into x
			x = y; // reset y to drop into case 1 or case 2
		}
		
		if (p == null) {
			root = x.left != null ? x.left : x.right; // case 1 and 2
			size--;
			return temp;
		}
		
		// works for case 2 (two combos) and case 2 (4 combos)
		if (x == p.right) {
			p.right = x.left != null ? x.left : x.right;
		} else {
			p.left = x.left != null ? x.left : x.right;
		}
		size--;
		return temp;

	*/

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
			struct treenode* searchedElement = search(root, num);
			if( searchedElement != NULL){
				printf("present %d\n", searchedElement->height);
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

	print_tree(root);

	free_tree(root);

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