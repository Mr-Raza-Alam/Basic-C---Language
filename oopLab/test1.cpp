//Exception Handling
#include<iostream>
#include<string>
using namespace std;

class Cal{

  public :
   double n1;
  Cal():n1(0.0){}
  Cal(int i):n1(i){}// more effective
  Cal operator+(Cal obj);
  Cal operator-(Cal obj);
  Cal operator*(Cal obj);
  Cal operator/(Cal obj);
  void operator++(int);
  void showResult();
};
void Cal:: showResult(){
    cout<<"Your result after respective operation : "<<this->n1<<endl;
}

Cal Cal::operator+(Cal obj)
{ 
    if(obj.n1 <0){
        throw ("-ve value is not accepted for addition.");
    }else{
    return Cal(this->n1 + obj.n1);
    }
}
Cal Cal::operator-(Cal obj)
{
  if(this->n1<obj.n1){
    Cal temp = (this->n1 - obj.n1);
    throw (temp);
    return temp;
  }else{// +ve result
    return Cal(this->n1 - obj.n1);
  }
}
Cal Cal::operator*(Cal obj)
{
if(obj.n1 == 0){
        throw ("Always the result is Zero");
    }else{
     return Cal(this->n1 * obj.n1);
    }    
}
Cal Cal::operator/(Cal obj)
{
if(obj.n1 == 0){
        throw ("Oops.! Division of "+to_string(this->n1)+" and "+to_string(obj.n1)+"is aborted");
    }else{
    return Cal(this->n1 / obj.n1);
    }
}
void Cal::operator++(int)
{
    n1 = (int)n1;
    n1 +=2;
}

int main(){
   try{
   int ch;
   double n1,n2;
   cout<<"Enter 1st number : "; cin>>n1;
   cout<<"Enter 2nd number : "; cin>>n2;
   Cal t1(n1),t2(n2),t;
   cout<<"Press-1 : to add\nPress-2 : to subtract\nPress-3 : to multiply\nPress-4 : to divide\nPress-5 : to increment\n"<<endl;
    while(true){
      cout<<"Enter the choice of action : "; cin>>ch;
      switch(ch){
        case 1: t = t1+t2; t.showResult(); break;
        case 2: t = t1-t2; t.showResult(); break;
        case 3: t = t1*t2; t.showResult(); break;
        case 4: t = t1/t2; t.showResult(); break;
        case 5: t2++; t2.showResult(); t1++; t1.showResult(); break;
        default : cout<<"Oops wrong option.Try again"; return 0;
      }
    }
    //throw;// rethrowing
   }catch(const char *msg){
      cout<<msg<<endl;
   }catch(Cal err){
    cout<<"Subtraction result is -ve. and i.e "<<err.n1<<endl;
   }
}
//try{
//  int x;
//  cout<<"Enter a number : ";
//  cin>>x;
// // testError(x);
// }catch(char c){
//     cout<<"Cought a Charater Error";
// }catch(int t){
//     cout<<"Cought a Integer Error";
// }catch(double p){
//     cout<<"Cought a Floating-point Error";
// }

// void testError(int x) throw(int,double){
//     if(x>1){
//         throw x;
//     }else if(x == 1){
//         throw 'x';
//     }else{
//         throw (double)x;
//     }
// }
