/*  My Binary Tree Implementation  */

#include "binaryTree.h"

struct s_btree {
    int val;
    MyTree* left;
    MyTree* right;
};

/*  CREATE A NEW TREE OBJECT  */
MyTree* newTree(void){}

/*  RETURNS THE AMOUNT OF NODES IN THE TREE  */
int treeSize(MyTree* tree){}

/*  ADD NODE TO THE TREE  */
void addNode(MyTree* tree){}

/*  REMOVE ELEM FROM THE TREE  */
void remove(MyTree* tree, int elem){}

/*  CHECK IF ELEM EXISTS IN TREE  */
bool exists(MyTree* tree, int elem){}

/*  ORDER FUNCTIONS
 *  Returned array must be freed by caller.
 */
int* preOrderTraversal(MyTree* tree){}

int* postOrderTraversal(MyTree* tree){}

int* inOrderTraversal(MyTree* tree){}

/*  FREE ALL SPACE USED BY TREE  */
void freeTree(MyTree* tree){}

/*  PRINT TREE  */
void printTree(MyTree* tree, order_t type){}