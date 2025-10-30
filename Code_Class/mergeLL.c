#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{// user-define data-type that can store integer type data and also store address of next similar type node
    int data;
    struct Node* next;
};
struct Node* head,* run,* temp,*merge,*headM;
struct LinkeList{
    struct Node* l1;
    struct Node* l2;
    struct Node* resLL;
};

struct Node* create(struct Node* node,int k){
   int n;
   if(node == NULL){
   temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter data-%d = ",k);
     scanf("%d",&n);
    temp->data = n;
    temp->next = NULL;
    head = temp;
    return head;
   }
   printf("Enter data-%d = ",k);
   scanf("%d",&n);
   temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    node->next = temp;
    return temp;
}

void bubbleSort();
struct Node* create(struct Node* node,int k);
void merge2LL(struct Node* h1,struct Node* h2,struct Node* h);

void main(){
  head = NULL;
  run = head;
  struct LinkeList* l1;
  struct LinkeList* l2;
  int k = 1;
  printf("Create 1st linkedlist \n");
  for(int i = 1; i<=4; i++){
    run = create(run,k);
    k +=1;
  }
  printf("The values store in  linked-list-1 are :-\n");
  run = head;
  while(run != NULL){
    printf("%d ",run->data);
    run = run->next;
  }
  bubbleSort(head);
 struct Node* head2 = (struct Node*) malloc(sizeof(struct Node));
 head2 = NULL;
 run = NULL;
  k = 1;
  printf("\nCreate 2nd linkedlist \n");
  for(int i = 1; i<=5; i++){
     run = create(run,k);
    if(i == 1){
      head2 = run;
    }
    k +=1;
  }
 printf("\nThe values store in  linked-list-2 are :-\n");
  run = head2;
  while(run != NULL){
    printf("%d ",run->data);
    run = run->next;
  } 
  bubbleSort(head2);
   headM = NULL;
   run = head;
   temp = head2;
  if(headM == NULL){
   if(run->data > temp->data){
        headM->data = temp->data;
        headM->next = NULL; 
        temp = temp->next;
   } else{
      headM->data = run->data;
       headM->next = NULL;      
      run = run->next;
   }
   printf("mergeHead = %d\n",headM->data);
  merge2LL(run,temp,headM);
 printf("After merging of 2 unsorted linked-list are :- ");
 run = headM;
 while(run !=NULL){
  printf("%d ",run->data);
  run = run->next;
    }
  }
}

void bubbleSort(struct Node* node){// O(n^2)
 if(node == NULL){
    printf("The list is empty!");
    return;
 }
   temp = node; 
  while(temp !=NULL){
   bool isSwap = false;
   struct Node* prevNode = head;
   run = prevNode->next;

   while(run !=NULL){
   int prev = prevNode->data;
   int curr = run->data;
    if(prev > curr){
     // swapping hoga
     prevNode->data = curr;
     run->data = prev;
      isSwap = true;
      }
      // update the pointers 
      run = run->next;
      prevNode = prevNode->next;
    }

   if(isSwap == false) break;
    temp = temp->next;
  }
}

void merge2LL(struct Node* h1,struct Node* h2,struct Node* h){
  if(h1 == NULL || h2 == NULL){
    printf("Merging 2 ll is not possible b/c one of them is empty list \n");
    return;
  }
  merge = h;
  while(run!=NULL && temp !=NULL){
    if(run->data > temp->data){
     struct Node*t = (struct Node*)malloc(sizeof(struct Node));
        t->data = temp->data;
        t->next = NULL;
        merge->next = t;
        merge = merge->next;
        temp = temp->next;
    }else{
      struct Node*t = (struct Node*)malloc(sizeof(struct Node));
      t->data = run->data;
      t->next = NULL;
       merge->next = t;
       merge = merge->next;
      run = run->next;
    }
  }
  // merging for remaing sorted nodes
  while(run !=NULL){
     struct Node*t = (struct Node*)malloc(sizeof(struct Node));
        t->data = run->data;
        t->next = NULL;
        merge->next = t;
        merge = merge->next;
         run = run->next;
  }
 while(temp !=NULL){
     struct Node*t = (struct Node*)malloc(sizeof(struct Node));
        t->data = temp->data;
        t->next = NULL;
        merge->next = t;
        merge = merge->next;
        temp = temp->next;
  } 
}