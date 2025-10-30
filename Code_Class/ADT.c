#include<stdio.h>
int lastPts = -1;
void delete(int arr[20]);
void upgrade(int arr[20]);
void display(int arr[20]);

void insert(int arr[20]){
    int a,b;
    printf("Enter the index at which newdata to be inserted = ");
    scanf("%d",&a);
    printf("Enter your data = ");
    scanf("%d",&b);
    if(lastPts>a){ 
    for(int i = lastPts; i>a; i--){
          arr[i] = arr[i-1];
        } 
       arr[a] = b ;     
       printf("%d has been inserted at index = %d\n",b,a);
       lastPts++;
       return;
    }
    else if(a>=lastPts){
          arr[a] = b;
       printf("%d has been inserted at index = %d\n",b,a);
       lastPts++;
          return;
    }
}

void main(){
int i,t,arr[20]={2,8,9,6,3};
printf("The available data are given below:-\n");
for(i = 0; i<20; i++){
      lastPts++;
      if(arr[i]==0) break;
      printf("%d, ",arr[i]);
 }
printf("\nDo you want any change ?\n if yes then,\npress 1 for insertion\npress 2 for deletion\npress 3 for display the values\npress 4 for upgrdation\npress 5 for exist\n");
printf("value = 0 means that place is empty\n");

while(1){
    printf("\nEnter the choice of action = ");
    scanf("%d",&t);  
    if(t==1) insert(arr);
    else if(t ==2) delete(arr);
    else if(t ==3) display(arr);
    else if(t ==4) upgrade(arr);
    else break;
  }
}
      
void delete(int arr[20]){
    int  a;
    printf("Enter the index no. to delete that index's data = ");   
    scanf("%d",&a);
    if(a<=lastPts){
      printf("%d has been deleted from index = %d\n",arr[a],a);
      arr[a] = 0;
       return; 
    }
}
void display(int arr[20]){
    printf("The data store in the given array are:-\n");
      for(int i = 0; i<lastPts; i++){
        printf("%d,",arr[i]);
      }

}
void upgrade(int arr[20]){
    int i,a,b;
    printf("Enter the index no.,where you want to upgrade = ");
    scanf("%d",&a);
    printf("Enter the new data  = ");
    scanf("%d",&b);
    printf("%d has been upgradated by %d\n",arr[a],b);
    arr[a] = b;
   return; 
}