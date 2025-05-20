#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 15
int top = -1;
char stack[MAX];

void push(char ch){
  if(top == MAX -1){
   printf("Stack Overflow\n");
   return;
  }
   stack[++top] = ch;
}

char pop(){
   if(top == -1){
      printf("Stack-Underflow\n");
      return '?';
   }
   return stack[top--];
}
char peek(){
  if(top == -1){
     printf("Stack-Underflow\n");
      return '?';
   }
   return stack[top];
}

int precedence(char ch){
   if(ch == '^'){
      return 1;
   }
   else if(ch == '+' || ch == '-'){
      return 2;
   }
   else if(ch == '*' || ch == '/' || ch == '%'){
      return 3;
   } else{
      return 0;
   }
}

int isOperand(char ch){
   return isalpha(ch) || isdigit(ch);
}

void infixTOPrefix(char* infix,char* prefix,char* res){
   int i = 0,j = 0;
   char ch,topChar;
   while((ch = infix[i++]) !='\0'){
      if(isOperand(ch)){
         push(ch);
      }
      else if(ch == '('){
         push(ch);
      }
      else if(ch == ')'){
         // pop untill '(' is encounter
      while(top != -1 && stack[top] !='('){
        prefix[j++] = pop();
        }
      pop();// to pop '(' 
      }
    else{
      // pop operator from stack with higher or equal precedence
      while(top != -1 && precedence(stack[top]) >= precedence(ch) ){
          prefix[j++] = ch;
      }
      push(ch);
    }
   }
   // in case stack is still have some elem
   while(top != -1){
      prefix[j++] = pop();
   }
   prefix[j] = '\0';
   int n = j;
   j = 0;
 for(int i = n -1; i>=0; i--){
   res[j] = prefix[i];
   j++;
  }
}

void main(){
   char prefix[MAX],infix[MAX], res[MAX];
  printf("Enter the infix expression :- ");
  fgets(infix,sizeof(infix),stdin);
  for(int i = sizeof(infix) -1; i>=0; i--){
   if(infix[i] == '('){
     prefix[i] = ')';
   } else if(infix[i] == ')'){
      prefix[i] = '(';
   } else{
      prefix[i] = infix[i];
   }
  }
  infixTOPrefix(infix,prefix,res);
  printf("The resultant prefix expression :- %s\n",res);
   
}