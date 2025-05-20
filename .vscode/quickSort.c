#include<stdio.h>
// partition -> find pivot element's index
int partition(int arr[],int low,int high){
  // here in each recurrsive call , i assume pivot element = last element of subarray always
  // and According to that i am going to place smaller value than pivot in left side and larger one in other side
  int pivot = arr[high];
  int x = low-1;
  // swapping
  for(int i = low; i<high; i++){
    // now place smaller element than pivot element in left side 
    if(arr[i] < pivot){
     // first we create a space for lower value than pivot value
     x++;
     int temp = arr[x];
     arr[x] = arr[i];
     arr[i] = temp;     
    }
  }
  // now its time to place pivot element on its correct position by swapping
  x++;
    int temp = arr[x]; 
     arr[x] = arr[high];
     arr[high] = temp; 
    return x;
}

void quickSort(int arr[],int low,int high){
 if(low<high){
    int pvtIdx = partition(arr,low,high);
    quickSort(arr,low,pvtIdx-1);
    quickSort(arr,pvtIdx+1,high);
 }
}

void main(){
  int arr[] = {6,9,3,8,1,4,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Before Quick sort\n");
  for(int i = 0; i<n; i++){
    printf("%d ",arr[i]);
  }
  quickSort(arr,0,n-1);
  printf("\nAfter Quick sort\n");
  for(int i = 0; i<n; i++){
    printf("%d ",arr[i]);
  }
}



