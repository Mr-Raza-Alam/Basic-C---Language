#include<iostream>
#include<string>
using namespace std;

class book{
 public :
  string author,title,publisher;
  double price;
  int stock_pos; 
  // create a constructor , i.e used to initialize purpose
  book(string a,string tit,string pub,double pri,int sp){
      this->author = a;
      this->title = tit;
      this->publisher = pub;
      this->price = pri;
      this->stock_pos = sp;
  }
  void getBookInfo();
};

void book :: getBookInfo(){
 cout<< "\nAuthor : " << author << "\nTitle : " <<title<<"\nPublisher : " << publisher << "\nPrice : " <<price << "\nStock-Position : " << stock_pos <<endl;
}

void customer(book list[]){

  string auth,tit;

  cout<<"\nEnter book's author : ";
  cin>>auth;
  cout<<"Enter book's title : ";
  cin>>tit;
  // now apply search for find the request book for customer
  int n ,i = 0;

 while(i<5){
   if(list[i].author == auth && list[i].title == tit){
     cout<<"\nYes,your request book is avialable\nDescription of book :- \n";
      list[i].getBookInfo();
      cout<<"Enter the no. of copies required = ";
      cin>>n;
     // now check no. of requested copies are avialable or not
     if(list[i].stock_pos >= n){
       cout<<"Total cost of the requested no. of copies = "<<(list[i].price*n)<<endl;
     } else{
        cout<<"Sorry!insufficient stock\nVisit agian after 2 days"<<endl;
     }
     return;
    }else{
        i++;
    } 
 }
  cout<<"Request copies is unavialable in the stock"<<endl;   
}

int main(){
 // create a book store
 book list[] = {book("David-Hayward","heads-you-lose","Pan Books",103.45,5),book("C.J.Sansom" ,"winter-in-mandrid", "Pan Books", 133.45 , 2), book("Khale-Hosseini","the-kite-runner","Pan Books",213.87,3),book("Lisa-Lutz","life-is-elsewhere","Berkley",113.53,8),book("Milan-Kundera","ignorance","Pan Books",167.47,7)};
 //cout<<"The list of book avialable in the stock "<<endl;
 cout<<"  Author        |Title"<<endl;
 for(int i = 0; i<5; i++){
    cout<<list[i].author<<"--->"<<list[i].title<<endl;
 }
 cout<<"\nPress-1 : to buy a book"<<endl;
 int c;
 while(1){
  cout<<"\nEnter an option : ";
  cin>>c;
  if(c == 1){
  customer(list);
  } else{
    cout<<"Sorry! You enter a wrong option\nTry again"<<endl;
    break;
  }
 }
}