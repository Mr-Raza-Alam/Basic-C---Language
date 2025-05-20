  #include<iostream>
  #include<string>
  using namespace std;
  // full string taken by using a function called......getline(cin,string identifier);
  class sort{
   private :
    double arr[10];
   public:
    sort(){
        for(int i = 0; i<10; i++){
            arr[i] = 0.0;
        }
    }
   sort(double brr[10]){
     for(int i = 0; i<10; i++){
        arr[i] = brr[i];
     }
   }
   void insertionSort();
   void bubbleSort();
   void selctionSort();
  };

  void sort :: insertionSort(){
    for(int i = 1; i<9; i++){
        int pre = i-1;
        int curr = this->arr[i];
        while(pre>0 && arr[pre]>curr){
          // swapp
          double temp = arr[pre+1];
            arr[pre+1] = arr[i];
            arr[i] = temp;
            pre--;
        }
    }
    cout<<"After insertion sort "<<endl;
    for(int i = 0; i<10; i++){
      cout<<arr[i]<<"   ";
    }
    cout<<endl;
  }
  void sort :: bubbleSort(){
    for(int i = 0; i<9; i++){
      for(int j = i+1; j<10; j++){
        // swapp  
       if(arr[i]>arr[j]){
        double temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
       }
        // arr[i] = arr[i]^arr[j];
        // arr[j] = arr[i]^arr[j];
        // arr[i] = arr[i]^arr[j];
      }
    }
  cout<<"After bubble sort "<<endl;
  for(int i = 0; i<10; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
   void sort :: selctionSort(){
     for(int i = 0; i<9; i++){
        int minIdx  = i;
      for(int j = i+1; j<10; j++){
         if(arr[i]>arr[j]){
            minIdx = j;
         }
       }
            // swapp
            double temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        // arr[i] = arr[i]^arr[minIdx];
        // arr[minIdx] = arr[i]^arr[minIdx];
        // arr[i] = arr[i]^arr[minIdx];
     }


    cout<<"After selection sort "<<endl;
    for(int i = 0; i<10; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
   }

  int main(){
   double urr[10];
   cout<<"Enter your values to store in the container of size 10"<<endl;
   for(int i = 0; i<10; i++){
    cin>>urr[i];
   }
   sort s1(urr);
   s1.bubbleSort();
   s1.insertionSort();
   s1.selctionSort();
    // string str;
    // cout<<"Enter your string : ";
    // getline(cin,str);
    // cout<<"your given : "<<str<<endl;
    return 0;
  }