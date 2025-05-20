#include<iostream>
using namespace std;

int linearsearch(int brr[],int point,int m){
  for(int i = 0; i<m; i++){
    if(brr[i]==point) return i;
  }
  return (-1);// for not found the point value
}

int main (){
   int n,i ,target;
   cout<<"Enter the array's size = ";
   cin>>n;
   int arr[n];
   cout<<"Enter your values to store in the array"<<endl;
   for(i = 0; i<n; i++) cin>>arr[i];

   cout<<"Enter your target value = ";
   cin>>target;

   if(linearsearch(arr,target,n)==(-1)) cout<<"The target value "<<target<<" is unavialable in the given array "<<endl;
   else{
        cout<<"The poistion of your target value "<<target <<" = arr["<<linearsearch(arr,target,n)<<"]"<<endl;
   }
    return 0;
}