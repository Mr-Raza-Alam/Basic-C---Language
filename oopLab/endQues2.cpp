// Error Exceptional handling
#include<iostream>
#include<string>
using namespace std;

void vowelString(){
  string str;
  cout<<"Enter your string : "; cin>>str;
  // now extract each character of the string and check vowel 
  int isVowel = 0; 
  for(char ch : str){
   if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u'){
       isVowel = 1; 
       break;
   }else{
    isVowel = 0; 
   }
  }

  // check 
  if(isVowel == 0){
    throw ("String Error . Given string does not contain vowel");
  }else{
    cout<<"Yes. string contain vowel"<<endl; 
  }

}

int main(){
 try
 {
   vowelString(); 
 }
 catch(const char *err)
 {
   cout<<err<<endl;
}
 
    return 0;
}
