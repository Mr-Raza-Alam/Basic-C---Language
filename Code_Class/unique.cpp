#include<iostream>
using namespace std;

int main (){// paused ||
    int n,k;
    cout<<"Enter the array's size = ";
    cin>>n;
    int arr[n];
    cout<<"Enter your values to store in the given array "<<endl;
    for(int i = 0 ; i<n; i++) cin>>arr[i];
    cout<<"The unique elements are given below"<<endl;
   for(int i = 0; i<n; i++){
        k = 0;
       for(int j = n-1-i; j>i; j--){
        if(arr[i]==arr[j]) k =1;
       }
       if(k==0) cout<<arr[i]<<" ";
   }
    return 0;
} 