#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
    struct node*left;
    int data;
    struct node*right;
}node;
node* temp,*run,*leaf;
int*root;

void create();
void display();

int main(){
    int n;
    cout<<("Press:1 --> To create a binary-tree");
    cout<<("Press:2 --> To display the binary-tree's value");
    cout<<("Press:3 --> To exist");
     while(n!=3){
        cout<<"Enter the choic of action = ";
        cin>>n;
        if(n==1){
            create();
        }
        else if(n==2){
            display();
        }
        else{
            cout<<"Exist";
        }
     }
    return 0;
}

void create(){//paused mode for sometimes
     temp = (struct node*)malloc(sizeof(node));
     temp->data =8;
     temp->left = NULL;
     tepm->right = NULL;
     run = temp;
     root = temp
    temp = (struct node*)malloc(sizeof(node));
     temp->data =5;
     temp->left = NULL;
     tepm->right = NULL;
     leaf = temp;
     run->left = temp;
    temp = (struct node*)malloc(sizeof(node));
     temp->data =9;
     temp->left = NULL;
     tepm->right = NULL;
     run->right = temp;
}