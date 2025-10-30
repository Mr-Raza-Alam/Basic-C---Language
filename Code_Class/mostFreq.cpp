#include<iostream>
using namespace std;

void most_Freq_ele(int arr[],int map[],int n);
void dnf_Sort(int arr[],int n);
  

void insertSort(int arr[],int n,int map[]){
    if(arr[0] == 0) map[0]++;
    else if(arr[0] == 1) map[1]++;
    else map[2]++;
   for(int i = 1; i<n; i++){
      int j = i-1;
      int key = arr[i];
     while(j>=0 && arr[j] > key){
       // swapp
       arr[j+1] = arr[j];
       j--;
     }
     arr[j+1] = key;
    if(key == 0) map[0]++;
    else if(key == 1) map[1]++;
    else map[2]++;
   }
} 
 void mostFreqEle(int arr[],int n,int map[]){
 insertSort(arr,n,map);
 cout<<"The values after sorting are :- "<<endl;
  for(int i = 0; i<n; i++){
    cout <<arr[i]<<" ";
 } 
 cout<<"\nFrequency of 0's = "<<map[0]<<endl;
 cout<<"Frequency of 1's = "<<map[1]<<endl;
 cout<<"Frequency of 2's = "<<map[2]<<endl;
 int k = 0,mostFre = -1;
  for(int j = 0; j <3; j++){
    if(mostFre < map[j]){
      mostFre = map[j];
      k = j;
    } 
   }
cout<<"Most frequent element is "<<k<<"'s with its frequency = "<<mostFre<<endl;
 }
// 2nd way with O(n),O(1)
void most_Freq_ele(int arr[],int map[],int n){//O(n+p+j+k)-->O(n)
  // step-1 store frequencies of 0's,1's,&2's
 for(int i =0; i<n; i++){//O(n)
   if(arr[i] == 0) map[0]++;
   else if(arr[i] == 1) map[1]++;
   else map[2]++;
 } 
// step-2 re-fill the array's elements in sorted order
int idx = 0;
 for(int i = 0; i<map[0]; i++){//O(p),p = total no. of 0's
   arr[idx] = 0;
   idx++;
 }
 for(int i = 0; i<map[1]; i++){//O(j),j = total no. of 1's
  arr[idx] = 1;
    idx++;
 }
 for(int i = 0; i<map[2]; i++){//O(k),k = total no. of 2's
  arr[idx] = 2;
  idx++;
 }
 cout<<"The elements are in sorted order :- "<<endl;
 for(int i = 0; i<n;i++){
  cout<<arr[i]<<" ";
 }
 // step-3 find most frequent element
 cout<<"\nFrequency of 0's = "<<map[0]<<endl;
 cout<<"Frequency of 1's = "<<map[1]<<endl;
 cout<<"Frequency of 2's = "<<map[2]<<endl;
 int k = 0,mostFre = -1;
  for(int j = 0; j <3; j++){//O(3)--->O(1)
    if(mostFre < map[j]){
      mostFre = map[j];
      k = j;
    } 
   }
cout<<"Most frequent element is "<<k<<"'s with its frequency = "<<mostFre<<endl;
}

int main(){
 int n;
 cout<<"Enter the size = ";
 cin>>n;
 int arr[n];
 int map[3] = {0,0,0};
 cout<<"Enter the values to store in it are :- "<<endl;
 for(int i = 0; i<n; i++){
    cin>>arr[i];
 } 
 most_Freq_ele(arr,map,n);

//  cout<<"After sorting "<<endl;
//  dnf_Sort(arr,n);
//  for(int i = 0; i<n;i++){
//   cout<<arr[i]<<" ";
//  }
    return 0;
}

// using DNF that use 3 pointers
 void dnf_Sort(int arr[],int n){// O(n) with one pass and O(1)-->S/C
   int mid = 0,low = 0,high = n-1;
   while(mid <= high){
    // case-1
      if(arr[mid] == 0){
//       swap(arr[mid],arr[low]);
     int t = arr[mid];
     arr[mid] = arr[low];
     arr[low] = t;
        low++;
        mid++;
      } 
    // case-2
    else if(arr[mid] == 1){
       mid++;
    }
   // case-3
   else{
  //swap(arr[mid],arr[high]);
  int p = arr[mid];
  arr[mid] = arr[high];
  arr[high] = p;
    high--;
   }
   }
 }