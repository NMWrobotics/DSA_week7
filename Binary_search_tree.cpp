#include <iostream>
using namespace std;

struct node {

  int key;
  struct node *left, *right;

};

//function to find the minimum of a tree
//returns the address of the minimum value of a tree
struct node * findMin(struct node* node){

    struct node* currentMin = node;
 
    while (currentMin->left != NULL)
        currentMin = currentMin->left;
 
    return currentMin;
}

// Inorder traversal
void traverseInOrder(struct node *root) {

  if(root != NULL){
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);
  }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  //if there isn't a root node create one
  if (node == NULL){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key= key;
    temp -> left = temp->right = NULL;
    
    return temp;
  }
  
  //if the the key is less than or equals to the node
  //insert key to left side
  if(key <= node->key){
    node->left = insertNode(node->left,key);
  }

  //if the the key is greater than to the node
  //insert key to right side
  else if(key > node->key){
    node-> right = insertNode(node->right,key);
  }

  return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
 
  //base case
  if(root == NULL){
    return root;
  
  //if the value needs to be deleted is less than the key
  //the value is in the left side of the tree
  }if(key < root->key){
    root->left = deleteNode(root->left,key);

  //if the value needs to be deleted is greater than the key
  //the value is in the right side of the tree
  }else if (key > root->key){
    root->right = deleteNode(root->right,key);
  
  //else the value equals the key
  //then thats the node needs to be deleted
  }else{

    //if the node doesnt have child nodes
    if (root->left == NULL and root->right == NULL){
      free(root);
      
      return NULL;
    
    //if the node has only a right child
    }else if(root->left == NULL) {

      struct node *temp = root->right;
      free(root);
      
      return temp;

    //if the node has only a left child
    }else if(root->right == NULL) {

      struct node *temp = root->left;
      free(root);

      return temp;

  }
    
    //if the node has two childs
    //get the minimum node of the right sub tree
    //copy that node to the position of the deleting node
    else {

      struct node *temp = findMin(root->right);
    
      root->key = temp->key;
      root->right= deleteNode(root->right,root->key);
    }
  

  }

  return root;

}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
