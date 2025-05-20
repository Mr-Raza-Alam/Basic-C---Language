#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head,*run,*temp,*tail;
void create(){ 
  int n,max,i = 2;
  printf("Enter total no. of node require = ");
  scanf("%d",&max);
 temp = (struct Node*)malloc(sizeof(struct Node));
 printf("Enter data-1 = ");
  scanf("%d",&n);
 temp->data = n;
 temp->next = NULL;
 head = temp;
 run = temp;

 for(int k = 1; k<max; k++){
 temp = (struct Node*)malloc(sizeof(struct Node));
  printf("Enter data-%d = ",i);
  scanf("%d",&n);
  i +=1;
 temp->data = n;
 temp->next = NULL;
 run->next = temp;
 run = run->next;
 }
 tail = temp;
}
void display(){
 if(head == NULL){
    printf("The list is empty!\n");
    return;
 }
 printf("The data stored in the list are :- \n");
     run = head;
 while(run !=NULL){
    printf("%d ",run->data);
    run = run->next;
 }
}

void create();
void display();

void main(){
    int c;
    printf("Press-1 : to create a ll\nnPress-2 : to display\nPress-3 : to exit\n");
    while(1){
     printf("\nEnter the choice of action = ");
     scanf("%d",&c);
     if(c == 1) create();
     else if(c == 2) display();
     else break;
    }

}