#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// stack ,using linked-list
struct Node{
    int data ;
  struct Node* next;
};

struct Node* head,*run,*temp;
// initialize 
void initialize(){
  temp = (struct Node*)malloc(sizeof(struct Node));
  int n;
  printf("Enter data-1 = ");
  scanf("%d",&n);
  temp->data = n;
  temp->next = NULL;
  head = temp;
  run = temp;
}

// push
void push(int k){
temp = (struct Node*)malloc(sizeof(struct Node));
  int n;
  printf("Enter data-%d = ",k);
  scanf("%d",&n);
  temp->data = n;
  temp->next = NULL;
  run->next = temp;  
  run = run->next;
}
// pop
int pop(){
    if(head == NULL){
        printf("Stack is empty!\n");
        return -1;
    }
 int top = head->data;
 head = head->next;
 return top;
}
// peek
int peek(){
   if(head == NULL){
    printf("Stack is empty!\n");
     return -1;
  }
 return head->data;
}
// isEmpty
bool isEmpty(){
    if(head == NULL){
     return true;
    }
 return false;
}
bool isEmpty();
int peek();
int pop();
void push(int k);
void initialize();
void ansb();
void ansD(int x);

void main(){
    int k = 2;
 printf("Initialize a base node \n");
  initialize();
  for(int i = 1; i<8; i++){
    push(k);
    k++;
  }
  printf("The value stored in the stack are :- \n");
     run = head;
   while(run !=NULL){
    printf("%d ",run->data);
    run = run->next;
  }
 printf("\nThe answer of option-A is :- \n");
  // a
  printf("Top = %d\n",peek());
  // b
 printf("\nThe answer of option-B is :- \n");
  ansb();
 run = head;
 while(run !=NULL){
    printf("%d ",run->data);
    run = run->next;
 }
 // c
 printf("\nThe answer of option-C is :- \n");
  run = head;
  while(run->next!=NULL){
    printf("%d ",run->data);
    run = run->next;
  }
  // d
 printf("\nThe answer of option-D is  :- \n");
 ansD(4);   
   run = head;
   while(run !=NULL){
    printf("%d ",run->data);
    run = run->next;
  }
}

void ansD(int x){
  run = head;
  while(run != NULL){
    if(run->data == x){
        run->data = -1;
    }
    run = run->next;
  }
}

void ansb(){
temp = head;
run = head->next;
for(int i = 1; i<=3; i++){
  if(i == 3){
    temp = temp->next;
    temp->next = run;
    break;
  }
  run = run->next;
 }
}
