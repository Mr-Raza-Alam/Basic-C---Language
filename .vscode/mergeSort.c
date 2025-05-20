#include<stdio.h>

void conqure(int arr[],int si, int mid,int ei){
 int n = ei-si + 1;
 int mergeArr[n];
    //printf("The size of merged array = %d\n",size);
    int idx1 = si;
    int idx2 = mid + 1;
    int x = -1;
    while(idx1<=mid && idx2<=ei){
      if(arr[idx1]<=arr[idx2]){
           x++;
         mergeArr[x] = arr[idx1];       
         idx1++;
      }
      else{
             x++;
      mergeArr[x] = arr[idx2];  
      idx2++;
      }
    }
 while(idx1<=mid){
      x++;
       mergeArr[x] = arr[idx1];    
       idx1++;
 }
  while(idx2<=ei){
         x++;
       mergeArr[x] = arr[idx2]; 
       idx2++;
 }
//copy meged's element in the original array arr[];
 for(int i =si,j = 0; j<n; i++,j++){
    arr[i] = mergeArr[j];
 }

}

void divide(int arr[],int si,int ei){
 //base condition is when si>ei then stop recurssion taht means we got the single element
if(si<ei){
   int mid =  si + (ei-si)/2;
   //divide time
   divide(arr,si,mid);
   divide(arr,mid+1,ei);
   //conqure time
   conqure(arr,si,mid,ei);
  }
}

void main(){
//  int arr[7] = {6,4,5,2,1,8,3};
//  int n = 7;
   int n;
   printf("Enter the Arrray's size = ");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the values to store in the given array\n");
   for(int i = 0; i<n; i++){
    scanf("%d",&arr[i]);
   }
   //let say arr[n] = {4,6,3,2,9,1,5};
   //call divide function
   divide(arr,0,n-1);
   printf("After merged sort the new-updated array is\n");
   for(int i = 0; i<n; i++){
    printf("%d ",arr[i]);
   }

}