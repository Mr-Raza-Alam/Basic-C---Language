#include<iostream>
#include<climits>  
using namespace std;
int main (){
    int n ,i,j,temp, t;
    cout<<"Enter the array's size = " ;
    cin>>n;
    int arr[n];
    cout<<"Enter your values here "<<endl;
    for(i = 0 ; i<n; i++) cin>>arr[i];
    /*cout<<"The given values are in the ascending order :-"<<endl;
    for(i = 0 ; i<n-1; i++){
        j = i + 1;
        while(j >0 && arr[j]<arr[j-1]){
              temp = arr[j];
              arr[j] = arr[j-1];
              arr[j-1] = temp;
              j--;
        }
    }
    for(i = 0 ; i<n; i++) cout<<" "<<arr[i];
    cout<<"\nThe smallest value among the given array = "<<arr[0]<<endl;
    cout<<"\nThe largest value among the given array = "<<arr[n-1]<<endl;
   */
   int smallest = INT_MAX;

    for(i = 0 ; i<n; i++){
        if(smallest>arr[i]){
            smallest = arr[i];
            j = i;
        }
    }
    cout<<"\nThe smallest value among the given array arr["<<j<<"] = "<<smallest<<endl;
      
      int largest = INT_MIN ;
   for(i = 0 ; i<n; i++){
        if(largest<arr[i]){
            largest = arr[i];
            t = i;
        }
    }
    cout<<"\nThe largest value among the given array arr["<< t <<"] = "<<largest<<endl;

    return 0;
}