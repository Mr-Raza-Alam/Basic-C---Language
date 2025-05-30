// Arrays   
#include<iostream>
#include<string>
using namespace std;
/**
 *    Sort(T *a,int size){// value of an has
    for(int i =0; i<size; i++){
       v[i] = a[i];
    }
   }
 */
// using Tamplet of class
template<class T>
class Sort{
   T *v;
 public:
   Sort(int size){ v = new T[size];
        for(int i = 0;i <size; i++){
            v[i] = 0; 
        }
   }

    ~Sort() {
        delete[] v;  // ✅ Frees allocated memory
    }
// input
 void input(int size);
  void bubbleSort(int size);
  void insertionSort(int size);
  void selectionSort(int size);
  int binarySearch(int size,T key);
  void display(int size);
};
template<typename T>
void Sort<T> :: input(int size){
    cout<<"Enter "<<size<<" elements in an array. "<<endl;
   for(int i = 0; i<size; i++){
     cin>>this->v[i];
   }
}
template<class T>
void Sort<T> :: bubbleSort(int size){
   // sorting using bubble concept
   for(int i = 0; i<size-1; i++){
     for(int j = i+1; j<size; j++){
      if(this->v[i]>this->v[j]){
        // swapping     
       T temp = this->v[i];
       this->v[i] = this->v[j];
       this->v[j] = temp;
       }
     }
   }
}
template<class T>
void Sort<T> :: insertionSort(int size){
   // sorting using insertion concept
   for(int i = 1; i<size; i++){
      int pre = i-1; 
      T curr = this->v[i];
    while(pre>=0 && v[pre]>curr){
        // swapping 
       T temp = this->v[pre+1];
       this->v[pre+1] = this->v[pre];
       this->v[pre] = temp;
       pre--;
     }
   }
}
template<class T>
void Sort<T> :: selectionSort(int size){
   // sorting using bubble concept
   for(int i = 0; i<size-1; i++){
       int minIdx = i;
     for(int j = i+1; j<size; j++){
         if(this->v[minIdx]>this->v[j]){
            minIdx = j;
         }
     }
        // swapping 
       T temp = this->v[i];
       this->v[i] = this->v[minIdx];
       this->v[minIdx] = temp;
   }
}
template<typename T>
int Sort<T> :: binarySearch(int size, T key){
  int st = 0, et = size-1; 

  while(st<=et){
    int mid = st + (et-st)/2;
    if(this->v[mid] == key) return mid;
    else if(this->v[mid] < key){
         st = mid+1;
    }else{
        et = mid-1;
    }
  }
  return -1;
}

template<class T>
void Sort<T> :: display(int size){
   cout<<"The value of array elements after sorting are : "<<endl;
   for(int i = 0; i<size; i++){
      cout<<this->v[i]<<" ";
   }
   cout<<endl;
}

int main(){
   int ch,n;
   cout<<"Enter the size of an array : "; cin>>n;
   Sort<int> s1(n);
   s1.input(n);
   cout<<"Press-1 : sorting by bubble \nPress-2 : sorting by insertion \nPress-3 : sorting by selection \nPress-4 : binary Search\nPress-5 : to display "<<endl;
   while(1){
     cout<<"Enter the choice of action : "; cin>>ch;
     switch(ch){
        case 1: 
            s1.bubbleSort(n);
            break;
        case 2: 
            s1.insertionSort(n);
            break;
        case 3: 
            s1.selectionSort(n);
            break;
        case 4:{
          int key;
          cout<<"Enter the key : "; cin>> key;
          int idx = s1.binarySearch(n,key);
          if(idx != -1){
          cout<<key<<" is present at position no. : "<<idx<<endl;
          }else{
            cout<<key<<" is absent in the array."<<endl;
          }
         }
           break;
        case 5: 
            s1.display(n);
            break;    
      default : 
           cout<<"Invalid option selected . Select a valid one next time"<<endl;
           return 0;
     }
   }
}