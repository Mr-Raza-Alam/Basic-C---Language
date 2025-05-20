#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
  struct bTree{
  int value;
  struct bTree* left;
  struct bTree* right;

};

struct bTree * r ,*temp;

struct bTree* create(struct bTree* r, int data);
struct bTree* deleteNode(struct bTree* root,int key);
struct bTree* inOderSuccessor(struct bTree*root);
void preOder(struct bTree* root);// depth order traversal
void inOder(struct bTree* root);
void postOder(struct bTree* root);
bool searchKey(struct bTree* root,int key);
struct bTree* insertion(struct bTree* root,int data);

int main(){
  r = NULL;
  int nums[] = {4,5,3,11,1,8,9};
  int max = sizeof(nums)/sizeof(nums[0]),key;
  printf("The length of nums's array = %d\n",max);
  printf("Enter the target element to search in the tree = ");
  scanf("%d",&key);
  for(int i =0; i<max; i++){
     r = create(r,nums[i]);
  }

  if(searchKey(r,key)){
   printf("%d is avialable in the tree\n",key);
  }else{
   printf("%d is unavialable in the tree\n",key);
  }

 printf("The preOrder values are:-\n");
    preOder(r);
    printf("\n");
 printf("The inOrder values are:-\n");
   inOder(r);
    printf("\n");
 printf("The postOrder values are:-\n");
   postOder(r);
    printf("\n");
  insertion(r,key);
  printf("After inserting %d,the inOrder traversal's value  are:-\n",key);
   inOder(r);
    printf("\n");
 r = deleteNode(r,8);
  printf("After deleting the key value(%d),new updated inOrder values are:-\n",key);
   inOder(r);
    printf("\n");
  return 0;
}
 
 struct bTree* insertion(struct bTree* root,int data){//O(H)
    if(root == NULL){
      temp = (struct bTree*) malloc(sizeof(struct bTree));
      temp->value = data;
      temp->left =  NULL;
      temp->right =  NULL;
     return temp;
    } 
   else if(root->value > data){
      root->left = insertion(root->left,data);
    }else{
      root->right = insertion(root->right,data);
    }
    return root;
 }

bool searchKey(struct bTree* root,int key){
   if(root == NULL){
      return false;
   }
   if(root->value == key){
      return true;
   } else if(root->value > key){// find in left-sub-tree
        searchKey(root->left,key);
   } else{
       searchKey(root->right,key);
    }
    return false;
}

struct bTree* create(struct bTree* root,int data){
   if(root == NULL){
     temp = (struct bTree*) malloc(sizeof(struct bTree));
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
   }
   else if(data > root->value){
        root->right = create(root->right,data);
           return root;
      }
    else{
        root->left = create(root->left,data);
       return root;
    }
  }
    
void preOder(struct bTree* root){//DLR-->Data left-traversal then right-traversal
   if(root !=NULL){ 
   printf("%d ",root->value);
   preOder(root->left);
   preOder(root->right);
   }
}
void inOder(struct bTree* root){//LDR-->left-traversal and print data and  then right-traversal
   if(root !=NULL){
   inOder(root->left);
   printf("%d ",root->value);
   inOder(root->right);
   }
}

void postOder(struct bTree* root){//LRD-->left-traversal and right-traversal and then print the data
   if(root != NULL){
   postOder(root->left);
   postOder(root->right);
   printf("%d ",root->value);
   }
}
struct bTree* deleteNode(struct bTree* root,int key){
   if(root == NULL){
      return NULL;
   }
 else if(root->value > key){
    root->left = deleteNode(root->left,key);
 } 
 else if(root->value < key){
    root->right = deleteNode(root->right,key);
 } 
 else{// deletion of key is found;
   // case-1 ---> having no child;
   if(root->left == NULL && root->right==NULL){
      return NULL;
   }
   // case-2 ----> having one child;
  else if(root->left== NULL){
     return root->right;
  }
  else if(root->right== NULL){
     return root->left;
  }
  // case-3 ---> having two childs;
  struct bTree* ID = inOderSuccessor(root->right);// inorder successor found
  root->value = ID->value;
   root->right = deleteNode(root->right,ID->value);
 }
 return root;
}

struct bTree* inOderSuccessor(struct bTree*root){
      while(root->left!=NULL){
         root = root->left;
      }
      return root;
}