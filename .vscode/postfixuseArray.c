#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define size  5
int stack[size];
int top = -1;

int evaluate(char*ctr,int k);
int express(char*ntr,int t1,int t2);
void push(int n);
int pop();

void main(){
  char str[10];
  printf("Enter your postfix expression :- ");
  scanf("%s",str);
  printf("The given postfix expresion is given below:\n%s",str);
   int length = strlen(str);
   printf("\nThe length = %d\n",length);
   //printf("The available digits in the given expression are:\n");
   //isDigits(str,length_str);
   int a = evaluate(str,length);
   printf("The result of postfix expression = %d\n",a);
 
}

int evaluate(char*ctr,int k){
    int opr1,opr2;
    int res,p;
    for(int i = 0; i<k; i++){
      if((*ctr) == '+'||(*ctr) == '-'||(*ctr) == '*'||(*ctr) == '/'||(*ctr) == '%'){
      opr2 = pop();
      opr1 = pop();
      res = express(ctr,opr2,opr1);
      push(res);
      ctr++;
      }
     else{
      printf("%dth chararcter = %c\n",i,*ctr);
      p = *ctr - '0';
        push(p);
        ctr++;
       }

    }
   return res;
}

int express(char*ntr,int t1,int t2){
    
    if(*ntr == '*'){
      printf("t2*t1 = %d\n",(t1*t2));
      return (t1*t2);
    }
    else if(*ntr == '/'){
      printf("t2/t1 = %d\n",(t1/t2));
      return (t2/t1);
    }    
    else if(*ntr == '%'){
      printf("remainder = %d\n",(t1%t2));
      return (t2%t1);
    }
    else if(*ntr == '+'){
      printf("t2+t1 = %d\n",(t1+t2));
      return (t1+t2);
    }
    else if(*ntr == '-'){
      printf("t2-t1 = %d\n",(t1-t2));
      return (t2-t1);
    }
   else {
      printf("Invalid operator");
      return 0;
   }
}

void push(int n){//Stack ---> push implementation using array
        top++;
     if(top == size-1){
         printf("The stack-Ovaerflow\n");
        return;
    }
    else{
        printf("stack[%d] = %d\n",top,n);
        stack[top] = n;

    }
}
int pop(){//using array
     int x;
    if(top == (-1) ){
        printf("The stack is empty! please insert any value\n");
    }
    else{
       x = stack[top];
       printf("stack[%d] = %d has been deleted\n",top,x);
       top--;
       return x;
    }
}
     
