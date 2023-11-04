/*  My Binary Tree Implementation  */

#include "binaryTree.h"
#include <assert.h>

struct s_btree {
    int val;
    MyTree* left;
    MyTree* right;
};

/*  CREATE A NEW TREE OBJECT  */
MyTree* newTree(void){
    MyTree* t = malloc(sizeof(*t));
    t->val = -1;
    t->left = t;
    t->right = t;
    return t;
}

/*  RETURNS THE AMOUNT OF NODES IN THE TREE  */
int treeSize(MyTree* tree){
    return isEmpty(tree) ? 0 : 1+treeSize(tree->left)+treeSize(tree->right);
}

/*  ADD NODE TO THE TREE  */
void addNode(MyTree* tree, int elem){
    assert(tree);    
    if (isEmpty(tree)){
        tree->val = elem;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if (tree->left && !tree->right){
            tree->right = newTree();
            addNode(tree->right, elem);
        } else if (!tree->left && tree->right){
            tree->left = newTree();
            addNode(tree->left, elem);
        } else {
            if (treeSize(tree->left) < treeSize(tree->right))
                addNode(tree->left, elem);
            else
                addNode(tree->right, elem);
        }
    }
}

/*  REMOVE ELEM FROM THE TREE  */
void remove(MyTree* tree, int elem){}

/*  CHECK IF ELEM EXISTS IN TREE  */
bool exists(MyTree* tree, int elem){
    return isEmpty(tree) ? false : (tree->val == elem) || exists(tree->left, elem) || exists(tree->right, elem);
}

/*  DETERMINES IF TREE IS EMPTY  */
bool isEmpty(MyTree* tree){
    return tree == NULL || (tree->left == tree->right);
}

/*  ORDER FUNCTIONS
 *  Returned array must be freed by caller.
 */
int* preOrderTraversal(MyTree* tree){}

int* postOrderTraversal(MyTree* tree){}

int* inOrderTraversal(MyTree* tree){}

/*  FREE ALL SPACE USED BY TREE  */
void freeTree(MyTree* tree){
    if (!tree)
        return;
    if (isEmpty(tree)){
        free(tree->right);
        free(tree->left);
        free(tree);
        return;
    }
    MyTree* killme = tree;
    freeTree(tree->left);
    freeTree(tree->right);
    free(killme);
}

/*  PRINT TREE  */
void printTree(MyTree* tree, order_t type){}