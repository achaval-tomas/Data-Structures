/*  My Binary Tree Implementation  */

#include "binaryTree.h"
#include <assert.h>
#include <string.h>
#include <math.h>

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
        if ((!tree->left && tree->right) || (tree->left == tree->right)){
            tree->left = newTree();
            addNode(tree->left, elem);
        } else if (tree->left && !tree->right){
            tree->right = newTree();
            addNode(tree->right, elem);
        } else {
            if (treeSize(tree->left) <= treeSize(tree->right))
                addNode(tree->left, elem);
            else
                addNode(tree->right, elem);
        }
    }
}

/*  REMOVE ALL INSTANCES OF ELEM FROM THE TREE  */
// To-Do IMPROVE THIS FUNCTION
void removeNode(MyTree* tree, int elem){
    MyTree* node = tree;
    while (isNode(tree, elem)){
        node = tree;
        if (treeSize(node) == 1){
            // TAKE TREE TO UNINITIALIZED STEP
            node->val = -1;
            node->left = node;
            node->right = node;  
        
        } else {
            MyTree* searcher = node;
            MyTree* helper = node;
            bool side = 0;
            while (node->val != elem) {
                side = isNode(node->left, elem);
                helper = node;
                node = side ? node->left : node->right;
            }

            searcher = node;
            while (searcher->left || searcher->right){
                side = treeSize(searcher->left) >= treeSize(searcher->right);
                helper = searcher;
                searcher = side ? searcher->left : searcher->right;
            }

            if (searcher != node)
                node->val = searcher->val;
                
            if (side) {
                free(helper->left);
                helper->left = NULL;
            } else {
                free(helper->right);
                helper->right = NULL;
            }

        }
    }
}

/*  CHECK IF ELEM EXISTS IN TREE  */
bool isNode(MyTree* tree, int elem){
    return isEmpty(tree) ? false : (tree->val == elem) || isNode(tree->left, elem) || isNode(tree->right, elem);
}

/*  DETERMINES IF TREE IS EMPTY  */
bool isEmpty(MyTree* tree){
    return tree == NULL || (tree->left && (tree->left == tree->right));
}

/*  HELPER FOR ORDER FUNCTIONS  */
int* helper(MyTree* root, int *arr, int *i, order_t order){
    if (root == NULL)
        return NULL;
    switch (order){
        case PREORDER:
            arr[(*i)++] = root->val;
            helper(root->left, arr, i, order);
            helper(root->right, arr, i, order);
            break;
        case INORDER:
            helper(root->left, arr, i, order);
            arr[(*i)++] = root->val;
            helper(root->right, arr, i, order);
            break;
        case POSTORDER:
            helper(root->left, arr, i, order);
            helper(root->right, arr, i, order);
            arr[(*i)++] = root->val;
            break;
        default:
            return NULL;
    }
    return arr;
}

/*  ORDER TRAVERSALS
 *  Returned array must be freed by caller.
 *  PREORDER = 0, INORDER = 1, POSTORDER = 2
 */
int* orderTraversal(MyTree* tree, order_t order){
    int treeLen = treeSize(tree);
    if (treeLen == 0)
        return NULL;
    int *ret = malloc(treeLen*sizeof(*ret));
    int i = 0;
    ret = helper(tree, ret, &i, order);
    return ret;
}

/*  FREE ALL SPACE USED BY TREE  */
void freeTree(MyTree* tree){
    if (!tree)
        return;
    if (isEmpty(tree)){
        free(tree);
        return;
    }
    MyTree* killme = tree;
    freeTree(tree->left);
    freeTree(tree->right);
    free(killme);
}

/*  PRINT TREE  */
void printTree(MyTree* tree, order_t order){
    int *a = orderTraversal(tree, order);
    int size = treeSize(tree);

    fprintf(stdout, "[ ");
    for (int i = 0; i<size; ++i)
        fprintf(stdout, "%d ", a[i]);
    fprintf(stdout, "]\n");
    fflush(stdout);

    free(a);
}

char* treeToStr(MyTree* tree, unsigned int depth, unsigned int* length_ptr) {
    if (tree == NULL || isEmpty(tree))
        return calloc(1, sizeof(char));

    unsigned int right_length;
    char* str_right = treeToStr(tree->right, depth + 1, &right_length);

    // calculate how many characters long is val
    int n_digits = ceil(log10(tree->val));
    
    // make room for "depths" spaces, "n_digits" for val, 1 for \n 
    unsigned int middle_length = depth + n_digits + 1;
    char* str_middle = malloc((middle_length + 1) * sizeof(char));

    for (unsigned int i = 0; i < depth; ++i)
        str_middle[i] = ' ';

    sprintf(str_middle + depth, "%d\n", tree->val);

    unsigned int left_length;
    char* str_left = treeToStr(tree->left, depth + 1, &left_length);

    *length_ptr = right_length + middle_length + left_length;
    char* str_res = malloc((*length_ptr + 1) * sizeof(char));

    strcpy(str_res, str_right);
    strcat(str_res, str_middle);
    strcat(str_res, str_left);

    free(str_right);
    free(str_left);
    free(str_middle);

    return str_res;
}

/*  PRINT TREE BUT PRETTY   */
void visualizeTree(MyTree* tree, unsigned int depth, char line) {
    unsigned int l;
    char* tree_str = treeToStr(tree, 0, &l);

    printf("%s", tree_str);

    free(tree_str);
}
