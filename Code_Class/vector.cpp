#include<iostream>
#include<vector>
using namespace std;
 
int testDrive(int n){
    vector<int>vec;
  for(int i = 1; i<=n; i++){
    vec.push_back(2*i);
    } 
    vec.pop_back();
 cout<<"The value in the vector are from last to first are : "<<endl;
    while(vec.size() != 0){
        cout<<vec.back()<<" ";
        vec.pop_back();

     }
  return vec.capacity();
}

int main (){
    int n;
    cout<<"Enter the vector's size = ";
    cin>>n;
     cout<<"\nLast element of list = "<<testDrive(n)<<endl;
    //cout<<"The size of given vector above after pushing back a value  = "<<vec.size()<<endl;
     //cout<<"The capacity of vector after push back = "<<vec.capacity()<<endl;
   
     //for(int val: vec) cout<< val<<" ";
     
    return 0;
}
    //  cout<<"The size of given vector above = "<<vec.size()<<endl;
    //  cout<<"The capacity of vector = "<<vec.capacity()<<endl;