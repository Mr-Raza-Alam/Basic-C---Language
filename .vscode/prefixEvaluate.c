#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
 
 int top = -1;
 typedef struct node{
    int item;
    struct node* next;
}node;
  node* temp,*first,*last,*run;
 void create(int x){ 
  temp = (struct node*) malloc(sizeof(node));
  temp->item =  x ;
  temp->next = NULL;
  top++;
  first = temp;
  run = first;
  printf("%d is store at top = %d\n",run->item,top);
   return;
  }

int evaluate();
void push();
int pop();
void create();
int express();

void main(){
  char str[10];
  printf("Enter the prefix expression :- ");
  scanf("%s",str);
   int length_str = strlen(str);
   printf("The length = %d\n",length_str);
   printf("str[%d] = %c\n",length_str,str[length_str-1]);
   printf("The result of prefix expression = %d\n",evaluate(length_str,str));

}

int evaluate(int k,char ctr[k]){
    int opr1,opr2,res,p;
   for(int i = k-1; i>=0; i--){
    char*ptr = &ctr[i];
     if(ctr[i] == '*' || ctr[i] == '/' || ctr[i] == '%' || ctr[i] == '+' || ctr[i] == '-'){
      opr2 = pop();
      printf("opreand-2 = %d\n",opr2);
      opr1 = pop();
      printf("opreand-1 = %d\n",opr1);
      res = express(opr2,opr1,ptr);
      push(res);
     }
    else{
        p = ctr[i] - '0';
      printf("Character = %d\n",p);
         push(p);
    }
   }
   printf("The res = %d\n",res);
   return res;
}

int express(int t2,int t1,char*ntr){
   int p;
    if(*ntr == '*'){
      p = (t1*t2);
      printf("P = %d\n",p);
      return p;      
    }
    else if(*ntr == '/'){
      p = (t2/t1);
      printf("P = %d\n",p);
      return p;
    }    
    else if(*ntr == '%'){
      p = (t2%t1);
      printf("P = %d\n",p);
      return p;
    }
    else if(*ntr == '+'){
      p = (t1+t2);
      printf("P = %d\n",p);
      return p;
    }
    else if(*ntr == '-'){
      p = (t2-t1);
      printf("P = %d\n",p);
      return p;
    }
   else {
      printf("Invalid operator");
      return 0;
   }
}
 

     
 void push(int newitem){
    temp = (node*) malloc(sizeof(node)); 
    temp->item = newitem;
    temp->next = first;
    top++;
    first = temp;
    printf("%d is store at top = %d\n",first->item,top);
 }

 int pop(){
     int ans;
  if(top == -1) printf("Stack-Underflow!.....\n"); 
    temp = first;
    ans = temp->item;
   printf("%d is delete from top = %d\n",ans,top);
    top--;
   first = first->next;
   free(temp);
   return ans;
 }

 
// void isDigits(char* ptr,int t){
//     for(int i = 0; i<t; i++){
//     if(isdigit(((int)*ptr))!= 0){
//         printf("%c",*ptr);
//      }
//      ptr++;
//    }
// }