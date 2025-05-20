#include<stdio.h>
#include<string.h>

void main (){
    char str[10];
    printf("Enter the postfix expression = ");
    scanf("%s",str);
    printf("The length of given string = %d\n",strlen(str));
    char*ptr = str;
    for(int i = 0; i<strlen(str); i++){
           switch(*ptr){
              case 1:
           }
           printf("%d ",(*ptr));
       ptr++;
    }
}