#include<stdio.h>
#include<stdlib.h>

struct sNode{
  int data;
  struct sNode* next;
};

struct queue{
  struct sNode* s1;
  struct sNode* s2;
};

void enQueue(struct queue* q,int val){
  push(&q->s1,val);
}

int deQueue(struct queue* q){
  int x;
  if(q->s1 == NULL && q->s2== NULL){
    return -1;
  }
  if(q->s2 == NULL){
    while(q->s1 !=NULL){
      x = pop(&q->s1);
      push(&q->s2,x);
    }
  }
  x = pop(&q->s2);
  return x;
}

void push(struct sNode** top,int newData){
struct sNode* newNode = (struct sNode*)malloc(sizeof(struct sNode));
if(newNode == NULL){
  printf("Stack Overflow");
  getchar();
  exit(0);
}

newNode->data = newData;
newNode->next = (*top);

*top = newNode;
}

int pop(struct sNode** top){
  int res;
  struct sNode* x;
 if(**top == NULL){
 return -1;
 } else{
  x = *top;
  res = top->data;
  *top = top->next;
  free(x);
  return res;
 }
}
int pop(struct sNode** top);
void push(struct sNode** top,int newData);
int deQueue(struct queue* q);
void enQueue(struct queue* q,int val); 

int main(){
  struct queue*q = (struct queue*) malloc(sizeof(struct queue));
  q->s1= NULL;
  q->s2 = NULL;
  enQueue(q,6);
  enQueue(q,8);
  enQueue(q,5);
  enQueue(q,3);

  printf("%d ",deQueue(q));
  printf("%d ",deQueue(q));
  printf("%d ",deQueue(q));
 
 return 0;
}

 