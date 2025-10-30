#include<stdio.h>
#include<stdlib.h>
 typedef struct node{
    int item;
    struct node* next;
}node;
  node* temp,*first,*last,*run,*temp2,*curr,*prev,*nextNode;
  void create(){
    int i,x,max;
    printf("Enter the total no. of nodes required = ");
    scanf("%d",&max);
    printf("Enter your 1st desire data = ");
    scanf("%d",&x);
    temp = (struct node*) malloc(sizeof(node));
    temp->item   = x ;
    temp->next = NULL;
       first = temp;
       run = first;
     for(i = 1; i<max; i++){
      printf("Enter your next data = ");
      scanf("%d",&x);
        temp = (struct node*) malloc(sizeof(node));
        temp->item = x;
        temp->next = NULL;
        run->next = temp;
        run = run->next; 
     }
     last = run;
    return;
  }
    void printline(){
    for(int i = 1; i<=35; i++) printf("=");
    return;
  } 

struct node* reverseRecurrsively(struct node* head){
 if(head == NULL || head->next == NULL){
  return head;
 }
// kaam
struct node* newHead = reverseRecurrsively(head->next);
head->next->next = head;
head->next = NULL;
return newHead;
}
void reversell(){
  run = first;
  int x;
  while(run!=NULL){
     x = reverseRecurrsively(run)->item;
    printf("%d ",x);
     run = run->next;
  }
}

  // void reverseLinklist(){
  //   if(first->next == NULL || first == NULL){
  //     return;
  //   }
  //    prev = first;
  //    curr = first->next;
  //    while(curr!=NULL){// using iterative method
  //     nextNode = curr->next;
  //     curr->next = prev;
  //     // update
  //     prev = curr;
  //     curr = nextNode;
  //    }
  //    first->next = NULL;
  //    first = prev;
  //    return;
  //}
  void reversell();
  void create();
  void display();
  void delete();
  void insert();
  struct node* reverseRecurrsively(struct node* head);
  void reverseLinklist();

  void main (){
    int c;
     printf("Welcome to Linked-list world\n");
     printf("what do you like to do here!\n");
     printline();
     printf("\nTo create a linked-list: press 1\nTo insert the new data:press 2\nTo delete the avilable data:press 3\nTo display the given data : press 4\nTo reverse linkedlist:- press 5\nTo exits:press 6\n");
     while(c!=6){
     printf("\nEnter your preference choice = ");
     scanf("%d",&c);
     if(c==1) create();
     else if(c==2) insert();
     else if(c==3) delete();
     else if(c==4) display();
     else if(c == 5) reversell();
     else if(c==6) printf("You have been succesfully existed from linked-list world\n");
     else{ printf("Invalid input!try again"); 
           printf("\nwhat do you like to do now!");
         }    
    }
     
  }
  void display(){
    run = first;
    while(run!=NULL){
      if(run==NULL) printf("Linked list is empty\n");
      printf("%d\t",run->item);
      run = run->next;
    }
  }
  void insert(){
    int newitem,p,pts;
    if(first==NULL){
      printf("No insertion is possible! Linked-list is empty\n");
      return;                                                                                                                                                                                                                                                                                                                      
    }
    printf("\npress 1: for inert from begining\npress 2: for inert from ending\npress 3: for insert from any position\n");
    printf("Enter your choice = ");
    scanf("%d",&p);
    if(p==1){
    temp = (node*) malloc(sizeof(node));
    printf("Enter your new inserting input = ");
    scanf("%d",&newitem);
    temp->item = newitem;
    temp->next = first;
    first = temp;
    printf("\nInsertion from begining has been successfully done\n");
    }
    else if(p==2){
  temp = (node*) malloc(sizeof(node));
   printf("Enter your new inserting input = ");
    scanf("%d",&newitem);
    temp->item = newitem;
    temp->next = NULL;
    last->next = temp;
    printf("\nInsertion from ending has been successfully done\n");
    }
    else if(p==3){
        printf("Enter the position b/w 1st and last for insertion = ");
        scanf("%d",&pts);
        run = first;
        temp2 = first;
         for(int i= 1; i<pts; i++){
              run = run->next;
            if(i == (pts-1)){
               temp = (node*) malloc(sizeof(node));
               printf("Enter your new inserting input = ");
               scanf("%d",&newitem);
               temp->item = newitem;                 
               temp2->next = temp;
               temp->next = run;  
             printf("%d has been inserted at %dth position\n",newitem,pts);
             }  
            temp2 = temp2->next;
        }

    }
    else {
      printf("No insertion is possible! enter the correct option\n");
      return;
    }
      
  }
void delete(){
   int m,p;
   if(first==NULL){ 
     printf("No deletion occurs|linked-list is empty\n");
        return;
   }
   printf("\npress:1 for deletion from begin\npress:2 for deletion from ends\npress:3 for deletion b/w 1st and last\n");
   printf("Enter your choice here = ");
   scanf("%d",&m);
   if(m==1){
   temp = first;
   first = first->next;
   free(temp);
   printf("\nDeletion from begining has been successfully done\n");
   }
   else if(m==2){
    run = first;
    while(run->next!=last){
      run = run->next;
     }
     temp = last;
     run->next = NULL;
     last = NULL;
      free(temp);
      printf("\nDeletion from ending has been successfully done\n");
   }
  else if(m==3){
     printf("Enter the deleting position = ");
     scanf("%d",&p);
     run = first;
     temp2 = first;    
       for(int i = 1; i<p; i++){
         run = run->next; 
         if(p == 2){   
           temp = run;
           printf("%d has been deleted from %dnd position\n",temp->item,p);                
           run = run->next;
           temp2->next = run;
            free(temp);
         }
         else if(i == (p-1)){
            temp = run;
            printf("%dth has been deleted from %dth position \n",temp->item,p);
            run = run->next;
            temp2 = temp2->next;
            temp2->next = run;
            free(temp);
          }
         else{
            if(i>=2){
              temp2 = temp2->next;
            }
         }
       }
     }
   }
  // else printf("\nNo deletion is possible ! press correct option\n");
 