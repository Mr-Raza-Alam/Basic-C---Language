#include<iostream>
#include<string>
using namespace std;

class Calender{
   int day,mon,year;
   public:
  Calender(){// default constructor
    day = 0;
    mon = 0;
    year = 0;
  }
 Calender(int d,int m,int y){// Parametrise constructor
    this->day = d;
    this->mon = m;
    this->year = y;
 }

 // operator++ overlaoding fun.
 Calender operator++(){
  // case-1: if year is leap-year
  if(year%4 == 0){
    // cout<<"Guys, you'r in the leap year! i hope you enjoy it"<<endl;
    if(mon>0 && mon < 13){
   // case-1.1
   if(mon == 02){// feb. month
    if(day < 29){
       day++;
     cout<<day<<"/"<<mon<<"/"<<year<<endl;
    }else{
        mon++;
        day = 01;
     cout<<day<<"/"<<mon<<"/"<<year<<endl;
    }
   }else if(mon == 4 || mon == 6 || mon == 9 || mon == 11){//case-1.2 month of 30 days
     if(day>0 && day<30){
        day++;
      cout<<day<<"/"<<mon<<"/"<<year<<endl;
     }else if(day == 30){
        mon++;
        day = 01;
      cout<<day<<"/"<<mon<<"/"<<year<<endl;
     }else{
      cout<<"day : "<<day<<" is out of range.please enter a valid one."<<endl;
     }
   }else{// case-1.3 month of 31 days
     if(this->day == 31 && this->mon == 12){
        day = 01;
        mon = 01;
       year++;
       cout<<day<<"/"<<mon<<"/"<<year<<endl;
     }
    else if(day<31){
        day++;
    cout<<day<<"/"<<mon<<"/"<<year<<endl;
    }else if(day == 31){
        mon++;
        day = 01;
      cout<<day<<"/"<<mon<<"/"<<year<<endl;
       }else{
        cout<<"day : "<<day<<" is out of range.please enter a valid one."<<endl;
       }
     }
  }else{
    cout<<"Invalid month.Try again"<<endl;
  }
  }else{//case-2 if year is non-year
    // cout<<"Guys, you'r in the non-leap year! i hope you enjoy it"<<endl;
  if(mon >0 && mon<13){
   // case-2.1
   if(mon == 02){// feb. month
    if(day<28){
       day++;
     cout<<day<<"/"<<mon<<"/"<<year<<endl; 
    }else if(day == 28){
        mon++;
        day = 01;
     cout<<day<<"/"<<mon<<"/"<<year<<endl;
    }else{
      cout<<"Invalid day"<<endl;
    }
   }else if(mon == 4 || mon == 6 || mon == 9 || mon == 11){//case-2.2 month of 30 days
    if(day>0 && day<30){
        day++;
     cout<<day<<"/"<<mon<<"/"<<year<<endl;
    }else if(day == 30){
        mon++;
        day = 01;
      cout<<day<<"/"<<mon<<"/"<<year<<endl;
     }else{
      cout<<"day : "<<day<<" is out of range.please enter a valid one."<<endl;
     }
  }else{// case-2.3 month of 31 days
     if(this->day == 31 && this->mon == 12){
        day = 01;
        mon = 01;
       year++;
       cout<<day<<"/"<<mon<<"/"<<year<<endl;
      }
   else if(day<31){
     day++;
    cout<<day<<"/"<<mon<<"/"<<year<<endl;
    }else if(day == 31){
        mon++;
        day = 01;
      cout<<day<<"/"<<mon<<"/"<<year<<endl;
      }else{
        cout<<"day : "<<day<<" is out of range.please enter a valid one."<<endl;
       }     
    }
   }else{
    cout<<this->mon<<" is an invalid month.Try again"<<endl;
    }
  }
 }

 void showDate(){
    if(mon>0 && mon<13){
       if(day >0 && day<32){
        cout<<day<<"/"<<mon<<"/"<<year<<endl;
       }else{
        cout<<"day : "<<day<<" is out of range.please enter a valid one."<<endl;
       }
    }else{
     cout<<this->mon<<" is an invalid month.Try again"<<endl;
    }
 }

};

void dateUpgrade(){
  int dd,mm,yyyy;
  cout<<"Enter a date.(e.g 12 04 2001) : ";
  cin>>dd>>mm>>yyyy;
 Calender c1(dd,mm,yyyy);
 cout<<"Your date , before increment "<<endl;
  c1.showDate();
  cout<<"Your date , after increment "<<endl;
  ++c1;// pre-increment
//  c1++;// post-increment (int) required must
// //  c1.showDate();
}


int main(){
  string Month[] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; 
  cout<<"Month( code )"<<endl;
  for(int i = 0; i<12; i++){
    cout<<Month[i]<<"( "<<(i+1)<<" )"<<endl;
  }
  cout<<"\nPress-1 : to increment your date."<<endl;
  int ch;
  while(1){
    cout<<"\nEnter an option : ";
    cin>>ch;
    if(ch == 1){
      dateUpgrade();
    }else{
      cout<<"Sorry! you entered a wrong option.please try again."<<endl;
      break;
    }
  }
  return 0; 
}