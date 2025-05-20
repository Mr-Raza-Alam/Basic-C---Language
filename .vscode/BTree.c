#include<stdio.h>
#include<stdlib.h>
struct tNode{
    int data;
    struct tNode *left, *right;
};

struct tNode*insert(struct tNode*p,int val){
    struct tNode*temp1,*temp2;
    if(p == NULL){
        p = (struct tNode*)malloc(sizeof(struct tNode));
        if(p == NULL){
            printf("Cannot allocate\n");
            exit(0);
        }
        p->data = val;
        p->left = p->right = NULL;
    } else{
        temp1 = p;
        while(temp1!=NULL){
            temp2 = temp1;
            if(temp1->data > val){
                temp1 = temp1->left;
            } else{
                temp1 = temp1->right;
            }
        }
        if(temp2->data >val){
            temp2->left = (struct tNode*)malloc(sizeof(struct tNode));
            temp2 = temp2->left;
            if(temp2 == NULL){
                printf("Cannot allocate\n");
                exit(0);
            }
         temp2->data = val;
         temp2->left = temp2->right = NULL;
        } else{
            temp2->right = (struct tNode*)malloc(sizeof(struct tNode));
            temp2 = temp2->right;
            if(temp2==NULL){
              printf("Cannot allocate\n");
                exit(0);
            }
            temp2->data = val;
            temp2->left = temp2->right = NULL;
        }
    }
        return p;
}

void inorder(struct tNode*p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void inorder(struct tNode* p);
void preOder(struct tNode* root);
void postOder(struct tNode* root);
struct tNode*  insert(struct tNode* p,int val);
void main(){
    struct tNode* root = NULL;
    int n,x;
    printf("Enter the number of nodes requried = ");
    scanf("%d",&n);
    while(n>0){
        printf("Enter the i/p value = ");
        scanf("%d",&x);
        root = insert(root,x);
        n--;
    }
    printf("The inorder traversal of binary search tree\n");
    inorder(root);
    printf("\nThe pre-Order traversal of binary search tree\n");
    preOder(root);
    printf("\nThe post-Order traversal of binary search tree\n");
     postOder(root);
}
void preOder(struct tNode* root){//DLR-->Data left-traversal then right-traversal
   if(root !=NULL){ 
   printf("%d ",root->data);
   preOder(root->left);
   preOder(root->right);
   }
}

void postOder(struct tNode* root){//LRD-->left-traversal and right-traversal and then print the data
   if(root != NULL){
   postOder(root->left);
   postOder(root->right);
   printf("%d ",root->data);
   }
}