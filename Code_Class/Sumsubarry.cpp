#include<iostream>
#include<climits>
using namespace std;

int main (){
   int n,i,st,end,curr_sum,max_sum = INT_MIN;//st means start
//    cout<<"Enter the array's size = ";
//    cin>>n;
//    int arr[n];
//    cout<<"Enter your values to store in the given array\n";
//    for(i = 0; i<n; i++) cin>>arr[i];
//     for(st = 0; st<n; st++){//Burate Force Approach
//         curr_sum = 0;
//         for(end = st; end<n; end++){
//             curr_sum +=arr[end];
//             max_sum = max(curr_sum,max_sum);
//         }
//     }
//     cout<<"The maximum sum of subarray = "<<max_sum<<endl;
  // int n,i,st,end;//st means start
   cout<<"Enter the array's size = ";
   cin>>n;
   int arr[n];
   cout<<"Enter your values to store in the given array\n";
   for(i = 0; i<n; i++) cin>>arr[i];   
    
    for(st = 0; st<n; st++){
            curr_sum = 0;        
       for(end = st; end<n; end++){//Kadane's Algorithm
           curr_sum +=arr[end];
           max_sum = max(curr_sum,max_sum);
           if(curr_sum<0){
            curr_sum = 0;
           }      
         }
      }
      cout<<"The maximum sum of sub-array = "<<max_sum<<endl;
    return 0; 
}