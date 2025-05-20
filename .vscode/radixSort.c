#include<stdio.h>

int getMax(int arr[],int n){
    int mx = arr[0];
    for(int i = 1; i<n; i++){
        if(mx<arr[i]){
            mx = arr[i];
        }
    }
    return mx;
}

//Counting sort
void getCountingSort(int arr[],int place,int size){
    int output[size] ;
    int countArr[10] ;
    for(int i =0 ;i<10; i++){// let largest = k , i.e. loop will run k times and O(k)*c;
        countArr[i] = 0;
    }
    for(int i = 0; i<size; i++){//store freq. of each element O(k)*c;
        countArr[(arr[i]/place)%10]++;
        printf("countArr[%d] = %d\n",(arr[i]/place)%10,countArr[(arr[i]/place)%10]);
    }
    // prefix sum 
    for(int i = 1; i<10; i++){
          countArr[i] +=countArr[i] -1;
    }
  //sorting
    for(int j = size -1; j>0; j--){
        int idx = countArr[(arr[j]/place)%10] - 1;
         output[idx] = arr[j];
         countArr[(arr[j]/place)%10]--;
    }
    // copy all elements of o/p  to arr
    for(int i =0; i<size; i++){
        arr[i] = output[i];
    }
}

//Radix sort
 void radixSort(int arr[],int size){
      int n = getMax(arr,size);
      //cal. no.of digit of max.element of arr[]
      int count = 0, N = n;
      while(N>0){
        N /=10;
        count++;
      }
      printf("The digits of max. element = %d\n",count);
      for(int place = 1; n/place>0; place *=10){
          getCountingSort(arr,place,size);
      }
      printf("The sorted array in Ascending Order is:-\n ");
      for(int i = 0;i<size; i++){
        printf("%d ",arr[i]);
      }
 }

 int getMax(int arr[],int n);
 void InsertionSort(int arr[],int size);
 void radixSort(int arr[],int size);

 void main(){
    int size;
    printf("Enter the array's size = ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the values to store in the given array\n");
    for(int i = 0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    radixSort(arr,size);
 }