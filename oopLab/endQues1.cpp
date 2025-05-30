// find your age
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Date{
 int bDay,cDay,bYear,cYear ,bMon,cMon;
 string Month[12] = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec"};
//                                       0, 1,  2,  3,  4,  5,  6,   7, 8,  9,    10,    11
 public:
  Date(int bd,int cd,int by,int cy, int bm,int cm){
      this->bDay = bd;
      this->cDay = cd;
      this->bYear = by;
      this->cYear = cy;
      this->bMon = bm;
      this->cMon = cm;
  }

  ~Date(){
      this->bDay = 0;
      this->cDay = 0;
      this->bYear = 0;
      this->cYear = 0;
      this->bMon = 0;
      this->cMon = 0; 
  }

   int findDay();
   string findMonth();
   int findYear();
};

int Date :: findDay(){
  int temp;
  temp = this->cDay - this->bDay;
  // month having 31days are : 1,3,5,7,8,10,12
  if(temp>0){
    return temp;
  }else{
    if(cMon == 1 || cMon == 3 ||cMon == 5 ||cMon == 7 ||cMon == 8 ||cMon == 10 ||cMon == 12){
         this->cDay += 31;
         this->cMon -=1;
    }else if(cMon == 2){
       this->cDay += 28;
         this->cMon -=1;
    }else{
       this->cDay += 30;
       this->cMon -=1;
    }
  temp = this->cDay - this->bDay;
  return temp;
  }
}

string Date :: findMonth(){
    int temp; 
    temp = this->cMon - this->bMon;
    if(temp>0 && temp<13){
        string mon = Month[temp-1];
        return mon;
    }else{
       this->cMon +=12;
       this->cYear -=1;
      temp = this->cMon - this->bMon;
      string mon = Month[temp-1];
      return mon;
    }
}

int Date :: findYear(){
   return (this->cYear - this->bYear);
}

int main(){
  int cd,bd,cm,bm,cy,by;
  cout<<"Enter your birth date : "; cin>>bd>>bm>>by;
  cout<<"Enter your current date : "; cin>>cd>>cm>>cy;
  Date d1(bd,cd,by,cy,bm,cm);
  
  int day = d1.findDay();
  string mon = d1.findMonth();
  int year = d1.findYear();
 cout<<"Your age is given : "<<endl;
 cout<<"Day : "<<day<<endl;
 cout<<"Month : "<<mon<<endl;
 cout<<"Year : "<<year<<endl;
    return 0;
}

