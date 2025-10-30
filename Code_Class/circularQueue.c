#include<stdio.h>

#define size 5  
int Queue[size];
int front = -1,rare = -1;

void enqueue();//enqueue means insertion of data in the queue using Array's implementation;
void dequeue();//dequeue means deletion of data from the queue using Array's implementation;
void display();
void circular_enqueue();

void main(){
       int choice,t = 0;
       printf("press:1--> To enqueue the value\n");
       printf("press:2--> To dequeue the value\n");
       printf("press:3--> To diaplay the values\n");
       printf("press:4--> To Circular-enqueue the value\n");
       printf("press:5--> To exist\n");

        if(rare == (-1)) front = 0;
      while(choice!=5){
        t++;
        printf("\nEnter the choice of action = ");
        scanf("%d",&choice);
        if(choice == 1) enqueue(t);
        else if(choice == 2) dequeue();
        else if(choice == 3) display();
        else if(choice == 4) circular_enqueue();
        else break;               
       }
}
  
void enqueue(int t){
    int x;
    if(rare == size -1){
        printf("The queue is completely full\nfor further enqueue operation call circular-enqueue function\n");
        rare = 0;
        return;
    }
 else if(t == 1){
   for(int i = 0 ; i<size; i++){
      printf("Enter your value = ");
      scanf("%d",&x);
      rare++;
      Queue[rare] = x;
            
      }
   printf("Rare = %d\n",rare);
     }
}
void circular_enqueue(){
    if(rare == front){
        printf("The queue is fulled!\n1st remove some data\n");
    }
    else{
    int x;
    printf("Enter the input = ");
    scanf("%d",&x);
     Queue[rare] = x;
     printf("Rare = %d\n",rare);
      rare++;
    }
}

void dequeue(int k){
    if(front == size){
        front = 0;
         return;
    }
    else {
        //printf("The simple queue is not fulled ! please insert more input\n");
        printf("dequeue occurs at front = %d\n",front);
        Queue[front] = 0;
        front++;

    }
}

void display(){
    printf("The avialable value in the given Circular-queue are :\n");
    if(front == -1 && rare == -1){
       printf("The queue is completely empty\n");
    }
    else{
     for(int i = 0; i<size; i++){
        if(i<rare)printf("%d ",Queue[i]);
        else if(i >=rare) printf("%d ",Queue[i]);
    }
  }    
}