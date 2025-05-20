#include<stdio.h>
#include<stdlib.h>

#define size 5  
int Queue[size];
int front = -1,rare = -1;

void enqueue();//enqueue means insertion of data in the queue using Array's implementation;
void dequeue();//dequeue means deletion of data from the queue using Array's implementation;
void display();

void main(){
       int choice;
       printf("press:1--> To enqueue the value\n");
       printf("press:2--> To dequeue the value\n");
       printf("press:3--> To diaplay the values\n");
       printf("press:4--> To exist\n");
        if(rare == (-1)) front = 0;
      while(choice!=4){
        printf("\nEnter the choice of action = ");
        scanf("%d",&choice);
        if(choice == 1) enqueue();
        else if(choice == 2) dequeue();
        else if(choice == 3) display();
        else break;               
       }
}

void enqueue(){
    int x;
    if(rare == size -1){
        printf("The queue is completely full\n");
        return;
    }
    else{
      printf("Enter your value = ");
      scanf("%d",&x);
      rare++;
      Queue[rare] = x;
      printf("%d has been enqueue in %dth line\n",x,rare);
     
    }

}

void dequeue(){
    if(rare == size-1){
        printf("%d has been dequeue from %dth index\n",Queue[front],front);
        Queue[front] = 0;
        front++;
    }
    else if(rare == front){
          front = -1;
          rare = -1;
          printf("The queue is empty\n");
          return;
    }
    else {
        printf("%d has been dequeue from %dth index\n",Queue[front],front);
        Queue[front] = 0;
        front++;
        return;
    }
}

void display(){
    printf("The avialable value in the given queue are :\n");
    if(front == -1 && rare == -1){
       printf("The queue is completely empty\n");
    }
    else if(front == rare){
        printf("The queue contains only one element i.e = %d\n",Queue[front]);
    }
    else{
        for(int i = front; i<=rare; i++){
            printf("%d ",Queue[i]);
        }
    }
}

//  #include<stdio.h>
//  #include<stdlib.h>

//  typedef struct node{
//     int item;
//     struct node* next;
// }node;
//   node* temp,*first,*last,*run;
//   void create(){
//     int x;
//     printf("Enter your 1st desire data = ");
//     scanf("%d",&x);
//     temp = (struct node*) malloc(sizeof(node));
//     temp->item   = x ;
//     temp->next = NULL;
//     first = temp;
//     run = first;
//     printf("your base node has been created\nNow you can start enqueue operation\n");
//     return;
//   }
     
//   void create();
//   void display();
//   void dequeue();
//   void enqueue();
  
//   void main(){
//     int c;
//      printf("press :1-> To create base node\n");
//      printf("press:2-> To enqueue your value\n");
//      printf("press:3-> To dequeue the value\n");
//      printf("press:4-> To display the inserted value in the given Queue\n");
//      printf("press:5-> To exist\n");
//      while(c!=5){
//         printf("\nEnter the choice of action = ");
//         scanf("%d",&c);
//          if(c==1) create();
//          else if(c == 2) enqueue();
//          else if(c == 3) dequeue();
//          else if(c == 4) display();
//          else break;
//      }
//   }
 
//  void enqueue(){
//     int newitem;
//    temp = (node*) malloc(sizeof(node));
//    printf("Enter your new inserting input = ");
//    scanf("%d",&newitem);
//     temp->item = newitem;
//     temp->next = NULL;
//     run ->next = temp;
//     run = run->next;
//     //last = temp;
//    printf("%d has been inserted\n",newitem);
//  }

//  void dequeue(){
//     temp = first;
//    printf("%d has been deleted\n",temp->item);
//    first = first->next;
//    free(temp);
//  }

//  void display(){
//      printf("The given value stored in the Queue are:\n");
//       run = first;
//      if(run==NULL) printf("The Queue is empty\n");
//     while(run!=NULL){
//       printf("%d  ",run->item);
//       run = run->next;
//     }
//  }
