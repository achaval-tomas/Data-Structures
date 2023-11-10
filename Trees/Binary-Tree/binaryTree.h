/*  My Binary Tree Specification  */

#ifndef BINARY_TREE_HEADER
#define BINARY_TREE_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_btree MyTree;

/*  ENUM FOR TREE ORDER TRAVERSALS  */
typedef enum {
    PREORDER = 0,
    INORDER = 1,
    POSTORDER = 2
} order_t;

/*  CREATE A NEW TREE OBJECT  */
MyTree* newTree(void);

/*  RETURNS THE AMOUNT OF NODES IN THE TREE  */
int treeSize(MyTree* tree);

/*  ADD NODE TO THE TREE  */
void addNode(MyTree* tree, int elem);

/*  REMOVE ALL INSTANCES OF ELEM FROM THE TREE  */
void removeNode(MyTree* tree, int elem);

/*  CHECK IF ELEM EXISTS IN TREE  */
bool isNode(MyTree* tree, int elem);

/*  DETERMINES IF TREE IS EMPTY  */
bool isEmpty(MyTree* tree);

/*  ORDER FUNCTIONS
 *  Returned array must be freed by caller.
 */
int* orderTraversal(MyTree* tree, order_t order);

/*  FREE ALL SPACE USED BY TREE  */
void freeTree(MyTree* tree);

/*  PRINT TREE  */
void printTree(MyTree* tree, order_t order);

void visualizeTree(MyTree* tree, unsigned int depth);

#endif /* BINARY_TREE_HEADER */
