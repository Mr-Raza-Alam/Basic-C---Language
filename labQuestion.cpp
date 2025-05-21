// prime factor of any number
 
#include<iostream>
#include<string>
using namespace std;

class Vowel{
 public:
  int n = 0;
  char ch;
  // Vowel(int idx , char c){
  //   this->n = idx;
  //   this->ch = c;
  // }
};

void countVowels(string word);
void swappNum(double *num1,double *num2);
bool isPrime(int* k);


 bool isPrime(int* k){
    int num = *(k);
   for(int i = 2;i<=num/2; i++){
    if(num%i==0){
        return false;
    }
   }
   return true;
 }

 void swappNum(double *num1,double *num2){
    double temp = *(num1);
        *(num1) = *(num2);
         *(num2) = temp;
 }

int main(){
    int n;
    double x,y;
    string word;
    //getline(cin,word);//  syntax of sentence userdefined is getline(cin,variable);
    cout<<"Enter a sentence : ";
    cin>>word;
    countVowels(word);
    cout<<"\nEnter a number : ";
    cin>>n;
   if(isPrime(&n)){
    cout<<"Yes, "<<n<<" is a Prime number."<<endl;
   }else{
    cout<<n<<" is non Prime number."<<endl;
   }
    cout<<"\nEnter 1st number : ";
    cin>>x;
    cout<<"\nEnter 2nd number : ";
    cin>>y;
   swappNum(&x,&y);
   cout<<"After Swapping numbers are : "<<endl;
   cout<<"X : "<<x<<endl;
   cout<<"Y : "<<y<<endl;
  //   cout<<"Prime factor of "<<n<<" are : \n";
  // for(int i = 2; i<n; i++){
  //    if(isPrime(i) == true){
  //      if(n%i == 0){
  //       cout<<i<<" ";
  //      }
  //    }
  // }
    // call countVowels(word);

  return 0;
}

//  program to check no. of vowels present in the given string by user
void countVowels(string word){
  int count = 0;
  //int vowels[5];
  Vowel arr[5];
  // initialize vowels[] with zero
  for(int i = 0; i<5; i++){
   // vowels[i] = 0;
    if(i == 0){
      arr[i].ch = 'a';
    }else  if(i == 1){
      arr[i].ch = 'e';
    }else  if(i == 2){
      arr[i].ch = 'i';
    }else  if(i == 3){
      arr[i].ch = 'o';
    }else  if(i == 4){
      arr[i].ch = 'u';
    }
  }

  for(char letter : word){// using forEach loop
     if(letter == 'a' ||letter == 'A'){
        // vowels[0]---vowel a
        arr[0].n++;
        count++;
     }else if(letter == 'e' ||letter == 'E'){
        // vowels[1]---vowel e
        arr[1].n++;
        count++;
     }else if(letter == 'i' ||letter == 'I'){
        // vowels[2]---vowel i
        arr[2].n++;
        count++;
     }else if(letter == 'o' ||letter == 'O'){
        // vowels[3]---vowel o
        arr[3].n++;
        count++;
     }else if(letter == 'u' ||letter == 'U'){
        // vowels[4]---vowel u
        arr[4].n++;
        arr[4].ch = letter;
        count++;
     }      
  }
// now print no. of vowels
cout<<"Total no. of vowels are present in the word "<<word<<" : "<<count<<endl;
cout<<"No.of each vowels present are in the word "<<word<<" are : \n"<<endl; 
for(Vowel v : arr){
    cout<<"vowel "<<v.ch<<" = "<<v.n<<endl; 
  }

}
