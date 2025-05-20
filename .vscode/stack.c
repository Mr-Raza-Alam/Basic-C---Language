#include<stdio.h>
int top = -1;
#include<stdlib.h>
 typedef struct node{
    int item;
    struct node* next;
}node;
  node* temp,*first,*last,*run;
  void create(){ 
    int x;
    printf("Enter the base data = ");
    scanf("%d",&x);
    temp = (struct node*) malloc(sizeof(node));
    temp->item   = x ;
    temp->next = NULL;
    top++;
    first = temp;
    run = first;
    printf("%d is store at top = %d\n",run->item,top);
    return;
  }
     
  void create();
  void display();
  void  pop();
  void push(); 
  
  void main(){
    int c;
     printf("press :0-> To create base node\n");
     printf("press:1-> To push your value\n");
     printf("press:2-> To pop the value\n");
     printf("press:3-> To display the inserted value in the given stack\n");
     printf("press:4-> To exist\n");
     while(1){
        printf("\nEnter the choice of action = ");
        scanf("%d",&c);
         if(c == 0) create();
         else if(c ==1) push();
         else if(c == 2) pop();
         else if(c== 3)display();
         else{
          printf("The operations on stack data structure has been ended!!\n");
          break;
         }
     }
  }
 
 void push(){
    int newitem;
    temp = (node*) malloc(sizeof(node));
    printf("Enter your new inserting input = ");
    scanf("%d",&newitem);
    temp->item = newitem;
    temp->next = first;
    top++;
    first = temp;
    printf("%d is store at top = %d\n",first->item,top);
 }

 void pop(){
  if(top == -1) printf("Stack-Underflow!.....\n"); 
    temp = first;
   printf("%d is delete from top = %d\n",temp->item,top);
    top--;
   first = first->next;
   free(temp);
 }

 void display(){
     if(run==NULL) printf("Linked list is empty\n");
     printf("The given value stored in the stack are:\n");
      run = first;
    while(run!=NULL){
      printf("%d\t",run->item);
      run = run->next;
    }
 }
/*
#include<stdio.h>
#define size  10
int stack[size];
int top = -1;

void push(){//Stack ---> push implementation using array
   top++;
    if(top == (-1)){
        printf("The stack is empty! please insert any value\n");
    }
    else if(top == size-1){
         printf("The stack is totally fulled! Cannot be insert any value more\n");
        return;
    }
    else{
       int n;
        printf("\nEnter your value..... = ");
        scanf("%d",&n);
        printf("%d is inserted at top = %d\n",n,top);
        stack[top] = n;

    }
}

void push();
int pop();
void display();

void main(){
    int i,k;
     printf("press:1-> To push your value\n");
     printf("press:2-> To pop the value\n");
     printf("press:3-> To display the inserted value\n");
     printf("press:4-> To exist\n");
    while(top<size){
        printf("\nEnter your choice of action = ");
        scanf("%d",&k);
      if(k==1){
        push();
       }
     else if(k==2){
         pop();
      } 
     else if(k==3){
        display();
     }
     else{
        printf("\n");
        break;
      }
    }
}

int pop(){//using array
     int x;
    if(top == (-1) ){
        printf("The stack is empty! please insert any value\n");
    }
    else{
       x = stack[top];
       printf("%d is deleted from top = %d\n",x,top);
       top--;
       return x;
    }
}

void display(){
    printf("The given values store in the stack are:\n");
    for(int i = top; i>=0; i--){
        printf("%d ",stack[i]);        
    }
}
*/