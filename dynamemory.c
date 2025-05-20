#include<stdio.h>
#include<stdlib.h>
void main (){
   int a,i;
   printf("Enter your desire size to alllocate = ");
   scanf("%d",&a);
   int arr[a];
   printf("Address of array before heap allocation = %u\n",&arr);
   for(i = 0; i<a; i++){
    arr[i] = 2*i+1;
   }
   for(i = 0; i<a; i++) printf("arr[%d] = %d\n",i,arr[i]);
   //int*p = (int*) malloc(a*(sizeof(int)));
   //int*p = (int*) calloc(a,(sizeof(int)));
    int*p = (int*)realloc(arr,0);
    printf("Address of array After heap allocation = %u\n",p);
    for(i = 0; i<; i++) printf("arr[%d] = %d\n",i,arr[i]);
    
}