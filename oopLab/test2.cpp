// file handling
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void fileHandling(){
string country,capital;
    ofstream fout1,fout2;
  fout1.open("Country.txt");
    fout1<<"United State of America"<<endl;
    fout1<<"India"<<endl;
    fout1<<"United Kingdom"<<endl;
    fout1<<"South Africa"<<endl;
    fout1<<"Pakistan"<<endl;
  fout1.close();
  fout2.open("Capital.txt");
    fout2 << "Washington D.C." << endl;
    fout2 << "New Delhi" << endl;
    fout2 << "London" << endl;
    fout2 << "Pretoria" << endl;
    fout2 << "Islamabad" << endl;
  fout2.close();
 // now open the exiting file to read data from them and manipulate on it 
 ifstream fin1,fin2;
  fin1.open("Country.txt");
  fin2.open("Capital.txt");
  cout<<"The content from 2 files are given below : "<<endl;
  while(getline(fin1,country) && getline(fin2,capital)){
     cout<<"Capital of "<<left<<setw(30)<<country<<capital<<endl;
  }
  fin1.close();
  fin2.close();
}
int main(){
  fileHandling();
    return 0 ;
}

// open a file to write something to it
//    ofstream fout,fout1,fout2;
//    fout.open("sampleTest.c");
//     fout<<"#include<stdio.h>"<<endl;
//     fout<<"void main(){"<<endl;
//     fout<<"int a,b,c;"<<endl;
//     fout<<"printf(\"Enter a : \");scanf(\" %d \",&a);"<<endl;
//     fout<<"printf(\"Enter b : \"); scanf(\"%d\",&b);"<<endl;
//     fout<<"c = a + b;"<<endl;
//     fout<<"printf(\"The sum of %d + %d : %d\",a,b,c)"<<endl;
//     fout<<"}"<<endl;
//   fout.close();