#include<stdio.h>
#include<limits.h>
#include<math.h>

void getCountingSort(int nums[],int size){
    int largest = INT_MIN;
    for(int i = 0; i<size; i++){//n times rum i.e O(n)*c
        largest = fmax(largest,nums[i]);
    }
    printf("largest = %d\n",largest);
    int countArr[largest+1] ;
    for(int i =0 ;i<=largest; i++){// let largest = k , i.e. loop will run k times and O(k)*c;
        countArr[i] = 0;
    }
    for(int i = 0; i<=largest; i++){//store freq. of each element O(k)*c;
        countArr[nums[i]]++;
        printf("countArr[%d] = %d\n",nums[i],countArr[nums[i]]);
    }
  //sorting
    for(int i =0; i<=largest; i++){// O(n)
        while(countArr[i]>0){//k
           printf("%d ",i);
            countArr[i]--;
        }
    }
}

void main(){
    int size; 
    printf("Enter the size of array = ");
    scanf("%d",&size);
    int nums[size];
    printf("Enter the elements to store in the given array\n");
    for(int i = 0; i<size ; i++){
        scanf("%d",&nums[i]);
    }
    printf("\nThe sorted array in Ascending Order is \n");
    getCountingSort(nums,size);
   
}