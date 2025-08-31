// mostFrequent element-Set-A
#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

int mostFreqEle(){
   map<int,int> mp;
    int n,max = 0;
  cout<<"Enter the size of an array : "; cin>>n;
  cout<<"Enter "<<n<<" elements in the array "<<endl;
   int arr[n];
  for(int i =0; i<n; i++){
     cin>>arr[i];
  }

  // now 
  for(int i = 0; i<n; i++){
    int count = 1;
    for(int j = i+1; j<n; j++){
       int key = arr[i];
        if(key == arr[j]){
            count++;
           mp[key] = count;        
        }
      }  
    }
 
  // print the map
  cout<<left<<setw(5)<<"key "<<right<<setw(8)<<"value"<<endl;
  for(auto &t : mp){
    cout<<left<<setw(10)<<t.first<<t.second<<endl;
    if(t.second > max){
      max = t.second;
    }
  }
  return max;// mostfrequent element 
}

int main(){
  try{
     mostFreqEle();
  }catch(const char *err){
    cout<<err<<endl;
  }
    return 0;
}
