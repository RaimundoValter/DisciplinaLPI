#include "TAD_TreeGen.h"

#include <stdlib.h>
#include <stdio.h>

/*IS IT EMPTY?
    respondes this question: is this tree empty?

Params
    root: pointer to a root node of a tree.

Return
    True if the tree is empty, otherwise false.
*/
int tree_empty(Node* root);

/* CREATE AN ENPTY TREE
    Creates a empty tree.

Return
    (Node*)NULL, representing a empty tree.
*/
Node* tree_create_empty();

/*CREATE A NODE
    Creates a node with an info and left and right sub-tree.

Params
    info: pointer to a information.
    lst: pointer to a node root of a left sub-tree.
    rst: pointer to a node root of a right sub-tree.

Return
    pointer to a new node (Node*).
*/
Node* tree_create_node(void* info, Node* lst, Node* rst);

/*INSERT A NODE
    Inserts a node in a tree based on a comparison.
    If it's true, the new_node will be placed in the left sub-tree, 
    if it's false, the new_node will be in the right sub-tree.

Params
    root: pointer to the root of the tree
    new_node: pointer to the new node
    compare: callback function that compares two elements

Return
    True if the new_node was placed in the tree,
    otherwise false.
*/
Node* tree_insert_node(Node* root, Node* new_node, int (compare)(void*, void*));

/*FREE A TREE
    free memory of all elements in a tree/subtree starting from the "root" node.

Params
    root: a node of a tree/subtree that you would like to free.
*/
void tree_free(Node* root);

/*PERFORM OPERATION IN A TREE 
    perform an operation in all elements of a tree. 
Params
    Node* root = receives the head of the tree 
    void (operation)(void*) = callback operation that will be applied to the intere tree
*/ 
void tree_map(Node* root, void (operation)(void*));

/*COPY A NODE 
    copy a node of a tree.
Params
    original_node: pointer to the original node.

Returns
    pointer to a copied node.
*/
Node* tree_copy_node(Node* original);


/*FILTER ELEMENTS IN THE TREE INTO A LIST
    Gather together a set of elements that satisfy condition inside the tree, creating a list of nodes.
 
 Params
    root: pointer to the root of the tree
    condition: callback function that returns true if the element satisfies the condition
    copy_node: callback function that returns a copy of the element
 
 Return
    Pointer to the head of a list composed by the elements
    that satisfy the condition.
*/
Listagen* tree_filter_as_list(Node* root, int (condition)(void*), void* (copy_info)(void*));

/*FILTER ELEMENTS IN THE TREE CREATING A NEW TREE
    Gather together a set of elements that satisfy condition inside the tree.
 
 Params
    root: pointer to the root of the tree
    condition: callback function that returns true if the element satisfies the condition
    copy_node: callback function that returns a copy of the element
    compare: callback function that compares two elements
 
 Return
    Pointer to the root of a tree composed by the elements
    that satisfy the condition.
*/
Node* tree_filter(Node* root, int (condition)(void*), void* (copy_info)(void*), int (compare)(void*, void*));

/*VERIFIES THE HEIGHT OF THE NODE
    Receives a node that calculates his height on the tree

 Params
    node: pointer to the root of the tree

 Return
    An integer for the height 
*/
int tree_get_height(Node* node);

/*ROTATES THE TREE TO THE RIGHT
    Executes a rotation to the right, to fix the imbalance
    when the left subtree is heavier

 Params
    root: pointer to the root of the tree

 Return
    A pointer (Node*) to the new root
*/
Node* rotate_right(Node* root);

/*ROTATES THE TREE TO THE LEFT
    Executes a rotation to the left, to fix the imbalance
    when the right subtree is heavier

 Params
    root: pointer to the root of the tree

 Return
    A pointer (Node*) to the new root
*/
Node* rotate_left(Node* root);

/*INSERTS A NEW NODE WHILE BALANCING THE TREE 
    Inserts a new node like a BST, but balancing the tree
    after each insertion to keep it balanced

 Params
    root: pointer to the root of the tree
    new_node: pointer to the new node
    compare: callback function that compares two elements

 Return
    A pointer (Node*) to the new root
*/
Node* tree_insert_balanced(Node* root, Node* new_node, int (compare)(void*, void*));

/*TREE SEARCH
   Search the first element that satisfies the condition inside the tree.

Parameters
   Node* root - receives the root of the tree.
   int (condition)(void) - a callback that receives the node info
   and returns a non-zero value if the condition is satisfied.

Return
   A pointer (Node*) to the first node that satisfies the condition.
*/
Node* tree_search(Node* root, int (condition)(void*));

/*WRITE IN ORDER
    Recursively writes the contents of a binary tree to a file using
     symmetric order.
 
Return
  (void) – does not return any value.
 
Parameters
  Node* new_node – current node to process.
  FILE* fp – file pointer to the opened text file where data will be written.
  char* (create_line)(void*) – function that receives the node's info and
  returns a dynamically allocated string to be written into the file.
*/
void write_inorder(Node *new_node, FILE *fp, char* (*create_line)(void*));

/*TREE TO FILE
    Save all elements from the tree to a text file using in-order traversal.

Parameters
    Node* root - receives the root of the tree.
    char* file_name - receives the name of the file to be created.
    char* (create_line)(void) - function that receives a node’s info,
    returns a formatted string to be saved in the file.
    This function must return a dynamically allocated string,
    which will be freed after being written.

Return
    (void) - does not return anything.
*/
void tree_to_file(Node* root, char* file_name, char* (create_line)(void*));

/*LOAD A BINARY TREE FROM A TEXT FILE 
    Reads a text file line by line, converts each line into data (using read_line),
    creates a node for each data item, and inserts it into the tree in order using the compare function.

Return
    A pointer to the root of the constructed tree (Node*)

Parameters
    file_name: name of the file to read
    read_line: function that converts a line (char*) into generic data (void*)
    compare: function used to order nodes upon insertion
*/
Node* tree_load_from_file(char* file_name, void* (read_line)(char*), int (compare)(void*, void*));