// Design a database that can provide the functionality of display,insert new ,update exiting,delete desire exiting data
#include<iostream>
#include<string>
#include<map>
using namespace std;
// rename the map
typedef map<int,string> studentDB;
void createDB(studentDB &student);
void insertNewData(studentDB &is);
void modify(studentDB &ms);
void deleteData(studentDB &ds);
void showData(studentDB &s);


int main(){
  studentDB student;// declare a student map
 cout<<"Press-0: to create a database\nPress-1: to insert new data to the database\nPress-2: to update data\nPress-3: to delete the data\nPress-4: to display the data of database\n"<<endl;
 int opt;
 while(1){
    cout<<"\nEnter a choice of action : ";
    cin>>opt;
   switch(opt){
    case 0: createDB(student); break;
    case 1: insertNewData(student); break;
    case 2: modify(student); break;
    case 3: deleteData(student); break;    
    case 4: showData(student); break;
    default:
        cout<<"Ohh No!! You entered a wrong option :"<<endl;
        return 0;
    }  
 }

    return 0; 
}
void createDB(studentDB &student){
  int roll;
  string studName;
  cout<<"Insert Student details to create the database"<<endl;
  cout<<"Roll No. : ";
  cin>>roll;
  cin.ignore();// clear the newline
  cout<<"Student Name  : ";
  getline(cin,studName);
  student[roll] = studName;
}


void insertNewData(studentDB &is){
    if(is.size()    != 0){
    cout<<"\nAdd new Student details to the database"<<endl;
   int newRoll;
   string newName;
   cout<<"New Roll No. : ";
  cin>>newRoll;
  cin.ignore();// clear the newline
  cout<<"New Student Name  : ";
  getline(cin,newName);
  is[newRoll] = newName;
  }else{
   cout<<"Can't insert.First create your data base"<<endl;
   return;
  }
}

// modify the exiting details of student
void modify(studentDB &ms){
   int roll;
   string name;
  cout<<"\nEnter the roll number   : ";
  cin>>roll;
  cin.ignore();// clear the newline
 auto detail = ms.find(roll);
 if(detail != ms.end()){
  cout<<"Enter the modifying details  : ";
  getline(cin,name);
  ms[roll] = name;
 }else{
    cout<<"Oops!Invalid roll number"<<endl;
 }
}

// delete the data
void deleteData(studentDB &ds){
  int roll;
  char con;
  cout<<"\nEnter the deleting roll no. : ";
  cin>>roll;
 auto detail = ds.find(roll);
  if(detail != ds.end()){
  // safe that means we have access to delete 
  cout<<"Do you really want to delete ?? if yes(y) otherwise press(n) : ";
  cin>>con;
   if(con == 'y'){
     ds.erase(roll);
   }
  }else{
    cout<<"Oops!Invalid roll number"<<endl;
 }
}

// display data from created data base;
void showData(studentDB &s){
   cout<<"Data of student database are : \n"<<endl;
   cout<<"\nRoll No.        Student Name"<<endl;
   for(auto &p : s){
    cout<<p.first<<"   :     "<<p.second<<endl;
   }
}