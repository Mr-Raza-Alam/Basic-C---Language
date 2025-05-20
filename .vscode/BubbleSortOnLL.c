// bubble sort on linked list
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
struct Node{
    int data;
    struct Node* next;
};
struct Node* head,* run,* temp,* tail;

void create(){//O(n)
 int max,n,i=2;
 printf("Enter the total no. of node required = ");
 scanf("%d",&max);
 temp = (struct Node*) malloc(sizeof(struct Node));
 printf("Enter data-1 = ");
 scanf("%d",&n);
   temp->data = n;
   temp->next = NULL;
   head = temp;
   run = temp;
 for(int k = 1; k<max; k++){
   temp = (struct Node*) malloc(sizeof(struct Node));
   printf("Enter data-%d = ",i);
   scanf("%d",&n);
   temp->data = n;
   temp->next = NULL;
   run->next = temp;
   run = run->next;
   i +=1;
 }
 tail = temp;
}
void bubbleSort(){// O(n^2)
 if(head == NULL){
    printf("The list is empty!");
    return;
 }
   temp = head; 
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
void bubbleSort();
void create();
void removeDuplicate();

void main(){// TC = o(n^2)
printf("Create a linkedlist first\n");
  create();//O(n)
  printf("Before bubble sort\n");
   run = head;
 while(run!=NULL){
    printf("%d ",run->data);
    run = run->next;
 }
  bubbleSort();// O(n^2)
 printf("\nAfter bubble sort\n");
 run = head;
 while(run!=NULL){
    printf("%d ",run->data);
    run = run->next;
 }
 removeDuplicate();
  printf("\nAfter removing a duplicate element\n");
  run = head;
  while(run!=NULL){
    printf("%d ",run->data);
    run = run->next;
  }
}

void removeDuplicate(){// O(n)
  temp = head;
  run = head;
  struct Node* prev = head;
  struct Node* curr = head->next;
  int i = 1;
  while(run!=NULL){
        i++;
   if(prev->data == curr->data){
    head = head->next;
    free(prev);
    break;
   } else if(i ==2){
      prev = prev->next;
      curr = curr->next;
    if(prev->data == curr->data){
       temp->next = curr;
        free(prev);
       break;
      }
    }else{
     temp = temp->next;
    prev = prev->next;
    curr = curr->next;
    if(prev->data == curr->data){
        temp->next = curr;
        free(prev);
        break;
      } 
   }
   run = run->next;
  }
}