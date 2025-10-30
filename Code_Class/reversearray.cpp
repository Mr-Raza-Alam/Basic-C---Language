#include<iostream>
using namespace std;
  
  void swaparr(int s,int e,int brr[]){
      int temp;
      temp = brr[s];
      brr[s] = brr[e];
      brr[e] = temp;
  }

int main (){
    int n,i,start = 0, end;
    cout<<"Enter the array's size = ";
    cin>>n; 
    end = n-1;
    int arr[n];
    cout<<"Enter the values to store in the given array "<<endl;
    for(i=0 ; i<n; i++) cin>>arr[i];
    while(start<end){
        swaparr(start,end,arr);
        start++;
        end--;
    }
    cout<<"The reverse array "<<endl;
    for(i = 0; i<n; i++) cout<<arr[i]<<" ";
    return 0; 
} 